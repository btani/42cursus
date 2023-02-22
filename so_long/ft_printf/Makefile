# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btani <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 17:40:53 by btani             #+#    #+#              #
#    Updated: 2022/10/26 17:51:59 by btani            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
AR = ar rcs
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = ft_countdec.c ft_printunsnbr.c ft_countdec_uns.c\
	ft_printhexa1.c ft_printvoidptr.c ft_counthexa.c\
	ft_printchar.c ft_printnbr.c ft_printhexa.c\
	ft_printf.c ft_printstr.c ft_putnbr_uns_fd.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./Libft
	cp Libft/libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c -I. $< -o $@

clean:
	$(MAKE) clean -C ./Libft
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./Libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

