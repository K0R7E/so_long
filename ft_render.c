/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akortvel <akortvel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:20:33 by akortvel          #+#    #+#             */
/*   Updated: 2023/11/08 13:40:03 by akortvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_render(t_list *list)
{
	int	x;
	int	y;

	y = 0;
	while (y < list->map.rows)
	{
		x = 0;
		while (x < list->map.cols)
		{
			ft_render_imgs(list, y, x);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_render_imgs(t_list *list, int y, int x)
{
	char	parameter;

	parameter = list->map.full[y][x];
	if (parameter == '1')
		ft_render_img (list, list->wall, y, x);
	else if (parameter == '0')
		ft_render_img (list, list->floor, y, x);
	else if (parameter == 'C')
		ft_render_img (list, list->coins, y, x);
	else if (parameter == 'E')
		ft_render_img (list, list->exit, y, x);
	else if (parameter == 'P')
		ft_render_img (list, list->player, y, x);
}

void	ft_render_img(t_list *list, t_image new_img, int line, int column)
{
	mlx_put_image_to_window (list->mlx_ptr, list->window_ptr, new_img.ptr,
		column * new_img.x, line * new_img.y);
}
