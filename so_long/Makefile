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
#NAME_BONUS = so_long_bonus

GREEN = \033[0;32m
YELLOW = \033[0;33m
PURPLE = \033[0;35m
NO_COLOR = \033[0m

CC = cc

CFLAGS = -Wall -Werror -Wextra -g
MLX_FLAGS = minilibx-linux/libmlx.a -lX11 -lXext -lm

#OBJS = $(SRCS:.c=.o)
#OBJS_BONUS = $(SRCS_BONUS:.c=.o)

SRCS_DIR = ./sources/

SRCS =	$(addprefix $(SRCS_DIR),\
	ft_check_map.c ft_free_mem.c ft_start_game.c ft_close_game.c\
	ft_init_map.c so_long.c)

#SRCS_BONUS =

LIBFT = ./libraries/Libft/libft.a

all: $(LIBFT) $(NAME)

$(NAME):
	$(CC) $(SRCS) $(LIBFT) $(CFLAGS) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)Compilato con successo $(NO_COLOR)"
	
#$(NAME_BONUS):
#	$(CC) &(OBJS_BONUS) $(LIBFT) $(CFLAGS) $(MLX_FLAGS) -o $(NAME)
#	@echo "$(GREEN)Bonus compilati con successo $(NO_COLOR)"

#$(LIBFT):
#	make -C libraries/Libft
	
clean:
	make clean -C libraries/Libft
	@echo "$(PURPLE)Libft pulita $(NO_COLOR)"

fclean: clean
	rm -rf $(NAME)
	#make fclean -C libraries/Libft
	@echo "$(PURPLE)Srcs pulite con successo $(NO_COLOR)"
		
re: fclean all

.PHONY: all clean fclean re
