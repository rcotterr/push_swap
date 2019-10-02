/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 19:06:00 by rcotter-          #+#    #+#             */
/*   Updated: 2019/05/26 21:13:12 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_before_middle(t_lst *a, int mid)
{
	int		rest_elem;
	t_lst	*tmp;

	tmp = a;
	rest_elem = 0;
	while (tmp && tmp->data != mid)
	{
		rest_elem++;
		tmp = tmp->next;
	}
	return (rest_elem);
}

int	find_end(t_lst *list, int mid_prev)
{
	t_lst	*tmp;
	int		res;

	res = 0;
	tmp = list;
	while (tmp && tmp->data > mid_prev)
		tmp = tmp->next;
	if (tmp)
		res = tmp->data;
	return (res);
}

int	sort_part2(t_stack *stack, int mid_prev)
{
	int	mid_new;
	int	rest_elem;

	stack->end = find_end(stack->a, mid_prev);
	rest_elem = count_before_middle(stack->a, stack->end);
	if (rest_elem < 3)
	{
		if (stack->a && stack->a->next && stack->a->data > stack->a->next->data)
			sa(stack);
		stack->limit = mid_prev;
		return (0);
	}
	mid_new = find_middle_part(stack, rest_elem);
	divide_into_two1(stack, mid_new, rest_elem);
	divide_into_two4(stack, mid_new);
	while (stack->limit < stack->mid &&
			count_before_middle(stack->a, stack->mid) > 3)
		sort_part(stack, stack->mid);
	sort_three(stack);
	return (0);
}

int	sort_part(t_stack *stack, int mid_prev)
{
	int	mid_new;
	int	rest_elem;

	rest_elem = count_before_middle(stack->a, mid_prev);
	if (rest_elem <= 3)
	{
		sorting(stack, rest_elem);
		return (0);
	}
	mid_new = find_middle_part(stack, rest_elem);
	divide_into_two1(stack, mid_new, rest_elem);
	divide_into_two3(stack, mid_new, mid_prev);
	while (check_sort_part(stack->a, mid_new) && mid_prev <= stack->mid)
		sort_part(stack, mid_new);
	stack->limit = mid_new;
	while (stack->a && stack->a->data <= mid_new)
		ra(stack);
	return (0);
}

int	ft_quicksort(int mid, t_stack *stack)
{
	int	rest_elem;

	rest_elem = stack->elem;
	divide_into_two1(stack, mid, rest_elem);
	divide_into_two2(stack, mid);
	if (check_sort(stack))
	{
		while (stack->limit < stack->mid &&
				count_before_middle(stack->a, stack->mid) > 3)
			sort_part(stack, stack->mid);
		sort_three(stack);
		while (stack->a->data > stack->limit &&
				count_before_middle(stack->a, stack->end) > 3)
			sort_part2(stack, mid);
		last_three(stack);
	}
	return (0);
}
