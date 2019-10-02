/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_quicksort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 17:18:05 by rcotter-          #+#    #+#             */
/*   Updated: 2019/06/03 17:47:48 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_less(t_stack *stack, int rest_elem, int mid)
{
	t_lst	*tmp;

	tmp = stack->a;
	while (rest_elem-- && tmp)
	{
		if (tmp->data < mid)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	divide_into_two1(t_stack *stack, int mid, int rest_elem)
{
	while (stack->a->data != mid)
	{
		if (stack->a->data > mid)
			pb(stack);
		else
			ra(stack);
		rest_elem--;
	}
	if (stack->a->data == mid)
	{
		ra(stack);
		rest_elem--;
	}
	while (rest_elem)
	{
		if (stack->a->data < mid)
			pb(stack);
		else
		{
			if (is_less(stack, rest_elem, mid))
				ra(stack);
		}
		rest_elem--;
	}
	return (0);
}

int	sort_three(t_stack *stack)
{
	if (stack->a && stack->a->next && stack->a->data > stack->a->next->data)
		sa(stack);
	ra(stack);
	if (stack->a && stack->a->next && stack->a->data > stack->a->next->data)
		sa(stack);
	if (stack->a && find_last_elem(stack->a) > stack->a->data)
	{
		rra(stack);
		sa(stack);
	}
	while (stack->a && stack->a->data <= stack->mid)
		ra(stack);
	stack->limit = stack->mid;
	return (0);
}

int	last_three(t_stack *stack)
{
	if (stack->a && stack->a->next && stack->a->data > stack->a->next->data)
		sa(stack);
	ra(stack);
	if (stack->a && stack->a->next && stack->a->data > stack->a->next->data)
		sa(stack);
	if (stack->a && find_last_elem(stack->a) > stack->a->data)
	{
		rra(stack);
		sa(stack);
	}
	while (stack->a && stack->a->data > stack->limit)
		ra(stack);
	return (0);
}

int	sorting(t_stack *stack, int rest_elem)
{
	if (rest_elem < 3)
	{
		if (stack->a && stack->a->next && stack->a->data > stack->a->next->data)
			sa(stack);
	}
	if (rest_elem == 3)
	{
		if (stack->a && stack->a->next && stack->a->data > stack->a->next->data)
			sa(stack);
		ra(stack);
		if (stack->a && stack->a->next && stack->a->data > stack->a->next->data)
			sa(stack);
		if (stack->a && find_last_elem(stack->a) > stack->a->data)
		{
			rra(stack);
			sa(stack);
		}
	}
	return (0);
}
