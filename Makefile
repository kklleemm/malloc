# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/11 12:00:21 by cdeniau           #+#    #+#              #
#    Updated: 2015/09/17 18:10:14 by cdeniau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME		=		libft_malloc_$(HOSTTYPE).so
LS			=		libft_malloc.so

CC			=		gcc
CFLAGS		=		-Wall -Werror -Wextra
SRCDIR		=		./sources/
SRCO		=		$(SRC:.c=.o)
ODIR		=		./includes/
LIB			=		./libft/libft.a
INC			=		-I./includes -I./libft/includes
LINK		=		-Llibft -lft

SRC			=		ft_atoi_hex.c \
					malloc.c \
					ft_free.c \
					ft_realloc.c \
					ft_print.c \
					tiny.c \
					header.c \

OBJ			=		$(SRC:.c=.o)
OBJS		=		$(addprefix $(ODIR), $(OBJ))

all			:		$(LIB) $(NAME)

$(NAME)		:		$(OBJS)
					$(CC) -shared -o $(NAME) $^ $(LINK) 
					ln -s $(NAME) $(LS)

$(ODIR)%.o	:		$(SRCDIR)%.c
					mkdir -p $(ODIR)
					$(CC) $(CFLAGS) -c $^ $(INC) -o $@

$(LIB)		:
					@make -C libft

clean		:
					/bin/rm -f $(addprefix $(ODIR), $(OBJ)) 
					make -C ./libft clean

fclean		:		clean
					/bin/rm -rf $(LS)
					make -C ./libft fclean
					/bin/rm -rf $(NAME)
					/bin/rm -rf test

re			:		fclean all

test		:		re
					gcc $(CFLAGS) -o test main.c $(LINK) $(NAME) $(INC) -g
