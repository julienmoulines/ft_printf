/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouline <jmouline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:49:31 by jmouline          #+#    #+#             */
/*   Updated: 2022/11/15 03:37:08 by jmouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dest;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	dest = ft_calloc(ft_strlen(s) + 1, 1);
	if (!dest)
		return (NULL);
	while (*s)
	{
		dest[i] = f(i, *s++);
		i++;
	}
	return (dest);
}
