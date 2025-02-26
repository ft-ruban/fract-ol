# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 15:21:37 by ldevoude          #+#    #+#              #
#    Updated: 2025/02/26 10:21:37 by ldevoude         ###   ########lyon.fr    #
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
DLIBFTX		=	libftx
OBJDIR 		= 	obj
$(shell mkdir -p $(OBJDIR)) #create dir if not existing
#D		=	

#####################################################
#					FLAGS							#
#####################################################
CFLAGS		=	-Wall -Wextra -Werror -g3 -g
CPPFLAGS	=	-I $(DMLX)/ -I $(DLIBFTX)/  # Include headers from both directories
MLXFLAGS	=	-lX11 -lXext -lm

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
				$(wildcard $(DLIBFTX)/*.c)
				
# OBJ = $(CFILES:.c=.o)\

OBJ = $(SRC:.c=.o)\

HEADERS		=	fractol.h \
				$(DMLX)/mlx.h \
				$(DMLX)/mlx_int.h \
				$(DLIBFTX)/libft.h  \

#####################################################
#					ARCHIVES						#
#####################################################
AR			=	ar
AFLAG		=	rcs
LIBMLX		=	$(DMLX)/libmlx.a
LIBLIBFTX 	=   $(DLIBFTX)/libftx.a

#####################################################
#                   TARGETS                         #
#####################################################

all: $(LIBLIBFTX) $(LIBMLX) $(NAME)

$(NAME): $(OBJ)
	$(AR) $(AFLAG) $(NAME) $(OBJ)

$(LIBLIBFTX):
	$(MAKE) -C $(DLIBFTX)

$(LIBMLX):
	$(MAKE) -C $(DMLX)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(HEADERS) Makefile $(SRC)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(SRC) $(LIBMLX) $(LIBLIBFTX) $(MLXFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(DLIBFTX) clean || true
	$(MAKE) -C $(DMLX) clean || true
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(DLIBFTX) fclean || true
	$(MAKE) -C $(DMLX) fclean || true

re: fclean all

.PHONY: all clean fclean re

#TODO Would love to learn how to place my .o into a folder...