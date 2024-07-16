NAME	= megaphone
SRCS	= megaphone.cpp
OBJS	= $(SRCS:.cpp=.o)
CC	= c++
CPPFLAGS= -Wall -Werror -Wextra -std=c++98 #-g

all:	$(NAME)

$(NAME):$(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o:%.cpp
	$(CC) -c $(CPPFLAGS) $^ -o $@

clean:
	rm $(OBJS)

fclean:	clean
	rm $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
