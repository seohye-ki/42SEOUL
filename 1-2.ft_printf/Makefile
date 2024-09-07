# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 21:29:03 by seohyeki          #+#    #+#              #
#    Updated: 2023/11/11 17:32:36 by seohyeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
SRCS=ft_printf.c \
		ft_strlen.c \
		print_char.c \
		print_demical.c \
		print_hex.c \
		print_ptr.c \
		print_str.c \
		print_unsigned_demical.c

OBJS=$(SRCS:.c=.o)
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)
	
$(NAME) : $(OBJS)
	ar -cr $@ $^

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : 
	make fclean
	make all

.PHONY: all clean fclean re