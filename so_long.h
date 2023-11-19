/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akortvel <akortvel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:44:46 by akortvel          #+#    #+#             */
/*   Updated: 2023/11/08 14:29:30 by akortvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft/libft.h"

# define COLOR_OFF  "\033[0m"
# define RED		"\033[1;91m"
# define GREEN	  "\033[0;32m"
# define YELLOW	 "\033[0;33m"
# define BLUE	   "\033[0;34m"	 

# define WALL				'1'
# define FLOOR 				'0'
# define COINS  			'C'
# define PLAYER				'P'
# define EXIT 			 	'E'

# define W					119
# define A					97
# define S					115
# define D					100
# define LEFT_ARROW			65361
# define UP_ARROW			65362
# define RIGHT_ARROW		65363
# define DOWN_ARROW			65364

# define Q					113
# define ESC  				65307

typedef struct s_image
{
	void	*ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_map
{
	char	**full;
	int		rows;
	int		cols;
	int		coins;
	int		exit;
	int		player;
	int		position_x;
	int		position_y;
}	t_map;

typedef struct s_mapcopy
{
	char	**full;
	int		rows;
	int		cols;
	int		coins;
	int		exit;
	int		player;
	int		position_x;
	int		position_y;
}	t_mapcopy;

typedef struct s_list
{
	void		*mlx_ptr;
	void		*window_ptr;
	int			moves;
	int			map_exist;
	t_map		map;
	t_mapcopy	mapcopy;
	t_image		wall;
	t_image		floor;
	t_image		coins;
	t_image		exit;
	t_image		player;
}	t_list;

void	ft_check_args(int ac, char **av, t_list *list);
int		ft_error_exit(char *msg, t_list *list);
void	ft_mapfree(t_list *list);
void	ft_add_map(t_list *list, char *av);
void	ft_add_map_copy(t_list *list, char *av);
void	ft_check_empty_line(char *map, t_list *list);
char	*ft_strappend(char **s1, const char *s2);
void	ft_add_value(t_list *list);
void	ft_wallcheck(t_list *list);
void	ft_correct_map(t_list *list);
void	ft_player_exit_check(t_list *list);
void	ft_add_mlx(t_list *list);
t_image	ft_add_new_img(void *mlx, char *path, t_list *list);
void	ft_add_img(t_list *list);
int		ft_render(t_list *list);
void	ft_render_imgs(t_list *list, int y, int x);
void	ft_render_img(t_list *list, t_image new_img, int line, int column);
void	ft_free_all_memory(t_list *list);
void	ft_mapcopyfree(t_list *list);
void	ft_destroy_img(t_list *list);
void	ft_validpath_check(t_list *list);
int		ft_key(int keysym, t_list *list);
void	ft_move(t_list *list, int new_y, int new_x);
void	ft_win(t_list *list);
int		ft_close(t_list *list);
int		is_reachable(char **map, int x, int y, int rows);
int		ft_strlen_so_long(char *s);

#endif
