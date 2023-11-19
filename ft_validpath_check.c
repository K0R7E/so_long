/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validpath_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akortvel <akortvel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:21:31 by akortvel          #+#    #+#             */
/*   Updated: 2023/11/08 14:28:34 by akortvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_reachable(char **map, int x, int y, int rows)
{
	if (x < 0 || y < 0 || x >= ft_strlen_so_long(*map) || y >= rows
		|| map[y][x] == 'X' || map[y][x] == '1')
	{
		return (1);
	}
	map[y][x] = 'X';
	is_reachable(map, x - 1, y, rows);
	is_reachable(map, x + 1, y, rows);
	is_reachable(map, x, y - 1, rows);
	is_reachable(map, x, y + 1, rows);
	return (0);
}

void	ft_validpath_check(t_list *list)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	is_reachable(list->mapcopy.full, list->map.position_x, list->map.position_y,
		list->map.rows);
	while (i < list->map.rows)
	{
		j = 0;
		while (j < list->map.cols)
		{
			if (list->mapcopy.full[i][j] != 'X'
				&& list->mapcopy.full[i][j] != '1')
			{
				ft_error_exit(YELLOW"No valid path!"COLOR_OFF, list);
			}
			j++;
		}
		i++;
	}
}
