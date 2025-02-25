# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 15:21:37 by ldevoude          #+#    #+#              #
#    Updated: 2025/02/25 10:32:32 by ldevoude         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#####################################################
#					PROGRAM							#
#####################################################
NAME		=	fractol

#####################################################
#					COMPILING						#
#####################################################
CC			=	cc

#####################################################
#					DIRECTORY						#
#####################################################
DMLX		=	mlx_linux
#DLIBFT		=	libft
#D		=	

#####################################################
#					FLAGS							#
#####################################################
CFLAGS		=	-Wall -Wextra -Werror -g3 -g
CPPFLAGS	=	-I $(DMLX)/
MLXFLAGS	=	-lX11 -lXext

#####################################################
#					FILES							#
#####################################################
SRC			=	main.c\
				math_formula.c\
				mlx.c\
				sets.c\
				color.c\
				error.c\
				hooks.c\
				

HEADERS		=	fractol.h \
				$(DMLX)/mlx.h \
				$(DMLX)/mlx_int.h

#####################################################
#					ARCHIVES						#
#####################################################
AR			=	ar
AFLAG		=	rcs
LIBMLX		=	$(DMLX)/libmlx.a

all: $(LIBMLX) $(NAME)

$(LIBMLX):
	$(MAKE) -C $(DMLX)

$(NAME): $(HEADERS) Makefile $(SRC)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(SRC) $(LIBMLX) $(MLXFLAGS) -o $(NAME)

re: fclean
	$(MAKE) all

fclean: clean
	rm -f $(NAME)
	$(MAKE) clean -C $(DMLX)

clean:
	$(MAKE) clean -C $(DMLX)
