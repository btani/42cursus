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

typedef struct s_map
{
	int	lines;
	char	**full;
}	t_map;

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_game
{
	t_bool	map_alloc;
}	t_game *game;







void	ft_check_args(ac, av, game);
int	ft_error_msg(char *msg, t_game *game);
void	ft_free_map(t_game *game);
