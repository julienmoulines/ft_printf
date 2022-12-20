/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouline <jmouline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:48:13 by jmouline          #+#    #+#             */
/*   Updated: 2022/11/15 03:36:43 by jmouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_lstclear_norme(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !del)
		return (NULL);
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_element;
	t_list	*new_lst;

	if (!lst || !f || !del)
		return (NULL);
	new_element = ft_lstnew(f(lst->content));
	if (!new_element)
	{
		ft_lstclear(&new_lst, del);
		return (ft_lstclear_norme(&lst, del));
	}
	new_lst = new_element;
	lst = lst->next;
	while (lst)
	{
		new_element = ft_lstnew(f(lst->content));
		if (!new_element)
		{
			ft_lstclear(&lst, del);
			return (ft_lstclear_norme(&new_lst, del));
		}
		lst = lst->next;
		ft_lstadd_back(&new_lst, new_element);
	}
	return (new_lst);
}
