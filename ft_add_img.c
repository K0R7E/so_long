/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akortvel <akortvel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:20:25 by akortvel          #+#    #+#             */
/*   Updated: 2023/11/08 13:54:03 by akortvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_add_mlx(t_list *list)
{
	list->mlx_ptr = mlx_init();
	if (list->mlx_ptr == NULL)
	{
		free(list->mlx_ptr);
		ft_error_exit("Error while initializing Minilibx! Not found!", list);
	}
	list->window_ptr = mlx_new_window(list->mlx_ptr,
			list->map.cols * 50, list->map.rows * 50, "so_long");
	if (list->window_ptr == NULL)
	{
		free(list->mlx_ptr);
		ft_error_exit("Unable to create the window!", list);
	}
}

t_image	ft_add_new_img(void *mlx, char *path, t_list *list)
{
	t_image	new;

	new.x = 50;
	new.y = 50;
	new.ptr = NULL;
	new.ptr = mlx_xpm_file_to_image(mlx, path, &new.x, &new.y);
	if (!new.ptr)
		ft_error_exit("No img found!", list);
	return (new);
}

void	ft_add_img(t_list *list)
{
	list->wall = ft_add_new_img(list->mlx_ptr, "wall.xpm", list);
	list->floor = ft_add_new_img(list->mlx_ptr, "floor.xpm", list);
	list->coins = ft_add_new_img(list->mlx_ptr, "coin.xpm", list);
	list->player = ft_add_new_img(list->mlx_ptr, "character.xpm", list);
	list->exit = ft_add_new_img(list->mlx_ptr, "exit.xpm", list);
}
