NAME = RPN

SRCS =	RPN.cpp \
		main.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++

%.o: %.cpp
	${CC} ${CPPFLAGS} -c $< -o $@

CPPFLAGS = -std=c++98 -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	@echo -n "\e[?25lCompiling $(NAME)..."
	@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo
	@echo "$(NAME) compiled !\e[?25h"

clean:
	@rm -f $(OBJS);
	@echo "Object files deleted !"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted !"

re: fclean all

.PHONY: all clean fclean re