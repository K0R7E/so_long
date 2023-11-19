/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akortvel <akortvel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:06:14 by akortvel          #+#    #+#             */
/*   Updated: 2023/11/08 13:58:02 by akortvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win(t_list *list)
{
	ft_printf(GREEN"\nYOU WIN"COLOR_OFF);
	ft_close(list);
}

int	ft_close(t_list *list)
{
	ft_printf(YELLOW"\nAll moves: %d\n"COLOR_OFF, list->moves);
	ft_free_all_memory(list);
	ft_printf(YELLOW"GAME CLOSED\n"COLOR_OFF);
	exit (0);
}

void	ft_free_all_memory(t_list *list)
{
	ft_destroy_img(list);
	ft_mapfree(list);
	ft_mapcopyfree(list);
	mlx_destroy_window(list->mlx_ptr, list->window_ptr);
	mlx_destroy_display(list->mlx_ptr);
	free(list->mlx_ptr);
	free(list);
}
