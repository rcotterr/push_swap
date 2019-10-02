# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 11:10:10 by rcotter-          #+#    #+#              #
#    Updated: 2019/06/03 18:26:35 by rcotter-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
NAME1 = push_swap

SRC = instructions.c make_list.c add_instruction1.c add_instruction2.c script.c
SRC1 = ft_alg.c add_quicksort.c quick_sort.c add_quicksort1.c add_bubble.c add_bubble1.c

all: $(NAME) $(NAME1)

$(NAME):
		@make -C libft/
		@gcc -g -c -Wall -Wextra -Werror $(SRC) push_swap.h checker.c
		@gcc -g -Wall -Wextra -Werror -o $(NAME) $(SRC) checker.c -I. libft/libft.a

$(NAME1):
		@gcc -g -c -Wall -Wextra -Werror $(SRC) $(SRC1) push_swap.h push_swap.c
		@gcc -g -Wall -Wextra -Werror -o $(NAME1) $(SRC) $(SRC1) push_swap.c -I. libft/libft.a

debug:
	@gcc -c -Wall -Wextra -Werror $(SRC) $(SRC1) push_swap.h debug.c
	@gcc -Wall -Wextra -Werror -o $(NAME1) $(SRC) $(SRC1) debug.c -I. libft/libft.a

clean:
	@make -C libft/ clean
	@rm -f *.o 
	
fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@rm -f $(NAME1)

re: fclean all