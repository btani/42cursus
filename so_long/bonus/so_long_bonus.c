/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:59:18 by btani             #+#    #+#             */
/*   Updated: 2023/02/22 15:01:14 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	ft_check_args(ac, av, game);
	ft_init_map(game, av[1]);
	ft_init_variab(game);
	ft_check_map(game);
	ft_init_mlx(game);
	ft_sprites(game);
	ft_render_map(game);
	mlx_hook(game->win_ptr, 02, 1L << 0, ft_input, game);
	mlx_hook(game->win_ptr, 17, 1L << 2, ft_close_game, game);
	mlx_hook(game->win_ptr, 12, 1L << 15, ft_render_map, game);
	mlx_loop(game->mlx_ptr);
	ft_free_mem(game);
}
