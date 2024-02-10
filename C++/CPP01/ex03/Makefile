# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btani <btani@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 18:21:53 by btani             #+#    #+#              #
#    Updated: 2023/12/06 18:47:20 by btani            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

DEF_COLOR = \033[0;39m
GREEN = \033[1;92m
WHITE = \033[1;97m

NAME = weapon

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRC =  main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
	@echo "Rule '${GREEN}all${DEF_COLOR}' for mandatory ${NAME} executed successfully!"

all: $(NAME)

clean:
	$(RM) $(OBJ)
	@echo "Rule '${GREEN}clean${DEF_COLOR}' for ${NAME} executed successfully!"

fclean: clean
	$(RM) $(NAME)
	@echo "Rule '${GREEN}fclean${DEF_COLOR}' for ${NAME} executed successfully!"

re: fclean
	make all
	@echo "Rule '${GREEN}re${DEF_COLOR}' for ${NAME} executed successfully!"

.PHONY: clean fclean re
