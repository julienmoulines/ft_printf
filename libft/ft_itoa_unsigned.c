/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouline <jul.moulines@free.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 03:17:05 by jmouline          #+#    #+#             */
/*   Updated: 2022/12/19 03:54:44 by jmouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(unsigned long int n)
{
	int	count;
	int	sign;

	count = 1;
	sign = 0;
	if (n < 0)
	{
		sign += 1;
		n *= -1;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count + sign);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char		*dest;
	long int	nb;
	int			size;

	nb = n;
	size = ft_count(nb);
	dest = ft_calloc(size + 1, 1);
	if (!dest)
		return (NULL);
	if (nb < 0)
		nb *= -1;
	while (size - 1 >= 0)
	{
		dest[size - 1] = nb % 10 + 48;
		nb /= 10;
		size--;
	}
	if (n < 0)
		dest[0] = '-';
	return (dest);
}
