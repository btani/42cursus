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

void	ft_check_args(int ac, char **av, t_game game)
{
	game->map_alloc = false;
	if (ac > 2)
		ft_error_msg("Too many arguments!", game);
	if (ac < 2)
		ft_error_msg("Too few arguments!", game);
}

void	ft_empty_line_check(char *map, t_game *game)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map);
	if (map[0] == '\n')
	{
		free(map);
		ft_error_msg("Invalid map, empty line at the beginning", game);
	}
	else if (map[len] == '\n')
	{
		free(map);
		ft_error_msg("Invalid map, empty line at the end", game);
	}
	while (map[i + 1] == '\n')
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_error_msg("Invalid map, empty line in the middle", game);
		}
		i++;
	}
}

char	*ft_joinstr(char **s1, const char *s2)
{
	char	*str;

	if (!*s1 || ! s2)
		return (NULL);
	str = (char *)ft_calloc(ft_strlen(*s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(str, s2, ft_strlen(*s1) + ft_strlen(s2) + 1);
	free(*s1);
	return (str);
}

void	ft_init_map(t_game *game, char *av)
{
	char	*tmp_map;
	char	*tmp_line;
	int		fd;

	fd = open(av, 0_RDONLY);
	if (fd == -1)
		ft_error_msg("Ops impossible to open the map", game);
	tmp_map = ft_strdup("");
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
	game->map_alloc = true;
	free(tmp_map);
}
