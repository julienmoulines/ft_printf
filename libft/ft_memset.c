/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouline <jmouline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:41:50 by jmouline          #+#    #+#             */
/*   Updated: 2022/11/15 03:36:52 by jmouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;

	if (!s)
		return (NULL);
	str = s;
	while (n > 0)
	{
		*str = (char)c ;
		str++;
		n--;
	}
	return (s);
}
