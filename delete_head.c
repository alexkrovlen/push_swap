#include "push_swap.h"

static void	ft_free(char **arr)
{
	int i;

	if (!arr)
		return ;
	i = 0;
	while (i < 4)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

int		free_str(char **str)
{
	if (!str)
		return (0);
	ft_free(str);
	return (0);
}

t_stack	*lst_delete_one(t_stack *lst)
{
	t_stack	*next;

	next = lst->next;
	free(lst);
	return (next);
}

void		lst_delete(t_head *head)
{
	if (!head)
		return ;
	while (head->stack)
	{
		(head->stack)->next = NULL;
		head->stack = lst_delete_one(head->stack);
	}
	free(head);
}