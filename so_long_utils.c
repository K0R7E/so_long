/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akortvel <akortvel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:20:30 by akortvel          #+#    #+#             */
/*   Updated: 2023/11/08 13:58:35 by akortvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error_exit(char *msg, t_list *list)
{
	if (list->map_exist == 1)
	{
		ft_mapfree(list);
		ft_mapcopyfree(list);
	}
	free(list);
	ft_printf(RED"Error!\n"COLOR_OFF);
	ft_putstr_fd(msg, 2);
	ft_printf("\n");
	exit (1);
}

void	ft_mapfree(t_list *list)
{
	int	str;

	str = 0;
	while (str < list->map.rows)
		free(list->map.full[str++]);
	free(list->map.full);
}

void	ft_mapcopyfree(t_list *list)
{
	int	str;

	str = 0;
	while (str < list->mapcopy.rows)
		free(list->mapcopy.full[str++]);
	free(list->mapcopy.full);
}

void	ft_destroy_img(t_list *list)
{
	mlx_destroy_image(list->mlx_ptr, list->wall.ptr);
	mlx_destroy_image(list->mlx_ptr, list->floor.ptr);
	mlx_destroy_image(list->mlx_ptr, list->coins.ptr);
	mlx_destroy_image(list->mlx_ptr, list->player.ptr);
	mlx_destroy_image(list->mlx_ptr, list->exit.ptr);
}

void	ft_check_args(int ac, char **av, t_list *list)
{
	int	len;

	list->map_exist = 0;
	if (ac > 2)
		ft_error_exit("Too many agrs!", list);
	if (ac < 2)
		ft_error_exit("No Map file!", list);
	len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][len - 4], ".ber", 4))
		ft_error_exit("Your file extension is not \".ber\"!", list);
}
