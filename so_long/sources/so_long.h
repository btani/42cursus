/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:21:48 by btani             #+#    #+#             */
/*   Updated: 2023/02/10 20:35:48 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libraries/Libft/libft.h"
# include "../libraries/Libft/ft_printf.h"
# include "../libraries/Libft/get_next_line.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <time.h>
# include <stdlib.h>
# include <unistd.h>

# define GREEN = \033[0;32m
# define RED = \033[0;31m
# define YELLOW = \033[0;33m
# define PURPLE = \033[0;35m
# define NO_COLOR = \033[0m

# define WALL '1'
# define FLOOR '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define FRONT 1
# define BACK 2
# define LEFT 3
# define RIGHT 4

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_map
{
	int			lines;
	int			columns;
	int			collects;
	int			exit;
	int			players;
	t_position	player;
	char		**full;
}	t_map;

typedef struct s_game
{
	t_bool	map_alloc;
	int		movs;
	int		player_sprite;
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
	t_image	floor;
	t_image	wall;
	t_image	collectible;
	t_image	open_exit;
	t_image	close_exit;
	t_image	player_f;
	t_image	player_b;
	t_image	player_l;
	t_image	player_r;
}	t_game;

void	ft_check_args(int ac, char **av, t_game *game);
void	ft_init_map(t_game *game, char *av);
int		ft_error_msg(char *msg, t_game *game);
char	*ft_joinstr(char **s1, const char *s2);
void	ft_empty_line_check(char *map, t_game *game);
void	ft_free_map(t_game *game);
void	ft_init_variab(t_game *game);
void	ft_check_map(t_game *game);
void	ft_check_lines(t_game *game);
void	ft_check_columns(t_game *game);
void	ft_num_of_components(t_game *game);
void	ft_check_components(t_game *game);
void	ft_init_mlx(t_game *game);
t_image	ft_put_sprite(void *mlx, char *path, t_game *game);
void	ft_sprites(t_game *game);
int		ft_render_map(t_game *game);
void	ft_put_image_to_wind(t_game *game, t_image sprite, int y, int x);
void	ft_which_sprite(t_game *game, int y, int x);
void	ft_which_player(t_game *game, int y, int x);
int		ft_input(int key, t_game *game);
void	ft_move_player(t_game *game, int new_y, int new_x, int player_sprite);
int		ft_close_game(t_game *game);
int		ft_victory(t_game *game);
void	ft_destroy_img(t_game *game);
void	ft_free_mem(t_game *game);
void	ft_movements(t_game *game);
//int		ft_flood_fill(char **tab, t_map size, t_position begin);
//void	ft_find(char **temp, t_map size, t_position pos);
#endif
