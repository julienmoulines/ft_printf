/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouline <jul.moulines@free.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:41:41 by jmouline          #+#    #+#             */
/*   Updated: 2022/11/15 18:44:40 by jmouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;

	d = (char *)dest;
	if (!dest && !src)
		return (dest);
	while (n > 0)
	{
		*(char *)d = *(char *)src;
		d++;
		src++;
		n--;
	}
	return (dest);
}
