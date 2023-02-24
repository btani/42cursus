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

# include "../minilibix-linux/mlx.h"
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include <fcntl.h>
# include <time.h>
# include <stdlib.h>

# define WALL = "1"
# define FLOOR = "0"
# define COLLECITBLE = "C"
# define EXIT = "E"
# define PLAYER = "P"

# define FRONT
# define BACK
# define LEFT
# define RIGHT

typedef struct s_map
{
	int		lines;
	int		columns;
	int		collect;
	int 		exit;
	int		players;
	t_position	player;
	char	**full;
}	t_map;

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

typedef struct s_game
{
	t_bool	map_alloc;
	t_game	*game;
	int		movs;
	int		sprite_player;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_game;






void	ft_check_args(int ac, char **av, t_game game);
void	ft_init_map(t_game *game, char *av);
int		ft_error_msg(char *msg, t_game *game);
char	*ft_joinstr(char **s1, const char *s2);
void	ft_empty_line_check(char *map, t_game *game);
void	ft_free_map(t_game *game);
void	ft_init_variab(t_game *game);
void	ft_check_map(t_game *game);
void	ft_check_lines(t_game game);
void	ft_check_columns(t_game *game);
void	ft_num_of_components(t_game *game);
void	ft_check_components(t_game *game);

