/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouline <jul.moulines@free.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:07:20 by jmouline          #+#    #+#             */
/*   Updated: 2022/12/20 15:07:26 by jmouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_puthexa(unsigned long int number, char type);
int	ft_format_and_print(va_list args, char type);
int	ft_printf(const char *format, ...);

#endif