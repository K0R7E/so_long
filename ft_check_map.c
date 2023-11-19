/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akortvel <akortvel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:22:49 by akortvel          #+#    #+#             */
/*   Updated: 2023/11/08 13:36:41 by akortvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_wallcheck(t_list *list)
{
	int	i;
	int	n;

	i = 0;
	while (i < list->map.rows)
	{
		if (list->map.full[i][0] != '1')
			ft_error_exit(YELLOW"The frame must be a wall!"COLOR_OFF, list);
		else if (list->map.full[i][list->map.cols -1] != '1')
			ft_error_exit(YELLOW"The frame must be a wall!"COLOR_OFF, list);
		i++;
	}
	n = 0;
	while (n < list->map.cols)
	{
		if (list->map.full[0][n] != '1')
			ft_error_exit(YELLOW"The frame must be a wall!"COLOR_OFF, list);
		else if (list->map.full[list->map.rows -1][n] != '1')
			ft_error_exit(YELLOW"The frame must be a wall!"COLOR_OFF, list);
		n++;
	}
}

void	ft_correct_map(t_list *list)
{
	int	x;
	int	y;

	y = 0;
	while (y < list->map.rows)
	{
		x = 0;
		while (x < list->map.cols)
		{
			if (!ft_strchr("10PCE", list->map.full[y][x]))
				ft_error_exit("No wall, floor, player, coin or exit!", list);
			else if (list->map.full[y][x] == 'P')
			{
				list->map.player += 1;
				list->map.position_y = y;
				list->map.position_x = x;
			}
			else if (list->map.full[y][x] == 'C')
				list->map.coins += 1;
			else if (list->map.full[y][x] == 'E')
				list->map.exit += 1;
			x++;
		}
		y++;
	}
}

void	ft_player_exit_check(t_list *list)
{
	if (list->map.player != 1)
	{
		ft_error_exit(YELLOW"Play only one player"COLOR_OFF, list);
	}
	if (list->map.exit != 1)
	{
		ft_error_exit(YELLOW"You can't use more than one exit"COLOR_OFF, list);
	}
	if (list->map.coins < 1)
	{
		ft_error_exit(YELLOW"No coin on the map!"COLOR_OFF, list);
	}
}
