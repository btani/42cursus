# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btani <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 16:54:12 by btani             #+#    #+#              #
#    Updated: 2023/02/10 17:02:41 by btani            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = 

OBJS = $(SRCS:.c=.o)

MLX = ../minilibx-linux/libmlx_Linux.a -lX11 -lXext -lm

PRINTF = ./ft_printf/libftprintf.a

GNL = ./get_next_line   ## fare make file gnl

all: $(NAME)

GREEN = \033[0;32m
YELLOW = \033[0;33m
PURPLE = \033[0;35m
NO_COLOR = \033[0m

%.o:%.c
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(GNL) $(MLX) -o $(NAME)
	@echo "$(GREEN)Compilato con successo $(NO_COLOR)"

$(NAME): $(OBJS)

clean:
	rm -rf $(OBJS)
	make -C ft_printf get_next_line clean

fclean: clean
	rm -rf $(NAME)
	make -C ft_printf get_next_line fclean
make:
	make -C ft_printf get_next_line
		
re: fclean all
