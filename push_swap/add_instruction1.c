/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_instruction1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:23:44 by rcotter-          #+#    #+#             */
/*   Updated: 2019/06/04 17:30:57 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack *stack)
{
	t_lst	*first;
	t_lst	*tmp;

	if (!(stack->a && stack->a->next))
		return (0);
	tmp = stack->a;
	first = stack->a;
	stack->a = stack->a->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_listnew(first->data);
	free(first);
	if (stack->fd)
		write(1, "ra\n", 3);
	if (stack->debug)
		debug(stack);
	stack->num_command++;
	return (0);
}

int	rb(t_stack *stack)
{
	t_lst	*first;
	t_lst	*tmp;

	if (!(stack->b && stack->b->next))
		return (0);
	tmp = stack->b;
	first = stack->b;
	stack->b = stack->b->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_listnew(first->data);
	free(first);
	if (stack->fd)
		write(1, "rb\n", 3);
	if (stack->debug)
		debug(stack);
	stack->num_command++;
	return (0);
}

int	rr(t_stack *stack)
{
	t_lst	*first;
	t_lst	*tmp;

	tmp = stack->a;
	first = stack->a;
	stack->a = stack->a->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_listnew(first->data);
	free(first);
	tmp = stack->b;
	if (!(stack->b && stack->b->next))
		return (0);
	first = stack->b;
	stack->b = stack->b->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_listnew(first->data);
	free(first);
	if (stack->fd)
		write(1, "rr\n", 3);
	if (stack->debug)
		debug(stack);
	return (0);
}

int	pa(t_stack *stack)
{
	t_lst	*tmp;
	t_lst	*new;

	if (stack->fd)
		write(1, "pa\n", 3);
	if (stack->debug)
		debug(stack);
	tmp = stack->b;
	if (stack->b)
	{
		new = ft_listnew(tmp->data);
		new->next = stack->a;
		stack->a = new;
		tmp = tmp->next;
		stack->num_command++;
	}
	else
		return (0);
	tmp = stack->b;
	stack->b = stack->b->next;
	free(tmp);
	return (0);
}

int	pb(t_stack *stack)
{
	t_lst	*tmp;
	t_lst	*new;

	if (stack->fd)
		write(1, "pb\n", 3);
	if (stack->debug)
		debug(stack);
	if (!stack->a)
		return (0);
	tmp = stack->a;
	if (stack->b == NULL)
		stack->b = ft_listnew(stack->a->data);
	else
	{
		new = ft_listnew(tmp->data);
		new->next = stack->b;
		stack->b = new;
	}
	stack->a = stack->a->next;
	free(tmp);
	stack->num_command++;
	return (0);
}
