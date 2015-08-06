# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/07 15:13:04 by cdeniau           #+#    #+#              #
#    Updated: 2015/06/12 15:57:38 by cdeniau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc -g -Wall -Wextra -Werror

SRC = ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strlen.c \
	  ft_strdup.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strlcat.c \
	  ft_strtoupper.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_strucmp.c \
	  ft_atoi.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isspace.c \
	  ft_isprint.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_strdel.c \
	  ft_strsplit.c \
	  ft_itoa.c \
	  ft_strjoin.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strsub.c \
	  ft_strtrim.c \
	  ft_power.c \
	  ft_errno.c \
	  get_next_line.c \
	  ft_fact.c \
	  ft_tabtospace.c \

.PHONY = all clean fclean re;

all: $(NAME)

OBJECTS	= $(subst .c,.o,$(SRC))

$(NAME): $(OBJECTS)
		ar rc $(NAME) $(OBJECTS)
		ranlib $(NAME)

%.o: %.c
		$(CC) -c $< -o $@

clean:
		rm -f $(OBJECTS)
fclean: clean
		rm -f $(NAME)

re: fclean $(NAME)
