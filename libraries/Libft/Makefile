# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btani <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 22:26:00 by btani             #+#    #+#              #
#    Updated: 2022/10/22 16:35:34 by btani            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AR = ar rcs

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
	ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c\
	ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c\
	ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c\
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c\
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c\
	ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
	ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c ft_printf.c\
	ft_countdec.c ft_printunsnbr.c ft_countdec_uns.c ft_printhexa1.c\
	ft_printvoidptr.c ft_counthexa.c ft_printchar.c ft_printnbr.c\
	ft_printhexa.c ft_printf.c ft_printstr.c ft_putnbr_uns_fd.c\
	get_next_line.c

SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
	ft_lstmap.c

OBJ = $(SRCS:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c -I. $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:  $(OBJ_BONUS) 
	$(AR) $(NAME) $(OBJ_BONUS)

.PHONY: bonus all clean fclean re
