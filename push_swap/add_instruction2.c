/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_instruction2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:26:31 by rcotter-          #+#    #+#             */
/*   Updated: 2019/06/04 17:30:56 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack *stack)
{
	int	c;

	if (!(stack->a && stack->a->next))
		return (0);
	c = stack->a->data;
	stack->a->data = stack->a->next->data;
	stack->a->next->data = c;
	if (stack->fd)
		write(1, "sa\n", 3);
	if (stack->debug)
		debug(stack);
	stack->num_command++;
	return (0);
}

int	sb(t_stack *stack)
{
	int	c;

	if (!(stack->b && stack->b->next))
		return (0);
	c = stack->b->data;
	stack->b->data = stack->b->next->data;
	stack->b->next->data = c;
	if (stack->fd)
		write(1, "sb\n", 3);
	if (stack->debug)
		debug(stack);
	stack->num_command++;
	return (0);
}

int	ss(t_stack *stack)
{
	int	c;

	if (!(stack->a && stack->a->next))
		return (0);
	c = stack->a->data;
	stack->a->data = stack->a->next->data;
	stack->a->next->data = c;
	if (!(stack->b && stack->b->next))
		return (0);
	c = stack->b->data;
	stack->b->data = stack->b->next->data;
	stack->b->next->data = c;
	if (stack->fd)
		write(1, "ss\n", 3);
	if (stack->debug)
		debug(stack);
	stack->num_command++;
	return (0);
}

int	rra(t_stack *stack)
{
	t_lst	*last;
	t_lst	*tmp;
	t_lst	*new;

	tmp = stack->a;
	while (tmp && tmp->next)
		tmp = tmp->next;
	last = tmp;
	tmp = stack->a;
	while (tmp && tmp->next && tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
	new = ft_listnew(last->data);
	new->next = stack->a;
	stack->a = new;
	free(last);
	if (stack->fd)
		write(1, "rra\n", 4);
	if (stack->debug)
		debug(stack);
	stack->num_command++;
	return (0);
}

int	rrb(t_stack *stack)
{
	t_lst *last;
	t_lst *tmp;
	t_lst *new;

	tmp = stack->b;
	if (!(tmp && tmp->next))
		return (0);
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
	if (stack->fd)
		write(1, "rrb\n", 4);
	if (stack->debug)
		debug(stack);
	stack->num_command++;
	return (0);
}
