/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:40:21 by rcotter-          #+#    #+#             */
/*   Updated: 2019/06/04 17:04:20 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	for_rrr(t_stack *stack, t_lst *last, t_lst *tmp, t_lst *new)
{
	tmp = stack->b;
	if (tmp && tmp->next)
	{
		while (tmp->next)
			tmp = tmp->next;
		last = tmp;
		tmp = stack->b;
		while (tmp->next != last)
			tmp = tmp->next;
		tmp->next = NULL;
		new = ft_listnew(last->data);
		new->next = stack->b;
		stack->b = new;
		free(last);
	}
	return (0);
}

int	rrr(t_stack *stack)
{
	t_lst	*last;
	t_lst	*tmp;
	t_lst	*new;

	tmp = stack->a;
	while (tmp->next)
		tmp = tmp->next;
	last = tmp;
	tmp = stack->a;
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
	new = ft_listnew(last->data);
	new->next = stack->a;
	stack->a = new;
	free(last);
	for_rrr(stack, last, tmp, new);
	if (stack->fd)
		write(1, "rrr\n", 4);
	if (stack->debug)
		debug(stack);
	stack->num_command++;
	return (0);
}

int	check_sort(t_stack *stack)
{
	t_lst	*check;

	check = stack->a;
	while (check)
	{
		if (check->next && check->data > check->next->data)
			return (1);
		check = check->next;
	}
	check = stack->b;
	while (check)
	{
		if (check->next && check->data < check->next->data)
			return (1);
		check = check->next;
	}
	return (0);
}

int	check_sort_part(t_lst *a, int mid)
{
	t_lst	*tmp;

	tmp = a;
	while (tmp && tmp->data < mid)
	{
		if (tmp->next && tmp->data > tmp->next->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_sort_part2(t_lst *a, int mid)
{
	t_lst	*tmp;

	tmp = a;
	while (tmp && tmp->data != mid)
	{
		if (tmp->next && tmp->data > tmp->next->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
