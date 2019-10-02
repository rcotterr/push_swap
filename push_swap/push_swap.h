/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:55:32 by rcotter-          #+#    #+#             */
/*   Updated: 2019/06/03 18:15:57 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct		s_lst
{
	int				data;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_stack
{
	t_lst			*a;
	t_lst			*b;
	int				num_command;
	int				elem;
	int				rotate;
	int				rot;
	int				push;
	int				limit;
	int				mid;
	int				end;
	int				fd;
	int				debug;
}					t_stack;

t_lst				*ft_make_list(char **argv, int *argc);
int					ft_valid(char *str);
t_lst				*ft_listnew(int nb);
void				ft_print_list(t_lst *list);
int					find_middle(t_lst *list, int num);
int					ra(t_stack *stack);
int					rb(t_stack *stack);
int					rr(t_stack *stack);
int					pa(t_stack *stack);
int					pb(t_stack *stack);
int					sa(t_stack *stack);
int					sb(t_stack *stack);
int					ss(t_stack *stack);
int					rra(t_stack *stack);
int					rrb(t_stack *stack);
int					rrr(t_stack *stack);
void				ft_free(t_lst *list);
int					ft_quicksort(int mid, t_stack *stack);
int					check_sort(t_stack *stack);
int					check_sort_part(t_lst *a, int mid);
int					find_min(t_lst *a);
int					find_middle_part(t_stack *stack, int num);
int					sort_part(t_stack *stack, int mid_prev);
int					check_sort_part2(t_lst *a, int mid);
int					divide_into_two1(t_stack *stack, int mid, int rest_elem);
int					divide_into_two2(t_stack *stack, int mid);
int					find_last_elem(t_lst *list);
int					sort_three(t_stack *stack);
int					last_three(t_stack *stack);
int					sorting(t_stack *stack, int rest_elem);
int					divide_into_two3(t_stack *stack, int mid_new, int mid_prev);
int					divide_into_two4(t_stack *stack, int mid_new);
int					ft_alg(t_lst *list, int num);
int					ft_make_two_stacks(t_stack *stack, t_lst *list, int mid);
int					ft_make_one_stack(t_stack *stack);
int					check_after(t_stack *stack, int i);
int					check_before(t_stack *stack, int rot, int j);
t_lst				*script(char *str, int *argc);
int					ft_sort(t_stack *stack, int i);
int					debug(t_stack *stack);

#endif
