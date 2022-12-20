/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouline <jmouline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 23:30:00 by jmouline          #+#    #+#             */
/*   Updated: 2022/11/15 03:37:00 by jmouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dest;
	int		i;

	i = 0;
	len = ft_strlen(s);
	dest = malloc(len + 1);
	if (!(dest))
		return (NULL);
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
