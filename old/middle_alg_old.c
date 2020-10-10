/*#include "push_swap.h"

static int	 midle_next_s(t_head *head_a, t_head *head_b, int min_s)
{
	int size;
	//printf("min_sssssssssss = %d\n", min_s);
	//printf("indexxxxx = %zu\n", head_a->stack->index);
	if (head_a->size % 4 == 0)
		size = head_a->size / 4;
	else if (head_a->size % 4 != 0 && head_a->size % 2 == 0)
		size = head_a->size / 4 + 1;
	else
		size = head_a->size / 4;
	//printf("size = %d\n", size);
	//printf("min_sssssssssss = %zu\n", min_s);
	//getchar();
	while (size > 0)
	{
		if (head_a->stack->index == min_s)
		{
			ra_rb_instruction(head_a);
			ft_printf("ra\n");
			min_s = min_s + 1;
		}
		else if (head_a->stack->next->index == min_s && head_a->stack->next->index  == head_a->stack->index + 1)
		{
			sa_sb_instruction(head_a);
			ra_rb_instruction(head_a);
			ra_rb_instruction(head_a);
			ft_printf("sa\n");
			ft_printf("ra\n");
			ft_printf("ra\n");
			min_s = min_s + 1;
		}
		else
		{
			pa_pb_instruction(head_b, head_a);
			ft_printf("pb\n");
		}
		size--;
		//print_two_stack(head_a, head_b);
		//getchar();
	}
	return (min_s);
}

static int		midle_next_simple(t_head *head_a, int min_s)
{
	int min;

	min = min_s;
	while (head_a->stack->index == min)
	{
		ra_rb_instruction(head_a);
		ft_printf("ra\n");
		min = min + 1;
	}
	//printf("min = %zu\n", min);25
	//printf("in = %zu\n", head_a->stack->index);
	return (min);
}

static int		midle_next(t_head *head_a, t_head *head_b, int min_s)
{
	int min;

	min = midle_next_s(head_a, head_b, min_s);
	while (head_a->stack->index == min)
	{
		ra_rb_instruction(head_a);
		ft_printf("ra\n");
		min = min + 1;
	}
	//printf("min = %d\n", min);25
	//printf("in = %zu\n", head_a->stack->index);
	return (min);
}

static int		midle_eighth_s(t_head *head_a, t_head *head_b, int min_s)
{
	int min=0 + min_s;//printf("min = %d\n", min);printf("min_s = %d\n", min_s);
	int max=head_a->size / 4  + min_s - min_s % (head_a->size / 4);//printf("max = %d\n", max);printf("size/4  = %d\n", head_a->size / 4);getchar();
	int mid;
//printf("size / 4 = %d\n", head_a->size / 4);
//getchar();
	if (head_a == NULL)
		return (0);
	if (head_b == NULL)
		return (0);
	mid = head_a->size / 8;
	if (min_s >= head_a->size / 2)
		max = head_a->size - 1;
	//printf("min = %d\n", min);printf("min_s = %d\n", min_s);
	//printf("max = %d\n", max);printf("size/4  = %d\n", head_a->size / 4);
	//getchar();
	//getchar();
	//print_two_stack(head_a, head_b);
	//getchar();
	while (head_b->stack)
	{
		if (head_b->stack->index == min)
		{
			pa_pb_instruction(head_a, head_b);
			ra_rb_instruction(head_a);
			ft_printf("pa\n");
			ft_printf("ra\n");
			min = min + 1;
		}
		else if (head_b->stack->index == max)
		{
			pa_pb_instruction(head_a, head_b);
			ft_printf("pa\n");
			max = max - 1;
		}
		else if (head_b->stack->index != min && head_b->stack->index != max)
		{
			//check_last_el(head_a, head_b);
			t_stack *last_elem;
			t_stack *pre_last_elem;
			last_elem = head_b->stack;
			pre_last_elem = head_b->stack;
			while (last_elem->next != NULL)
			{
				pre_last_elem = last_elem;
				last_elem = last_elem->next;
			}
			if (last_elem->index == min)
			{
				rra_rrb_instruction(head_b);
				pa_pb_instruction(head_a, head_b);
				ra_rb_instruction(head_a);
				ft_printf("rrb\n");
				ft_printf("pa\n");
				ft_printf("ra\n");
				min = min + 1;
			}
			else if (last_elem->index == max)
			{
				rra_rrb_instruction(head_b);
				pa_pb_instruction(head_a, head_b);
				ft_printf("rrb\n");
				ft_printf("pa\n");
				max = max - 1;
			}
			else if (pre_last_elem->index == min)
			{
				rra_rrb_instruction(head_b);
				rra_rrb_instruction(head_b);
				pa_pb_instruction(head_a, head_b);
				ra_rb_instruction(head_a);
				ft_printf("rrb\n");
				ft_printf("rrb\n");
				ft_printf("pa\n");
				ft_printf("ra\n");
				min = min + 1;
			}
			else if (pre_last_elem->index == max)
			{
				rra_rrb_instruction(head_b);
				rra_rrb_instruction(head_b);
				pa_pb_instruction(head_a, head_b);
				ft_printf("rrb\n");
				ft_printf("rrb\n");
				ft_printf("pa\n");
				max = max - 1;
			}
			else if (head_b->stack->next->index == min || head_b->stack->next->index == max)
			{
				sa_sb_instruction(head_b);
				ft_printf("sb\n");
				if (head_b->stack->index == min)
				{
					pa_pb_instruction(head_a, head_b);
					ra_rb_instruction(head_a);
					ft_printf("pa\n");
					ft_printf("ra\n");
					min = min + 1;
				}
				else if (head_b->stack->index == max)
				{
					pa_pb_instruction(head_a, head_b);
					ft_printf("pa\n");
					max = max - 1;
				}
			}
			else
			{	
				ra_rb_instruction(head_b);
				ft_printf("rb\n");
			}
		}
		//printf("min = %d\n", min);
		//printf("max = %d\n", max);
		//print_two_stack(head_a, head_b);
		//getchar();
	}
	return (min);
}

static int		midle_eighth(t_head *head_a, t_head *head_b, int min_s)
{
	int min;

	min = midle_eighth_s(head_a, head_b, min_s);
	//printf("min = %d\n", min);
	//getchar();
	//printf("index = %d\n", head_a->stack->index);
	//getchar();
	while (head_a->stack->index == min)
	{
		ra_rb_instruction(head_a);
		ft_printf("ra\n");
		min = min + 1;
	}
	return (min);
}

static void		midle_fourth(t_head *head_a, t_head *head_b)
{
	int	size;

	size = head_a->size / 2;
	//printf("size4 = %d\n", head_a->size / 4);
	while (size > 0)
	{
		if (head_b->stack->index >= head_a->size / 4)
		{
			pa_pb_instruction(head_a, head_b);
			ft_printf("pa\n");
		}
		else
		{
			ra_rb_instruction(head_b);
			ft_printf("rb\n");
		}
		size--;
	}
}

static int		middle_half_2(t_head *head_a, t_head *head_b, int min_s)
{
	int	size;

	if (head_a->size % 2 == 0)
		size = head_a->size / 2;
	else
		size = head_a->size / 2 + 1;
	while (size > 0)
	{
		if (head_a->stack->index > head_a->size / 2)
		{
			pa_pb_instruction(head_b, head_a);
			ft_printf("pb\n");
			if (head_b->stack->next != NULL && head_b->stack->index < head_a->size / 4 * 3)
			{
				ra_rb_instruction(head_b);
				ft_printf("rb\n");
			}
		}
		else
		{
			ra_rb_instruction(head_a);
			ft_printf("ra\n");
			min_s = min_s + 1;
		}
		size--;
		//print_two_stack(head_a, head_b);
		//getchar();
	}
	return (min_s);
}
static void		middle_half(t_head *head_a, t_head *head_b)
{
	int	size;

	size = head_a->size;
	//print_two_stack(head_a, head_b);
	//getchar();
	while (size > 0)
	{
		if (head_a->stack->index < head_a->size / 2)
		{
			pa_pb_instruction(head_b, head_a);
			ft_printf("pb\n");
			if (head_b->stack->next != NULL && head_b->stack->index < head_a->size / 4)
			{
				ra_rb_instruction(head_b);
				ft_printf("rb\n");
			}			
		}
		else
		{
			ra_rb_instruction(head_a);
			ft_printf("ra\n");
		}
		size--;
		//print_two_stack(head_a, head_b);
		//getchar();
	}
}

void middle_alg(t_head *head_a)
{
	t_head	*head_b;
	int min_s;

	if (head_a == NULL)
		return ;
	if (!(head_b = (t_head *)ft_memalloc(sizeof(t_head))))
		exit_error();
	//printf("\nPOLOVINA 1 PART\n");
	//getchar();
	middle_half(head_a, head_b);
	//print_two_stack(head_a, head_b);
	//getchar();

	//printf("\nCHETVERT PART\n");
	//getchar();
	midle_fourth(head_a, head_b); //в стэек б перенесли первые 25
	//print_two_stack(head_a, head_b);
	//getchar();

	min_s = 0;
	//printf("\nV STACK A VNIZ OTSORTIROVANYU 1/4\n");
	//getchar();
	min_s = midle_eighth(head_a, head_b, min_s);// осортировали 1-25 внизу в стэке а, б пуст
	if (head_b->stack != NULL)
	{
		while (head_b->stack != NULL)
		{
			pa_pb_instruction(head_a, head_b);
			ft_printf("pa\n");
		}
	}
	//print_two_stack(head_a, head_b);
	//getchar();
	//printf("min_s = %d\n", min_s);
	//getchar();

	//printf("\nV STACK B VTORYU 1/4\n");
	//getchar();
	min_s = midle_next(head_a, head_b, min_s);// 25 -50 в стэк б
	//print_two_stack(head_a, head_b);
	//getchar();
	//printf("min_s = %d\n", min_s);
	//ok
	//printf("!!!!!!!!!!!!!!!!!!!!\n");
	//printf("min_s0 = %d\n", min_s);
	//print_two_stack(head_a, head_b);
	//getchar();
	//printf("WWHAAAAAATTTTTTT\n");
	//getchar();

	//printf("\nV STACK A VTORYU 1/4 VNIZ OTSORTIROVANYU\n");
	//getchar();
	min_s = midle_eighth(head_a, head_b, min_s);//осортировали 26-50 внизу в стэке а, б пуст
	if (head_b->stack != NULL)
	{
		while (head_b->stack != NULL)
		{
			pa_pb_instruction(head_a, head_b);
			ft_printf("pa\n");
		}
	}
	//printf("min_s1 = %d\n", min_s);
	//print_two_stack(head_a, head_b);
	//getchar();

	//getchar();
	//printf("\nV STACK B VTORYU POLOVINA\n");
	//getchar();
	min_s = middle_half_2(head_a, head_b, min_s);//перекинули 2 половину в б
	
	//print_two_stack(head_a, head_b);
	//getchar();
	//printf("OKKKEEEE SSSSOOOOORRRRRTTTT 50\n");
	//printf("min_s1 = %d\n", min_s);
	//printf("\nV STACK B V STACK A VNIZ I VVERH\n");
	//getchar();
	min_s = midle_eighth(head_a, head_b, min_s);//раскидали б на верх и низ по сортировке
	if (head_b->stack != NULL)
	{
		while (head_b->stack != NULL)
		{
			pa_pb_instruction(head_a, head_b);
			ft_printf("pa\n");
		}
	}
	//min_s = midle_next(head_a, head_b, min_s);
	//printf("min_s2 = %d\n", min_s);
	//print_two_stack(head_a, head_b);
	//getchar();
	//printf("min_s1111 = %d\n", min_s);
	//getchar();
	//printf("\n\n\n\nEEEEEENNNNNDDDDD\n\n\n");
	//getchar();
	//printf("\nV STACK A S VVERHY VNIZ OTORTIROVANNOE\n");
	//getchar();
	min_s = midle_next_simple(head_a, min_s);//вернули отсортированный вверх вниз

	//printf("min_s = %d\n", min_s);
	//printf("s_a = %d\n", head_a->size);
	//printf("s_b = %d\n", head_b->size);
	//print_two_stack(head_a, head_b);
	//printf("Middle is ready\n");
	lst_delete(head_b);
}*/
/*
printf("i = %d\n", i);
print_stack(head_a);
printf("\n");
print_stack(head_b);
printf("\n");
getchar ();
*/