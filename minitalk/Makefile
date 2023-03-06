# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btani <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 14:34:23 by btani             #+#    #+#              #
#    Updated: 2023/01/12 14:38:57 by btani            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = ft_server.c

CLIENT = ft_client.c

SERVER_BONUS = ft_server_bonus.c

CLIENT_BONUS = ft_client_bonus.c


GCC = cc

FLAGS = -Wall -Werror -Wextra -g


NAME =  minitalk

NAME_SERVER = server

NAME_CLIENT = client

NAME_SERVER_BONUS = server_bonus

NAME_CLIENT_BONUS = client_bonus


SRC_SERVER = $(SERVER)

SRC_CLIENT = $(CLIENT)

SRC_SERVER_BONUS = $(SERVER_BONUS)

SRC_CLIENT_BONUS = $(CLIENT_BONUS)


OBJ_SERVER = $(SRC_SERVER:.c=.o)

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)

OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

GREEN = \033[0;32m
YELLOW = \033[0;33m
PURPLE = \033[0;35m
NO_COLOR = \033[0m

all: $(NAME)

%.o: %.c
	$(GCC) $(FLAGS) $< -o $@ -I Libft/ft_printf.h Libft/libft.a

$(NAME):  ft_server ft_client

ft_server: make $(OBJ_SERVER) 
	$(GCC) $(FLAGS) $(SRC_SERVER) -o $(NAME_SERVER) Libft/libft.a
	@echo "$(GREEN)ft_server compilato con successo $(NO_COLOR)"
	
ft_client: $(OBJ_CLIENT)
	$(GCC) $(FLAGS) $(SRC_CLIENT) -o $(NAME_CLIENT) Libft/libft.a
	@echo "$(GREEN)ft_client compilato con successo $(NO_COLOR)"
	
ft_server_bonus:  $(OBJ_SERVER_BONUS) 
	$(GCC) $(FLAGS) $(SRC_SERVER_BONUS) -o $(NAME_SERVER_BONUS) Libft/libft.a
	@echo "$(GREEN)ft_server compilato con successo $(NO_COLOR)"
	
ft_client_bonus: make $(OBJ_CLIENT_BONUS)
	$(GCC) $(FLAGS) $(SRC_CLIENT_BONUS) -o $(NAME_CLIENT_BONUS) Libft/libft.a
	@echo "$(GREEN)ft_client compilato con successo $(NO_COLOR)"
	
clean:
	rm -rf $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)
	make -C Libft clean
	@echo "$(PURPLE)objs rimossi!\n $(NO_COLOR)"

fclean: clean
	rm -rf $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
	make -C Libft fclean
	@echo "$(PURPLE)client, server e bonus rimossi!\n $(NO_COLOR)"
make:
	make -C Libft
	
bonus:	make ft_server_bonus ft_client_bonus
	@echo "$(GREEN)bonus compilati con successo $(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean re
