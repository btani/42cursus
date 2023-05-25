# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btani <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 17:58:22 by btani             #+#    #+#              #
#    Updated: 2023/03/25 17:58:54 by btani            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

GREEN = \033[0;32m
YELLOW = \033[0;33m
PURPLE = \033[0;35m
NO_COLOR = \033[0m

SRCS_DIR = ./src/

SRCS = $(addprefix $(SRCS_DIR),\
		check_algo.c check.c find_algo.c free.c\
		mechanicalturk.c moves_ab_algo.c moves_ba_algo.c\
		op_ab_algo.c op_ba_algo.c operation_a.c operation_b.c\
		operation_double.c push_swap.c sort_algo.c sort.c\
		utils_lst.c utils_lst2.c)

OBJS = $(SRCS:.c=.o)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I Libft -I src
	@printf "Compilo... %-9.0s\r" $@

LIBFT = ./Libft/libft.a

all: lib $(NAME)

lib: 
	make bonus -C ./Libft

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)
	@echo "$(GREEN)Sources compilate! $(NO_COLOR)"
	
clean:
	rm -rf $(OBJS)
#	make clean -C Libft
	@echo "$(PURPLE)Objs rimossi! $(NO_COLOR)"
	
fclean: clean
	rm -rf $(NAME)
#	make fclean -C Libft
	@echo "$(PURPLE)Srcs rimosse! $(NO_COLOR)"
	
re: fclean all

.PHONY: all clean fclean re