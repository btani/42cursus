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
#include "so_long.h"

void	ft_check_args(int ac, char **av, t_game *game)
{
	int	len_components;

	game->map_alloc = false;
	if (ac > 2)
		ft_error_msg("\033[0;31mToo many arguments!\033[0m", game);
	if (ac < 2)
		ft_error_msg("\033[0;31mToo few arguments!\033[0m", game);
	len_components = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][len_components - 4], ".ber", 4))
		ft_error_msg("\033[0;31mError! File map extension worng\033[0m", game);
}

void	ft_empty_line_check(char *map, t_game *game)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map);
	if (map[0] == '\n' || map[len] == '\n')
	{
		free(map);
		ft_error_msg("\033[0;31mError!Empty space!\033[0m", game);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_error_msg("\033[0;31mError!In middle empty line!\033[0m", game);
		}
		i++;
	}
}

char	*ft_joinstr(char **s1, const char *s2)
{
	char	*str;

	if (!*s1 || !s2)
		return (NULL);
	str = (char *)ft_calloc((ft_strlen(*s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(str, s2, ft_strlen(*s1) + ft_strlen(s2) + 1);
	free(*s1);
	return (str);
}

void	ft_check_void_map(t_game *game, char *tmp_map)
{
	if (game->map.full[0] == NULL)
	{
		free(tmp_map);
		ft_free_matrix(game->map.full);
		ft_error_msg("\033[0;31mOps empty map!\033[0m", game);
	}
}

void	ft_init_map(t_game *game, char *av)
{
	char	*tmp_map;
	char	*tmp_line;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error_msg("\033[0;31mOps impossible to open the map!\033[0m", game);
	tmp_map = ft_calloc(1, sizeof(char *));
	game->map.lines = 0;
	while (true)
	{
		tmp_line = get_next_line(fd);
		if (tmp_line == NULL)
			break ;
		tmp_map = ft_joinstr(&tmp_map, tmp_line);
		free(tmp_line);
		game->map.lines++;
	}
	close(fd);
	ft_empty_line_check(tmp_map, game);
	game->map.full = ft_split(tmp_map, '\n');
	ft_check_void_map(game, tmp_map);
	game->map_alloc = true;
	free(tmp_map);
}
