/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:42:10 by btani             #+#    #+#             */
/*   Updated: 2022/11/17 17:42:17 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include "libft.h"

char	*ft_read(int fd, int *i)
{
	char	*buff;
	int		a;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	a = read(fd, buff, BUFFER_SIZE);
	if (a < 0 || fd < 0 || fd > 1024)
	{
		free (buff);
		return (NULL);
	}
	buff[a] = '\0';
	*i = a;
	return (buff);
}

char	*ft_after_nl(char *statico)
{
	char	*res;
	int		i;
	int		b;

	i = 0;
	b = 0;
	while (statico[i] && statico[i] != '\n')
		i++;
	if (statico[i] == '\n')
		i++;
	res = (char *)malloc(sizeof(char) * (ft_strlen(statico) - i) + 1);
	while (statico[i])
	{
		res[b] = statico[i];
		i++;
		b++;
	}
	res[b] = '\0';
	free(statico);
	return (res);
}

char	*ft_line_towrite(char *statico)
{
	char	*res;
	int		i;

	i = 0;
	while (statico[i] && statico[i] != '\n')
		i++;
	if (statico[i] == '\n')
		res = (char *)malloc(sizeof(char) * i + 2);
	else
		res = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (statico[i] && statico[i] != '\n')
	{
		res[i] = statico[i];
		i++;
	}
	if (statico[i] == '\n')
	{
		res[i] = '\n';
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*statico;
	char		*buff;
	int			reading;
	int			i;

	reading = 1;
	while (reading > 0)
	{
		i = 0;
		buff = ft_read(fd, &reading);
		statico = ft_struni(statico, buff);
		if (statico == NULL || statico[0] == '\0')
			return (ft_freenreturn(statico));
		while (statico[i] != '\n' && statico[i])
			i++;
		if (statico[i] == '\n' || reading == 0)
		{
			buff = ft_line_towrite(statico);
			statico = ft_after_nl(statico);
			return (buff);
		}
	}
	return (NULL);
}
/*char	*ft_copiariga(char *str)
{
	char	*s;
	int		i;

	i = 0;
	if (!str || !(*str))
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	s = (char *)ft_calloc(sizeof(char), i + 2);
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		s[i] = str[i];
		i++;
	}
	return (s);
}

char	*ft_salvastringa(char *str)
{
	char	*stringa;
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (!*str)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	while (str[a] && str[a] != '\n')
		a++;
	if (str[a] == '\n')
		a++;
	stringa = malloc(sizeof(char) * ft_strlen(str) - a + 1);
	if (!stringa)
		return (NULL);
	while (str[a])
		stringa[b++] = str[a++];
	stringa[b] = '\0';
	free(str);
	return (stringa);
}

char	*ft_leggi(int fd, char *str)
{
	char	*buff;
	char	*sup;
	int		lettura;

	if (!str)
	{
		str = ft_calloc(1, 1);
		if (!str)
			return (NULL);
	}
	lettura = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (lettura != 0)
	{
		lettura = read(fd, buff, BUFFER_SIZE);
		buff[lettura] = '\0';
		sup = str;
		str = ft_strjoin(sup, buff);
		if (ft_strchr(str, '\n'))
			break ;
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{	
		if (str != NULL)
		{
			free(str);
			str = NULL;
		}			
		return (NULL);
	}
	str = ft_leggi(fd, str);
	if (!str)
		return (NULL);
	buffer = ft_copiariga(str);
	str = ft_salvastringa(str);
	return (buffer);
}*/
