/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:36:45 by btani             #+#    #+#             */
/*   Updated: 2023/02/22 15:36:46 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_victory(t_game *game)
{
	ft_printf("Moves: %d\n", ++game->movs);
	ft_free_mem(game);
	ft_printf("\033[0;32mYou win!\n\033[0m");
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
	ft_free_mem(game);
	ft_printf("%s\n", msg);
	exit (EXIT_FAILURE);
}
