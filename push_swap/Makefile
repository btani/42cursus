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

OBJS = $(SRCS:.c=.o)

SRCS = operation_2.c operation.c push_swap.c utils_lst.c

LIBFT = ./Libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "Sources compilate"
	
clean:
	rm - rf $(OBJS)
	make clean -C ./Libft
	@echo "Objs rimossi"
	
fclean: clean
	rm - rf $(NAME)
	make fclean -C ./Libft
	@echo "Srcs rimosse"
	
re: fclean all

.PHONY: all clean fclean re
