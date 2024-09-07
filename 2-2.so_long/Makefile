# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 18:38:57 by seohyeki          #+#    #+#              #
#    Updated: 2024/02/17 18:38:28 by seohyeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = libft.a
LIBFT_DIR = libft
MLX_DIR = .mlx
C_SRCS = so_long.c \
		 so_long_utils.c \
		 so_long_read_map.c \
		 so_long_check_map.c \
		 so_long_check_path.c
M_SRCS = so_long_draw_map.c \
		 so_long_press_key.c
B_SRCS = so_long_draw_map_bonus.c \
		 so_long_press_key_bonus.c
C_OBJS = $(C_SRCS:.c=.o)
M_OBJS = $(M_SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)
A_OBJS = $(C_OBJS) $(M_OBJS) $(B_OBJS)
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -lz

ifndef BONUS
	OBJS = $(C_OBJS) $(M_OBJS)
else
	OBJS = $(C_OBJS) $(B_OBJS)
endif
	
all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) ./
	cc -L$(MLX_DIR) $(CFLAGS) $(MLXFLAGS) $(LIBFT) -o $@ $^

%.o : %.c
	cc $(CFLAGS) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean :
	rm -f $(A_OBJS)
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean : clean
	rm -f $(NAME) $(LIBFT)

re :
	make fclean
	make all

bonus :
	make BONUS=1 all
	
.PHONY : all clean fclean re