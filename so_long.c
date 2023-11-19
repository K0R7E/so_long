/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akortvel <akortvel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:22:35 by akortvel          #+#    #+#             */
/*   Updated: 2023/11/08 14:30:14 by akortvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_so_long(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_add_value(t_list *list)
{
	list->map.coins = 0;
	list->map.exit = 0;
	list->map.player = 0;
	list->moves = 0;
	list->map.cols = ft_strlen(list->map.full[0]);
	list->mapcopy.cols = ft_strlen(list->mapcopy.full[0]);
}

int	main(int ac, char **av)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	ft_check_args(ac, av, list);
	ft_add_map(list, av[1]);
	ft_add_map_copy(list, av[1]);
	ft_add_value(list);
	ft_wallcheck(list);
	ft_correct_map(list);
	ft_player_exit_check(list);
	ft_validpath_check(list);
	ft_add_mlx(list);
	ft_add_img(list);
	ft_render(list);
	mlx_hook(list->window_ptr, KeyPress, KeyPressMask, ft_key, list);
	mlx_hook(list->window_ptr, DestroyNotify, ButtonPressMask, ft_close, list);
	mlx_hook(list->window_ptr, Expose, ExposureMask, ft_render, list);
	mlx_loop(list->mlx_ptr);
	ft_free_all_memory(list);
}
