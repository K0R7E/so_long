/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akortvel <akortvel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:21:43 by akortvel          #+#    #+#             */
/*   Updated: 2023/11/08 14:05:23 by akortvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key(int keysym, t_list *list)
{
	if (keysym == W || keysym == UP_ARROW)
		ft_move(list, list->map.position_y - 1, list->map.position_x);
	if (keysym == S || keysym == DOWN_ARROW)
		ft_move(list, list->map.position_y + 1, list->map.position_x);
	if (keysym == A || keysym == LEFT_ARROW)
		ft_move(list, list->map.position_y, list->map.position_x - 1);
	if (keysym == D || keysym == RIGHT_ARROW)
		ft_move(list, list->map.position_y, list->map.position_x + 1);
	if (keysym == Q || keysym == ESC)
		ft_close(list);
	return (0);
}

void	ft_move(t_list *list, int new_y, int new_x)
{
	int	last_x;
	int	last_y;

	last_x = list->map.position_x;
	last_y = list->map.position_y;
	if (list->map.full[new_y][new_x] == EXIT && list->map.coins == 0)
		ft_win(list);
	else if ((list->map.full[new_y][new_x] == FLOOR)
	|| (list->map.full[new_y][new_x] == COINS))
	{
		list->map.full[last_y][last_x] = FLOOR;
		if (list->map.full[new_y][new_x] == COINS)
			list->map.coins--;
		list->map.position_x = new_x;
		list->map.position_y = new_y;
		list->map.full[new_y][new_x] = PLAYER;
		list->moves++;
		ft_render(list);
	}
	ft_printf(BLUE"\rCurrent moves:"COLOR_OFF "%d", list->moves);
}
