CC			= c++ -Wall -Wextra -Werror -g -fsanitize=address -std=c++98
RM			= rm -rf
NAME		= ./RPN
NAME_SHORT	= RPN

MAIN_INC	= -I includes
INCS		=	RPN.hpp

SRCS		=	main.cpp \
				RPN.cpp

OBJS		= $(SRCS:.cpp=.o)

_OK			= \033[32mOK\033[0m
_BOLD		= \033[1m

%.o			: %.cpp
			$(CC) $(MAIN_INC) -c $< -o $@

all			: $(NAME)

$(NAME)		: $(OBJS) $(INCS)
			@$(CC) $(OBJS) $(MAIN_INC) -o $(NAME)
			@echo "$(_OK) $(NAME_SHORT) $(_BOLD)compiled"

clean		:
			@$(RM) $(OBJS)

fclean		: clean
			@$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re