/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bubble1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:56:29 by rcotter-          #+#    #+#             */
/*   Updated: 2019/06/03 17:35:53 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_min(t_lst *a)
{
	int		min;
	t_lst	*list;

	min = __INT_MAX__;
	list = a;
	while (list)
	{
		if (min > list->data)
			min = list->data;
		list = list->next;
	}
	return (min);
}

int			ft_make_two_stacks(t_stack *stack, t_lst *list, int mid)
{
	t_lst	*tmp;
	int		push_b;
	int		i;

	stack->a = list;
	tmp = list;
	push_b = 0;
	i = 0;
	while (list && i < stack->elem && push_b < stack->elem / 2)
	{
		if (list->data > mid)
			ra(stack);
		else
		{
			pb(stack);
			push_b++;
		}
		list = list->next;
		i++;
	}
	return (0);
}

int			ft_make_one_stack(t_stack *stack)
{
	t_lst	*tmp;
	t_lst	*new;

	tmp = stack->b;
	while (tmp)
	{
		new = ft_listnew(tmp->data);
		new->next = stack->a;
		stack->a = new;
		tmp = tmp->next;
		stack->num_command++;
		write(1, "pb\n", 3);
		new = stack->b;
		stack->b = stack->b->next;
		if (stack->debug)
			debug(stack);
		free(new);
	}
	ft_free(stack->b);
	stack->b = NULL;
	return (0);
}

int			check_after(t_stack *stack, int i)
{
	int		j;
	t_lst	*check;

	j = 0;
	check = stack->a;
	while (j < stack->rotate - i && check)
	{
		if (check->next && check->data > check->next->data)
			return (1);
		check = check->next;
		j++;
	}
	check = stack->b;
	j = 0;
	while (j < stack->rotate - i && check)
	{
		if (check->next && check->data < check->next->data)
			return (1);
		check = check->next;
		j++;
	}
	return (0);
}

int			check_before(t_stack *stack, int rot, int j)
{
	t_lst	*check;

	check = stack->a;
	j = stack->rotate - rot + 1;
	while (j-- && check)
		check = check->next;
	while (check)
	{
		if ((check->next && check->data > check->next->data)
			|| (check->data > stack->a->data))
			return (1);
		check = check->next;
	}
	check = stack->b;
	j = stack->rotate - rot + 1;
	while (j-- && check)
		check = check->next;
	while (check)
	{
		if ((check->next && check->data < check->next->data)
			|| (check->data < stack->b->data))
			return (1);
		check = check->next;
	}
	return (0);
}
