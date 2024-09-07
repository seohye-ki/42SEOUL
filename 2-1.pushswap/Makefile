# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 15:04:26 by seohyeki          #+#    #+#              #
#    Updated: 2024/02/17 16:11:39 by seohyeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 =	push_swap
BONUS	 =	checker
CFLAGS	 =	-Wall -Wextra -Werror
SRCS 	 =	command_swap.c \
			command_push.c \
			command_reverse.c \
			command_rotate.c \
			push_swap_ft_atoi.c \
			push_swap_ft_split.c \
			push_swap_ft_lst.c \
			push_swap_utils.c \
			stack_init.c
SRCS_MAN =	push_swap.c \
			quick_sort.c \
			sorting.c \
			greedy_find_best.c \
			greedy_push_best.c \
			greedy.c
SRCS_BON =	get_next_line.c \
			get_next_line_utils.c \
			checker_utils_bonus.c \
			checker_bonus.c
OBJS	 =	$(SRCS:.c=.o)
OBJS_MAN =	$(SRCS_MAN:.c=.o)
OBJS_BON =	$(SRCS_BON:.c=.o)

$(NAME) : $(OBJS) $(OBJS_MAN)
	cc $(CFLAGS) -o $@ $^

all : $(NAME) $(BONUS)

bonus : $(BONUS)

$(BONUS) : $(OBJS) $(OBJS_BON)
	cc $(CFLAGS) -o $@ $^

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS) $(OBJS_MAN) $(OBJS_BON)

fclean : clean
	rm -f $(NAME) $(BONUS)

re : 
	make fclean
	make all

.PHONY: all bonus clean fclean re
