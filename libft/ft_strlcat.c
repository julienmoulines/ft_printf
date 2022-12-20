/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouline <jmouline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:40:42 by jmouline          #+#    #+#             */
/*   Updated: 2022/11/15 03:37:04 by jmouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	ret;

	ret = 0;
	if (size == 0)
		return (ret + ft_strlen(src));
	while (dest[ret] && ret < size)
		ret++;
	i = ret;
	while (i < size - 1 && src[i - ret])
	{
		dest[i] = src[i - ret];
		i++;
	}
	if (ret < size)
		dest[i] = 0;
	return (ret + ft_strlen(src));
}
