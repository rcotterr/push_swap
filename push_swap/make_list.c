/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 18:48:33 by rcotter-          #+#    #+#             */
/*   Updated: 2019/06/03 17:54:25 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst		*ft_listnew(int nb)
{
	t_lst	*lst;

	if (!(lst = (t_lst *)(malloc(sizeof(t_lst)))))
	{
		free(lst);
		return (NULL);
	}
	lst->data = nb;
	lst->next = NULL;
	return (lst);
}

int			ft_valid(char *str)
{
	int		i;

	i = 0;
	if (!str[i])
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	if (str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (!str[i])
		return (1);
	else
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	return (0);
}

int			check_double(t_lst *lst)
{
	t_lst	*tmp;
	t_lst	*cmp;
	int		i;

	tmp = lst;
	while (tmp)
	{
		i = tmp->data;
		cmp = tmp->next;
		while (cmp)
		{
			if (tmp->data == cmp->data)
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			cmp = cmp->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

t_lst		*ft_make_list(char **argv, int *argc)
{
	t_lst	*lst;
	t_lst	*first;
	int		i;
	int		count;

	i = *argc - 1;
	count = *argc;
	if (*argc == 2)
		lst = script(argv[1], argc);
	else
	{
		while (--count > 0)
		{
			if (!ft_valid(argv[count]))
				return (0);
			first = lst;
			lst = ft_listnew(ft_atoi(argv[count]));
			lst->next = first;
			if (count == i)
				lst->next = NULL;
		}
	}
	check_double(lst);
	return (lst);
}

void		ft_print_list(t_lst *list)
{
	t_lst	*tmp;

	tmp = list;
	while (tmp)
	{
		ft_putnbr(tmp->data);
		write(1, " ", 1);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}
