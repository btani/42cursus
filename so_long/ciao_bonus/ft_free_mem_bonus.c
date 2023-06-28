/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mem_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:08:42 by btani             #+#    #+#             */
/*   Updated: 2023/03/05 17:09:45 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free_map(t_game *game)
{
	int	str;

	str = 0;
	while (str < game->map.lines)
		free(game->map.full[str++]);
	free(game->map.full);
}

void	ft_destroy_img(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->floor.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->close_ex.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->open_ex.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->collectible.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_f.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_b.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_l.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_r.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->enemy.xpm_ptr);
}

void	ft_free_mem(t_game *game)
{
	ft_destroy_img(game);
	ft_free_map(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
}
