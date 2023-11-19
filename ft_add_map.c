/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akortvel <akortvel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:05:58 by akortvel          #+#    #+#             */
/*   Updated: 2023/11/08 14:09:05 by akortvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strappend(char **s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	len1 = ft_strlen(*s1);
	len2 = ft_strlen(s2);
	if (*s1 == NULL || s2 == NULL)
		return (NULL);
	result = (char *)malloc(len1 + len2 + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, *s1, len1 + 1);
	ft_strlcat(result, s2, len1 + len2 + 1);
	free(*s1);
	return (result);
}

void	ft_check_empty_line(char *map, t_list *list)
{
	int	i;

	i = 0;
	if (map[0] == '\n')
	{
		free(map);
		ft_error_exit(YELLOW"This map containis an empty line!"COLOR_OFF, list);
	}
	else if (map[ft_strlen(map) -1] == '\n')
	{
		free(map);
		ft_error_exit(YELLOW"This map containis an empty line!"COLOR_OFF, list);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_error_exit(YELLOW"Empty line in the map!"COLOR_OFF, list);
		}
		i++;
	}
}

void	ft_add_map(t_list *list, char *av)
{
	int		fd;
	char	*map;
	char	*tmp;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error_exit(YELLOW"No map available"COLOR_OFF, list);
	map = ft_strdup("");
	list->map.rows = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		map = ft_strappend(&map, tmp);
		free(tmp);
		list->map.rows++;
	}
	close(fd);
	ft_check_empty_line(map, list);
	list->map.full = ft_split(map, '\n');
	list->map_exist = 1;
	free(map);
}

void	ft_add_map_copy(t_list *list, char *av)
{
	int		fd;
	char	*map;
	char	*tmp;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error_exit(YELLOW"No map available"COLOR_OFF, list);
	map = ft_strdup("");
	list->mapcopy.rows = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		map = ft_strappend(&map, tmp);
		free(tmp);
		list->mapcopy.rows++;
	}
	close(fd);
	list->mapcopy.full = ft_split(map, '\n');
	free(map);
}
