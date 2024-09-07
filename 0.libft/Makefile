# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 16:47:02 by seohyeki          #+#    #+#              #
#    Updated: 2023/11/09 19:54:31 by seohyeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRCS_MAN=ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
SRCS_BON=ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJS_MAN=$(SRCS_MAN:.c=.o)
OBJS_BON=$(SRCS_BON:.c=.o)
CFLAGS=-Wall -Wextra -Werror

ifdef WITH_BONUS
	OBJS = $(OBJS_MAN) $(OBJS_BON)
else
	OBJS = $(OBJS_MAN)
endif

all: $(NAME)
	
$(NAME) : $(OBJS)
	ar -crs $@ $^

bonus :
	@make WITH_BONUS=1 all

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJS_MAN) $(OBJS_BON)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re