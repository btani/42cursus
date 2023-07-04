/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:39:26 by btani             #+#    #+#             */
/*   Updated: 2023/02/22 15:39:28 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_free_map(t_game *game)
{
	int	str;

	str = 0;
	while (game && str < game->map.lines)
	{
		if (game->map.full[str])
			free(game->map.full[str++]);
	}
	if (game && game->map.full)
		free(game->map.full);
	game->map_alloc = false;
}

void	ft_free_matrix(char **matrix)
{
	int	y;

	y = 0;
	while (matrix[y])
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
}

void	ft_destroy_img(t_game *game)
{
	if (game->floor.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->floor.xpm_ptr);
	if (game->wall.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr);
	if (game->close_ex.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->close_ex.xpm_ptr);
	if (game->open_ex.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->open_ex.xpm_ptr);
	if (game->collectible.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->collectible.xpm_ptr);
	if (game->player_f.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player_f.xpm_ptr);
	if (game->player_b.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player_b.xpm_ptr);
	if (game->player_l.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player_l.xpm_ptr);
	if (game->player_r.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player_r.xpm_ptr);
}

void	ft_free_mem(t_game *game)
{
	if (game)
		ft_destroy_img(game);
	if (game && game->map_alloc == true)
		ft_free_map(game);
	if (game && game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game && game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	if (game && game->mlx_ptr)
		free(game->mlx_ptr);
	if (game)
		free(game);
}
