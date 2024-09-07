NAME	=	harlFilter
SRCS	=	$(wildcard *.cpp)
OBJS	=	$(SRCS:.cpp=.o)
DEPS	=	$(SRCS:.cpp=.d)
CFLAGS	=	-Wall -Wextra -Werror -MMD -MP -std=c++98

all : $(NAME)

$(NAME) : $(OBJS)
	c++ $(CFLAGS) -o $@ $^

-include $(DEPS)

%.o : %.cpp
	c++ $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS) $(DEPS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all
	
.PHONY : all clean fclean re