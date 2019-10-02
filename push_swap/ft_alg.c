/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:57:49 by rcotter-          #+#    #+#             */
/*   Updated: 2019/06/03 17:54:00 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_sort_with_rot(t_stack *stack, int rot)
{
	t_lst	*check;
	int		j;

	check = stack->a;
	j = stack->rotate - rot;
	while (check && j-- > 0)
	{
		if (check->next && check->data > check->next->data)
			return (1);
		check = check->next;
	}
	check = stack->b;
	j = stack->rotate - rot;
	while (check && j-- > 0)
	{
		if (check->next && check->data < check->next->data)
			return (1);
		check = check->next;
	}
	return (0);
}

int			buble_sort1(t_stack *stack, int i, int *rot)
{
	while (i < stack->rotate)
	{
		if (stack->a->data > stack->a->next->data &&
			stack->b->data < stack->b->next->data)
			ss(stack);
		else if (stack->a->data > stack->a->next->data)
			sa(stack);
		else if (stack->b->data < stack->b->next->data)
			sb(stack);
		if (i < stack->rotate - 1)
		{
			if (check_after(stack, i))
			{
				rr(stack);
				(*rot)++;
			}
			else
				break ;
		}
		i++;
	}
	return (0);
}

int			buble_sort2(t_stack *stack, int i, int *rot)
{
	while (i < stack->rotate)
	{
		if (i < stack->rotate - 1 && *rot > 0)
		{
			if (check_before(stack, *rot, i))
			{
				rrr(stack);
				(*rot)--;
			}
		}
		if (stack->a->data > stack->a->next->data &&
			stack->b->data < stack->b->next->data)
			ss(stack);
		else if (stack->a->data > stack->a->next->data)
			sa(stack);
		else if (stack->b->data < stack->b->next->data)
			sb(stack);
		i++;
	}
	return (0);
}

int			ft_sort(t_stack *stack, int i)
{
	int		rot;

	if (stack->rot)
		i = stack->rot;
	rot = stack->rot;
	buble_sort1(stack, i, &rot);
	if (stack->elem % 2 != 0)
	{
		if (stack->a->next && stack->a->next->next &&
			stack->a->next->data > stack->a->next->next->data)
		{
			ra(stack);
			sa(stack);
			rra(stack);
		}
	}
	buble_sort2(stack, i, &rot);
	stack->rot = rot;
	if (check_sort_with_rot(stack, rot))
		ft_sort(stack, 0);
	else
		while (rot-- > 0)
			rrr(stack);
	return (0);
}
