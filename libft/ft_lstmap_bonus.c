/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarrene <lbarrene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:08:13 by lbarrene          #+#    #+#             */
/*   Updated: 2022/09/22 12:08:17 by lbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*head;

	list = NULL;
	if (!list && !f && !del)
		return (NULL);
	head = NULL;
	while (lst)
	{
		list = ft_lstnew(f(lst->content));
		ft_lstadd_back(&head, list);
		lst = lst -> next;
	}
	return (head);
}
