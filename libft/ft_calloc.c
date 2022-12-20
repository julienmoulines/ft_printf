/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouline <jul.moulines@free.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 23:06:08 by jmouline          #+#    #+#             */
/*   Updated: 2022/11/15 18:21:20 by jmouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nb_element, size_t nb_octe)
{
	void	*tab;
	size_t	count;	

	if (!nb_element || !nb_octe)
		return (NULL);
	count = nb_element * nb_octe;
	if (nb_octe != 0 && SIZE_MAX / nb_octe < nb_element)
		return (NULL);
	tab = malloc(count);
	if (!tab)
		return (NULL);
	ft_memset(tab, 0, count);
	return (tab);
}
