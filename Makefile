# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/11 12:00:21 by cdeniau           #+#    #+#              #
#    Updated: 2015/08/07 14:56:42 by cdeniau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_malloc

SRC			=	sources/main.c \
				sources/size.c \
				sources/nope.c \
				sources/ft_atoi_hex.c \
				sources/ft_free.c \

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
clean		:
	make -C ./libft clean
	$(RM) $(OBJ)

fclean		:	clean
	make -C ./libft fclean
	$(RM) $(NAME)

re			:	fclean all

extra       :   FLAGS += $(EXTRAFLAGS)
extra       :   re

%.o			:	%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

.PHONY: all clean fclean re
