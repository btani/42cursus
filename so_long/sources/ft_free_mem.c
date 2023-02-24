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
	while (str < game->map.lines)
		free(game->map.full[str++]);
	free(game->map.full);
}
