/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouline <jmouline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:40:47 by jmouline          #+#    #+#             */
/*   Updated: 2022/11/15 03:37:11 by jmouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	c;

	if ((!s1 || !s2) && len == 0)
		return (NULL);
	if (*s2 == 0 || s1 == s2)
		return ((char *)s1);
	c = ft_strlen(s2);
	while (*s1 && c <= len--)
	{
		if (!(ft_strncmp((char *)s1, (char *)s2, c)))
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
