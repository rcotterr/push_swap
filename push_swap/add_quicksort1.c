/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_quicksort1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 19:10:33 by rcotter-          #+#    #+#             */
/*   Updated: 2019/06/03 17:49:46 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_last_elem(t_lst *list)
{
	t_lst	*tmp;
	int		res;

	tmp = list;
	res = list->data;
	while (tmp)
	{
		res = tmp->data;
		tmp = tmp->next;
	}
	return (res);
}

int	divide_into_two2(t_stack *stack, int mid)
{
	while (stack->b && find_last_elem(stack->b) > mid)
	{
		if (find_last_elem(stack->a) > mid)
			rrr(stack);
		else
			rrb(stack);
		pa(stack);
	}
	while (find_last_elem(stack->a) > mid)
		rra(stack);
	if (find_last_elem(stack->a) == mid)
		rra(stack);
	while (stack->b)
		pa(stack);
	while (find_last_elem(stack->a) < mid)
		rra(stack);
	return (0);
}

int	divide_into_two3(t_stack *stack, int mid_new, int mid_prev)
{
	while (stack->b && find_last_elem(stack->b) > mid_new)
	{
		if (find_last_elem(stack->a) > mid_new)
			rrr(stack);
		else
			rrb(stack);
		pa(stack);
	}
	while (find_last_elem(stack->a) >= mid_new &&
			find_last_elem(stack->a) < mid_prev)
		rra(stack);
	while (stack->b)
		pa(stack);
	while (find_last_elem(stack->a) < mid_new &&
			find_last_elem(stack->a) > stack->limit)
		rra(stack);
	return (0);
}

int	divide_into_two4(t_stack *stack, int mid_new)
{
	while (stack->b && find_last_elem(stack->b) > mid_new)
	{
		if (find_last_elem(stack->a) > mid_new)
			rrr(stack);
		else
			rrb(stack);
		pa(stack);
	}
	while (find_last_elem(stack->a) >= mid_new &&
			find_last_elem(stack->a) > stack->limit)
		rra(stack);
	while (stack->b)
		pa(stack);
	while (find_last_elem(stack->a) < mid_new &&
			find_last_elem(stack->a) > stack->limit)
		rra(stack);
	stack->mid = mid_new;
	return (0);
}
