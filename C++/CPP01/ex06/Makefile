# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btani <btani@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 15:33:40 by btani             #+#    #+#              #
#    Updated: 2024/01/19 14:55:47 by btani            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

DEF_COLOR = \033[0;39m
GREEN = \033[1;92m
WHITE = \033[1;97m

NAME = harlFilter

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRC =  main.cpp Harl.cpp

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
