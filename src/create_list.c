/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 12:13:53 by pelease           #+#    #+#             */
/*   Updated: 2020/06/16 00:38:45 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			list_push(t_list **head, char *data)
{
	t_list			*new;
	t_list			*lst;

	if (head == NULL)
		return ;
	if (!(new = list_create(data)))
		return ;
	if (*head == NULL)
		*head = new;
	else
	{
		lst = *head;
		while (lst && lst->next)
			lst = lst->next;
		lst->next = new;
	}
}

t_list			*list_create(char *data)
{
	t_list			*lst;

	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	lst->next = NULL;
	lst->content = data;
	return (lst);
}

void			clear_list(t_list **lst)
{
	t_list		*del;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		del = *lst;
		*lst = (*lst)->next;
		if (del->content)
			free(del->content);
		free(del);
	}
}
