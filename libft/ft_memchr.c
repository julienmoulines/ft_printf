/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouline <jmouline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:40:35 by jmouline          #+#    #+#             */
/*   Updated: 2022/11/14 18:53:06 by jmouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*dest;

	if (!s)
		return (NULL);
	dest = (unsigned char *)s;
	while (n > 0)
	{
		if (*dest == (unsigned char)c)
			return ((unsigned char *)dest);
		dest++;
		n--;
	}
	return (NULL);
}
