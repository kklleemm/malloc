# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/11 12:00:21 by cdeniau           #+#    #+#              #
#    Updated: 2015/08/06 16:10:54 by cdeniau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME		=	libft_malloc_$(HOSTTYPE).so

LS			=	libft_malloc.so

SRC			=	sources/main.c \
				sources/size.c \
				sources/nope.c \
				sources/print_addr.c \

OBJ			=	$(SRC:.c=.o)

INC			=	-I./includes -I./libft/includes
LINK		=	-Llibft -lft $(LDFLAGS)

EXTRAFLAGS	=	--analyze -Weverything -Wno-missing-prototypes -Qunused-arguments
FLAGS		=	$(LDFLAGS)
INC_MLX		=	minilibx_macos

CC			=	/usr/bin/gcc
RM			=	/bin/rm -v

all			:	$(NAME)

$(NAME)		:	$(OBJ)
	make -C ./libft
	$(CC) $(FLAGS) $(INC) $(LINK) $(OBJ) -o $(NAME)
	ln -s $(NAME) $(LS)

clean		:
	make -C ./libft clean
	$(RM) $(OBJ)

fclean		:	clean
	make -C ./libft fclean
	$(RM) $(NAME)
	$(RM) $(LS)

re			:	fclean all

extra       :   FLAGS += $(EXTRAFLAGS)
extra       :   re

%.o			:	%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

.PHONY: all clean fclean re
