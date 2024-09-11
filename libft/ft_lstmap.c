/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:51:04 by ccodere           #+#    #+#             */
/*   Updated: 2024/08/24 10:18:04 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*curr;
	t_list		*new;
	t_list		*new_next;

	if (!lst || !f)
		return (NULL);
	curr = lst;
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	while (curr->next != NULL)
	{
		new_next = ft_lstnew(f(curr->next->content));
		if (!new_next)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, new_next);
		curr = curr->next;
	}
	return (new);
}
