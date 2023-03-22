/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:35:05 by btani             #+#    #+#             */
/*   Updated: 2023/03/18 15:35:25 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

char	*ft_joiner(char *s1, char *s2)
{
	int		i;
	int		b;
	char	*newstr;

	i = 0;
	b = 0;
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newstr)
		return (NULL);
	while (s1[i])
		newstr[b++] = s1[i++];
	i = 0;
	while (s2[i])
		newstr[b++] = s2[i++];
	newstr[b] = '\0';
	return (newstr);
}

char	*ft_struni(char *s1, char *s2)
{
	char	*newstr;

	if (s1 == NULL)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (s2 == NULL)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	if (s1[0] == '\0' && s2[0] == '\0')
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	newstr = ft_joiner(s1, s2);
	free(s1);
	free(s2);
	return (newstr);
}

char	*ft_freenreturn(char *str)
{
	free(str);
	return (NULL);
}
