/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:34:56 by rcotter-          #+#    #+#             */
/*   Updated: 2019/06/03 18:48:30 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_instruction(t_stack *stack, char *line)
{
	if (strcmp(line, "sa") == 0)
		sa(stack);
	else if (strcmp(line, "sb") == 0)
		sb(stack);
	else if (strcmp(line, "ss") == 0)
		ss(stack);
	else if (strcmp(line, "pa") == 0)
		pa(stack);
	else if (strcmp(line, "pb") == 0)
		pb(stack);
	else if (strcmp(line, "ra") == 0)
		ra(stack);
	else if (strcmp(line, "rb") == 0)
		rb(stack);
	else if (strcmp(line, "rr") == 0)
		rr(stack);
	else if (strcmp(line, "rra") == 0)
		rra(stack);
	else if (strcmp(line, "rrb") == 0)
		rrb(stack);
	else if (strcmp(line, "rrr") == 0)
		rrr(stack);
	else
		exit(write(1, "Error\n", 6));
	return (0);
}

int	main(int argc, char **argv)
{
	char	*line;
	t_stack	stack;

	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	stack.fd = 0;
	stack.debug = 0;
	stack.a = ft_make_list(argv, &argc);
	stack.b = NULL;
	stack.push = 0;
	while ((get_next_line(stack.fd, &line)) == 1)
	{
		make_instruction(&stack, line);
		free(line);
	}
	if (check_sort(&stack) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free(stack.a);
	return (0);
}
