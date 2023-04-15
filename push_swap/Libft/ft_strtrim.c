/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:30:40 by btani             #+#    #+#             */
/*   Updated: 2022/10/14 17:49:19 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_controllaset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		a;
	int		i;
	int		f;
	char	*s2;

	a = 0;
	i = 0;
	f = ft_strlen(s1);
	if (s1 == 0 || set == 0)
		return (0);
	while (s1[i] && ft_controllaset(s1[i], set))
		i++;
	while (f > i && ft_controllaset(s1[f - 1], set))
		f--;
	s2 = (char *)malloc(sizeof(char) * f - i + 1);
	if (!s2)
		return (NULL);
	while (i < f)
	{
		s2[a] = s1[i];
		a++;
		i++;
	}
	s2[a] = '\0';
	return (s2);
}
