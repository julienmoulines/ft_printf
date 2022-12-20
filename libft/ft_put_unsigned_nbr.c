/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouline <jul.moulines@free.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:05:53 by jmouline          #+#    #+#             */
/*   Updated: 2022/12/20 15:06:06 by jmouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_unsigned_nbr(unsigned int n)
{
	long unsigned int	nb;
	unsigned int		count;
	long unsigned int	i;
	char				*to_count;

	count = 0;
	i = 0;
	if (i == 0)
	{
		to_count = ft_itoa_unsigned(n);
		count = ft_strlen(to_count);
		free (to_count);
	}
	i++;
	nb = n;
	if (nb < 10)
		ft_putchar_fd(nb + 48, 1);
	else
	{
		ft_putnbr_fd(nb / 10, 1);
		ft_putnbr_fd(nb % 10, 1);
	}
	return (count);
}
