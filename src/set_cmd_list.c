/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 12:13:53 by pelease           #+#    #+#             */
/*   Updated: 2020/06/13 00:38:36 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					set_cmd_list(t_list **head)
{
	char	*command;
	int		error;

	command = NULL;
	error = 0;
	*head = NULL;
	while (get_next_line(0, &command) > 0)
	{
		if (!(ft_strcmp(command, "sa") == 0 || ft_strcmp(command, "sb") == 0 ||
			ft_strcmp(command, "ss") == 0 || ft_strcmp(command, "pa") == 0 ||
			ft_strcmp(command, "pb") == 0 || ft_strcmp(command, "ra") == 0 ||
			ft_strcmp(command, "rb") == 0 || ft_strcmp(command, "rr") == 0 ||
			ft_strcmp(command, "rra") == 0 || ft_strcmp(command, "rrb") == 0
			|| ft_strcmp(command, "rrr") == 0))
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		list_push(head, command);
		command = NULL;
	}
	return (!error);
}
