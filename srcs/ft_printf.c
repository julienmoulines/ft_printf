/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouline <jul.moulines@free.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:05:38 by jmouline          #+#    #+#             */
/*   Updated: 2022/12/20 15:05:39 by jmouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

int	ft_puthexa(unsigned long int number, char type)
{
	char	*base;
	int		count;
	char	res[100];
	int		i;

	i = 0;
	count = 0;
	base = "0123456789abcdef";
	if (type == 'X')
		base = "0123456789ABCDEF";
	//if (type == 'p' && number == 0)
		//return (ft_putstr_fd("(nil)", 1));
	else if (type == 'p')
		count += write(1, "0x", 2);
	if (number == 0)
		count += write(1, "0", 1);
	while (number)
	{
		res[i++] = number % 16;
		number = number / 16;
	}
	while (--i >= 0)
		count += ft_putchar_fd(base[(int)res[i]], 1);
	return (count);
}

int	ft_format_and_print(va_list args, char type)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_putchar_fd(va_arg(args, int), 1);
	else if (type == 's')
		count += ft_putstr_fd(va_arg(args, char *), 1);
	else if (type == 'p')
		count += ft_puthexa(va_arg(args, unsigned long), type);
	else if (type == 'd' || type == 'i')
		count += ft_putnbr_fd(va_arg(args, int), 1);
	else if (type == 'u')
		count += ft_put_unsigned_nbr(va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		count += ft_puthexa(va_arg(args, unsigned int), type);
	else if (type == '%')
		count += write (1, "%", 1);
	va_end(args);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int	count;
	int	i;

	va_list(args);
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_format_and_print(args, format[i + 1]);
			i += 2;
		}
		else if (format[i])
			count += ft_putchar_fd(format[i++], 1);
	}
	return (count);
}

/*int main()
{
	
	int count = ft_printf("%d %X %x\n", 3, 0, 0);
	printf("%d\n", count);
	count = printf("%d %X %x\n", 3, 0, 0);
	printf("%d\n", count);
}*/