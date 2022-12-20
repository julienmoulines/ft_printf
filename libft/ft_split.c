/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouline <jul.moulines@free.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:08:32 by jmouline          #+#    #+#             */
/*   Updated: 2022/11/15 18:06:14 by jmouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, char sep)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 1;
	while (s[i] == sep)
		i++;
	if (s[i] == '\0')
		return (1);
	while (s[i])
	{
		if (s[i] == sep)
		{
			while (s[i] == sep)
				i++;
			if (s[i] != '\0')
				count++;
		}
		else
			i++;
	}
	return (count + 1);
}

static char	**ft_freetab(char **tab)
{
	int	i;

	i = -1;
	while (tab[i])
		free(tab[++i]);
	free(tab);
	return (NULL);
}

char	**ft_split_norme(char **tab, char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	while (k < ft_count(s, c) - 1)
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[j] != c && s[j])
			j++;
		tab[k] = ft_substr(s, i, j - i);
		if (tab[k] == NULL)
			return (ft_freetab(tab));
		k++;
		i = j;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char		**tab;

	if (!s)
		return (NULL);
	if ((*s == 0 && c == 0) || (!s && c == 0))
	{
		tab = ft_calloc(1, sizeof(char *));
		return (tab);
	}
	tab = ft_calloc(ft_count(s, c), sizeof(char *));
	if (!tab)
		return (NULL);
	ft_split_norme(tab, s, c);
	return (tab);
}
