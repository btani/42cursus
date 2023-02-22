/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:19:20 by btani             #+#    #+#             */
/*   Updated: 2023/02/22 15:20:16 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_check_args(int ac, char **av, t_game game)
{
	game->map_alloc = false;
	if (ac > 2)
		ft_error("Too many arguments!", game);
	if (ac < 2)
		ft_error("Too few arguments!", game)
}
