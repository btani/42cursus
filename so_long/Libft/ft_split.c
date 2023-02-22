/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:03:17 by btani             #+#    #+#             */
/*   Updated: 2022/10/16 17:55:53 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct t_vect
{
	int	i;
	int	j;
}	t_vect;

static int	ft_conto(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static	char	*ft_sup_split(char **new, const char *s, t_vect *var, int *n)
{
	char	*sub;

	sub = (char *)ft_calloc((*n + 1), sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, &s[(*var).i - *n], (*n + 1));
	new[(*var).j] = sub;
	((*var).j)++;
	*n = 0;
	return (sub);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		n;
	t_vect	var;

	var.i = 0;
	n = 0;
	var.j = 0;
	new = (char **)ft_calloc ((ft_conto(s, c) + 1), sizeof(char *));
	if (!new)
		return (NULL);
	while (s[var.i])
	{
		while (s[var.i] == c && s[var.i] != '\0')
			var.i++;
		while (s[var.i] != c && s[var.i] != '\0')
		{
			n++;
			var.i++;
		}
		if (n != 0)
			ft_sup_split(new, s, &var, &n);
	}
	return (new);
}
