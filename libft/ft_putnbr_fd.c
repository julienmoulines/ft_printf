/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouline <jul.moulines@free.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 23:02:43 by jmouline          #+#    #+#             */
/*   Updated: 2022/12/20 15:06:33 by jmouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_count(int n)
{
	char	*to_count;
	int		count;

	to_count = ft_itoa(n);
	count = ft_strlen(to_count);
	free(to_count);
	return (count);
}

int	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	long int	count;

	count = 0;
	if (count == 0)
		count = ft_count(n);
	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = nb * -1;
	}
	if (nb < 10)
		ft_putchar_fd(nb + 48, fd);
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	return (count);
}
