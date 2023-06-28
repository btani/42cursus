/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_game_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:10:12 by btani             #+#    #+#             */
/*   Updated: 2023/03/05 17:13:47 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

int	ft_lose_game(t_game *game)
{
	ft_printf("Moves: %d\n", ++game->movs);
	ft_free_mem(game);
	exit (EXIT_FAILURE);
}

int	ft_victory(t_game *game)
{
	ft_printf("Moves: %d\n", ++game->movs);
	ft_free_mem(game);
	exit (EXIT_FAILURE);
}

int	ft_close_game(t_game *game)
{
	ft_printf("Moves: %d\n", game->movs);
	ft_free_mem(game);
	ft_printf("Closed\n");
	exit (EXIT_FAILURE);
}

int	ft_error_msg(char *msg, t_game *game)
{
	if (game->map_alloc == true)
		ft_free_map(game);
	free(game);
	ft_printf("%s\n", msg);
	exit (EXIT_FAILURE);
}
