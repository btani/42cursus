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

size_t	ft_strlen(char *s)
{
	size_t	a;

	a = 0;
	if (!s)
		return (0);
	while (s[a] != '\0')
		a++;
	return (a);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{	
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	a;
	char	*f;

	f = s;
	a = 0;
	while (a < n)
	{
		*f = c;
		f++;
		a++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*a;

	a = (void *)malloc(nmemb * size);
	if (a == NULL)
		return (NULL);
	ft_memset(a, 0, nmemb * size);
	return (a);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	dest = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
		return (NULL);
	while (s1[++i])
		dest[i] = s1[i];
	free(s1);
	j = 0;
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (dest);
}
