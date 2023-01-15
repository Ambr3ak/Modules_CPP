CC			= c++ -Wall -Wextra -Werror -std=c++98
RM			= rm -rf
NAME		= ./phonebook
NAME_SHORT	= phonebook

MAIN_INC	= -I includes
INCS		=	includes/Contact.hpp \
				includes/PhoneBook.hpp

SRCS		=	main.cpp \
				Contact.cpp \
				PhoneBook.cpp

OBJS		= $(SRCS:.cpp=.o)

_CLEAR		= \033[0K\r\c
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