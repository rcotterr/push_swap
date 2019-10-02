/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:10:10 by rcotter-          #+#    #+#             */
/*   Updated: 2019/06/04 16:44:25 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_alg(t_lst *list, int num)
{
	int		mid;
	t_stack	stack;
	int		i;

	i = 0;
	stack.num_command = 0;
	stack.b = NULL;
	stack.elem = num;
	stack.rotate = stack.elem / 2 - 1;
	stack.rot = 0;
	stack.push = 1;
	stack.debug = 0;
	stack.fd = 1;
	mid = find_middle(list, num);
	ft_make_two_stacks(&stack, list, mid);
	ft_sort(&stack, i);
	ft_make_one_stack(&stack);
	ft_free(stack.a);
	return (0);
}

int			ft_alg1(t_lst *list, int num)
{
	int		mid;
	t_stack	stack;

	stack.num_command = 0;
	stack.b = NULL;
	stack.elem = num;
	stack.a = list;
	stack.debug = 0;
	stack.limit = find_min(stack.a) - 1;
	mid = find_middle(list, num);
	stack.mid = mid;
	stack.fd = 1;
	ft_quicksort(mid, &stack);
	if (check_sort(&stack))
		ft_alg(stack.a, num);
	else
		ft_free(stack.a);
	return (0);
}

int			main(int argc, char **argv)
{
	t_lst	*list;
	t_stack	stack;

	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	list = ft_make_list(argv, &argc);
	stack.a = list;
	stack.b = NULL;
	if (!check_sort(&stack))
	{
		ft_free(stack.a);
		return (0);
	}
	if (argc < 50)
		ft_alg(list, argc - 1);
	else
		ft_alg1(list, argc - 1);
	return (0);
}
