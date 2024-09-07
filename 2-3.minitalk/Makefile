# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 18:38:57 by seohyeki          #+#    #+#              #
#    Updated: 2024/03/06 14:06:36 by seohyeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
CLIENT = client
LIBFT = libft.a
LIBFT_DIR = libft
S_SRCS_M = minitalk_server.c
C_SRCS_M = minitalk_client.c
S_SRCS_B = minitalk_server_bonus.c
C_SRCS_B = minitalk_client_bonus.c
S_OBJS_M = $(S_SRCS_M:.c=.o)
C_OBJS_M = $(C_SRCS_M:.c=.o)
S_OBJS_B = $(S_SRCS_B:.c=.o)
C_OBJS_B = $(C_SRCS_B:.c=.o)
A_OBJS = $(S_OBJS_M) $(C_OBJS_M) $(S_OBJS_B) $(C_OBJS_B)
CFLAGS = -Wall -Wextra -Werror

ifndef BONUS
	S_OBJS = $(S_OBJS_M)
	C_OBJS = $(C_OBJS_M)
else
	S_OBJS = $(S_OBJS_B)
	C_OBJS = $(C_OBJS_B)
endif

all : $(NAME) $(CLIENT)

$(NAME) : $(S_OBJS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) ./
	cc $(CFLAGS) $(LIBFT) -o $@ $^

$(CLIENT) : $(C_OBJS)
	cc $(CFLAGS) $(LIBFT) -o $@ $^

%.o : %.c
	cc $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean :
	rm -f $(A_OBJS)
	make fclean -C $(LIBFT_DIR)

fclean : clean
	rm -f $(NAME) $(CLIENT) $(LIBFT)

re :
	make fclean
	make all

bonus :
	make BONUS=1 all

.PHONY : all clean fclean re bonus