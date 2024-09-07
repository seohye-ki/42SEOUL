# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 18:38:57 by seohyeki          #+#    #+#              #
#    Updated: 2024/05/06 15:43:57 by sumilee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
LIBFT = libft.a
LIBFT_DIR = libft
MLX = libmlx.a
MLX_DIR = .mlx
INC_DIR = include
P_SRCS = parse/parsing.c \
		 parse/parse_info.c \
		 parse/ft_lst_trim.c \
		 parse/parse_map_utils.c \
		 parse/parse_map.c \
		 parse/map_valid_check.c \
		 parse/init.c \
		 parse/info_to_img.c
E_SRCS = main.c \
		 exec/raycasting.c \
		 exec/rendering.c \
		 exec/key_press.c \
		 exec/util.c \
		 exec/mlx_util.c
P_OBJS = $(P_SRCS:.c=.o)
E_OBJS = $(E_SRCS:.c=.o)
P_DEPS = $(P_SRCS:.c=.d)
E_DEPS = $(E_SRCS:.c=.d)
A_OBJS = $(P_OBJS) $(E_OBJS)
A_DEPS = $(P_DEPS) $(E_DEPS)
CFLAGS = -Wall -Wextra -Werror -MMD -MP
LIBINC = -lmlx -L$(MLX_DIR) -lft -L$(LIBFT_DIR) -framework OpenGL -framework Appkit

all : $(NAME)

$(NAME) : $(A_OBJS)
	make -C $(MLX_DIR)
	make -C $(LIBFT_DIR)
	cc $(CFLAGS) $(LIBINC) -o $@ $^

-include $(A_DEPS)

%.o : %.c
	cc -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(INC_DIR) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(A_OBJS) $(A_DEPS)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all
	
.PHONY : all clean fclean re
