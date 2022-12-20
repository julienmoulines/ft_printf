/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouline <jul.moulines@free.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:11:46 by jmouline          #+#    #+#             */
/*   Updated: 2022/11/15 18:11:26 by jmouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_normed(const char *s1, const char *s2, char *dest)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	if (!dest)
		return (NULL);
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	if (i < (len_s1 + len_s2))
	{
		while (i < len_s1)
		{
			dest[i] = s1[i];
			i++;
		}
		len_s1 = 0;
		while (s2[len_s1])
			dest[i++] = s2[len_s1++];
	}
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*dest;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dest = ft_calloc(len_s1 + len_s2 + 1, 1);
	if (!dest)
		return (NULL);
	dest = ft_strjoin_normed(s1, s2, dest);
	return (dest);
}
