NAME		= g

CC			= gcc
SRCS		= main.cpp \
		get_next_line_bonus.c \
		get_next_line_utils_bonus

HEADERS		= Bureaucrat.h

CC_FLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -f

OBJS = $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(HEADERS)
	$(CC) $(SRCS) $(CC_FLAGS) -o $(NAME)

%.o:		%.cpp $(HEADERS)
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re