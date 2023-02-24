/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:16:39 by btani             #+#    #+#             */
/*   Updated: 2023/02/23 18:16:41 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_init_variab(t_game *game)
{
	game->map.collect = 0;
	game->map.exit = 0;
	game->map.players = 0;
	game->movs = 0;
	game->map.columns = ft_strlen(game->map.full[0]);
	game->sprite_player = RIGHT;
}

void	ft_init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		ft_error_msg("Error!", game);
	win_ptr = mlx_new_window(game->mlx_ptr, 32 * game->map.colums, 32 * game->map.lines, "SO_LONG"); //32 grandezza immagine
	if (win_ptr == NULL)
	{
		free(game->mlx_ptr);
		ft_error_msg("Error!", game);
	}
}
