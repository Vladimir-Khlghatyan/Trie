SRCS		= ${wildcard ./*.cpp}
OBJS 		= ${SRCS:.cpp=.o}
CC			= c++
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
NAME		= TrieEXE

%.o: %.cpp *.h
			@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
			@echo "$(GREEN) ✔ $(NAME) created!$(DEFAULT)"

all:		${NAME}

clean:
			@${RM} ${OBJS}
			@echo "$(YELLOW) ✔ object files deleted!$(DEFAULT)"

fclean:		clean
			@${RM} ${NAME}
			@echo "$(RED) ✔ executable deleted!$(DEFAULT)"

re:			fclean all

.PHONY:		all clean fclean re

#COLORS
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW 		= \033[1;33m
DEFAULT		= \033[0m