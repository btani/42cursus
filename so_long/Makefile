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
NAME_BONUS = so_long_bonus

GREEN = \033[0;32m
YELLOW = \033[0;33m
PURPLE = \033[0;35m
NO_COLOR = \033[0m

CC = cc

CFLAGS = -Wall -Werror -Wextra -g
MLX_FLAGS = minilibx-linux/libmlx.a -lX11 -lXext -lm

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

SRCS_DIR = ./sources/
SRCS_DIR_BONUS = ./bonus/

SRCS =	$(addprefix $(SRCS_DIR),\
	ft_check_map.c ft_free_mem.c ft_start_game.c ft_close_game.c\
	ft_init_map.c so_long.c ft_input.c ft_render_map.c flood_fill.c)

SRCS_BONUS = $(addprefix $(SRCS_DIR_BONUS),\
	ft_check_map_bonus.c ft_free_mem_bonus.c ft_start_game_bonus.c ft_close_game_bonus.c\
	ft_init_map_bonus.c so_long_bonus.c ft_input_bonus.c ft_render_map_bonus.c)

LIBFT = ./libraries/Libft/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)Sources compilate con successo! $(NO_COLOR)"
	
bonus: $(LIBFT) $(NAME_BONUS)
	
$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX_FLAGS) -o $(NAME_BONUS)
	@echo "$(GREEN)Bonus compilati con successo! $(NO_COLOR)"

$(LIBFT):
	make -C libraries/Libft
	
clean:
	rm -rf $(OBJS) $(OBJS_BONUS)
	make clean -C libraries/Libft
	@echo "$(PURPLE)Objs rimossi con successo! $(NO_COLOR)"

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)
	make fclean -C libraries/Libft
	@echo "$(PURPLE)Srcs rimosse con successo! $(NO_COLOR)"
		
re: fclean all

.PHONY: all clean fclean re
