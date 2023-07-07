# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btani <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 17:05:12 by btani             #+#    #+#              #
#    Updated: 2023/06/05 17:05:14 by btani            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

CC = cc

CFLAGS = -Wall -Werror -Wextra

GREEN = \033[0;32m
YELLOW = \033[0;33m
PURPLE = \033[0;35m
NO_COLOR = \033[0m

SRCS_DIR = ./src/

SRCS = $(addprefix $(SRCS_DIR),\
		readme.c)

OBJS = $(SRCS:.c=.o)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I Libft -I src
	@printf "Compilo... %-9.0s\r" $@

LIBFT = ./Libft/libft.a

all: $(NAME)

lib: 
	make bonus -C ./Libft

$(NAME): lib $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)
	@echo "$(GREEN)Sources compilate! $(NO_COLOR)"
	
clean:
	rm -rf $(OBJS)
	make clean -C Libft
	@echo "$(PURPLE)Objs rimossi! $(NO_COLOR)"
	
fclean: clean
	rm -rf $(NAME)
	make fclean -C Libft
	@echo "$(PURPLE)Srcs rimosse! $(NO_COLOR)"
	
re: fclean all

.PHONY: all clean fclean re
