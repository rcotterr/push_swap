/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   script.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 21:41:30 by rcotter-          #+#    #+#             */
/*   Updated: 2019/06/03 18:02:21 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			for_script(char *str, int i, int c, t_lst **lst)
{
	t_lst	*first;

	while (i >= 0)
	{
		if (str[i] >= '0' && str[i] <= '9')
			while (str[i] >= '0' && str[i] <= '9' && i > 0)
				i--;
		else
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		if (str[i] == '-' && i > 0)
			i--;
		first = (*lst);
		(*lst) = ft_listnew(ft_atoi(&str[i]));
		(*lst)->next = first;
		if (c++ == 0)
			(*lst)->next = NULL;
		if (str[i] == ' ')
			i--;
		if (i == 0)
			break ;
	}
	return (c);
}

t_lst		*script(char *str, int *argc)
{
	int		i;
	t_lst	*lst;
	int		c;

	i = ft_strlen(str) - 1;
	lst = NULL;
	c = for_script(str, i, 0, &lst);
	*argc = c + 1;
	return (lst);
}

int			debug(t_stack *stack)
{
	t_lst	*tmp;

	tmp = stack->a;
	write(1, "--------\n", 9);
	write(1, "stack->a: ", 10);
	ft_print_list(stack->a);
	write(1, "stack->b: ", 10);
	ft_print_list(stack->b);
	return (0);
}

void		ft_free(t_lst *list)
{
	t_lst	*tmp;

	if (!list)
		return ;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}
