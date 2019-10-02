/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bubble.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 21:03:44 by rcotter-          #+#    #+#             */
/*   Updated: 2019/06/04 16:31:52 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_max(t_lst *list)
{
	int		max;

	max = 0;
	while (list)
	{
		if (max < list->data)
			max = list->data;
		list = list->next;
	}
	return (max);
}

t_lst		*copy_list(t_lst *list)
{
	t_lst	*tmp;
	t_lst	*first;

	tmp = ft_listnew(list->data);
	list = list->next;
	first = tmp;
	while (list)
	{
		first = ft_listnew(list->data);
		first->next = tmp;
		tmp = first;
		list = list->next;
	}
	return (first);
}

int			find_min_make_max(t_lst *tmp, int max)
{
	t_lst	*first;
	int		min;

	min = max;
	first = tmp;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	tmp = first;
	while (first)
	{
		if (first->data == min)
			first->data = max;
		first = first->next;
	}
	return (min);
}

int			find_middle_part(t_stack *stack, int num)
{
	int		i;
	int		min;
	int		max;
	t_lst	*tmp;

	i = 0;
	max = find_max(stack->a);
	tmp = copy_list(stack->a);
	if (num % 2 != 0)
		num++;
	while (i < num / 2)
	{
		min = find_min_make_max(tmp, max);
		if (min <= stack->limit)
			continue;
		i++;
	}
	ft_free(tmp);
	return (min);
}

int			find_middle(t_lst *list, int num)
{
	int		i;
	int		min;
	int		max;
	t_lst	*tmp;

	i = 0;
	max = find_max(list);
	tmp = copy_list(list);
	while (i < num / 2)
	{
		min = find_min_make_max(tmp, max);
		i++;
	}
	ft_free(tmp);
	return (min);
}
