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
	ft_printf("Movements: %d\n", ++game->movs);
	ft_free_mem(game);
	//inserisci immagine "you win"
	exit (EXIT_FAILURE);
}

int	ft_close_game(t_game *game)
{
	ft_printf("Movements: %d\n", game->movs);
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
	//nb! EXIT_FAILURE = 1; EXIT SUCCESS = 0 fanno parte di stdlib.h
}
