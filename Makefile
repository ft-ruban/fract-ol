# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 15:21:37 by ldevoude          #+#    #+#              #
#    Updated: 2025/02/28 15:19:34 by ldevoude         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#####################################################
##				 								   ##					
##                    VARIABLES                    ##
##												   ##
#####################################################

#####################################################
#				 PROGRAM + AUTHOR					#
#####################################################
AUTHOR 		   =   ldevoude
NAME		   =	fractol
#####################################################
#					COMPILING						#
#####################################################
CC             =   cc
#####################################################
#					FLAGS							#
#####################################################
CFLAGS         =   -Wall -Wextra -Werror -g3 -g #dl -g before push
CPPFLAGS	   =	-I $(DIR_MLX)/  # Include headers from both directories
MLXFLAGS	   =	-lX11 -lXext
#####################################################
#					ARCHIVES						#
#####################################################
AR 			=   ar rcs
LIBMLX		=	$(DIR_MLX)/libmlx.a
LIBLIBFTX 	=   $(DIR_LIBFTX)/libftx.a

#####################################################
#					DIRECTORY						#
#####################################################
DIR_FRACTOL    =   .
DIR_MLX		   =   ./mlx_linux
DIR_PRINTF     =   ./libftx/printf
DIR_GNL        =   ./libftx/get_next_line
DIR_LIBFTX     =   ./libftx
OBJ_DIR        =   obj_fractol


#####################################################
#					HEADER  						#
#####################################################
HEADER_FRACTOL =   $(DIR_FRACTOL)/fractol.h
HEADER_MLX     =   $(DIR_MLX)/mlx.h\
				   $(DIR_MLX)/mlx_int.h
					
HEADER_PRINTF  =   $(DIR_PRINTF)/printf.h
HEADER_GNL 	   =   $(DIR_GNL)/get_next_line.h
HEADER_LIBFTX  =   $(DIR_LIBFTX)/libft.h

#####################################################
#					 MISC     						#
#####################################################
LIGHTPURPLE    =   \033[1;35m
GREEN		   =   \033[1;32m
RED            =   \033[1;31m

#####################################################
#					VARIABLES SOURCES				#
#####################################################
FRACTOL_SRC    =   $(addsuffix .c, \
						main\
						math_formula\
						mlx\
						sets\
						color\
						error\
						hooks)
# MLX_SRC       =    $(addsuffix .c, \
# 						mlx_clear_window\
# 						mlx_destroy_display\
# 						mlx_destroy_image\
# 						mlx_destroy_window\
# 						mlx_expose_hook\
# 						mlx_ext_randr\
# 						mlx_flush_event\
# 						mlx_get_color_value\
# 						mlx_get_data_addr\
# 						mlx_hook\
# 						mlx_init\
# 						mlx_int_anti_resize_win\
# 						mlx_int_do_nothing\
# 						mlx_int_get_visual\
# 						mlx_int_param_event\
# 						mlx_int_set_win_event_mask\
# 						mlx_int_str_to_wordtab\
# 						mlx_int_wait_first_expose\
# 						mlx_key_hook\
# 						mlx_lib_xpm\
# 						mlx_loop\
# 						mlx_loop_hook\
# 						mlx_mouse\
# 						mlx_mouse_hook\
# 						mlx_new_image\
# 						mlx_new_window\
# 						mlx_pixel_put\
# 						mlx_put_image_to_window\
# 						mlx_rgb\
# 						mlx_screen_size\
# 						mlx_set_font\
# 						mlx_string_put\
# 						mlx_xpm)

LIBFTX_SRC     =   $(addsuffix .c, \
						ft_atoi \
						ft_atop \
						ft_bzero \
						ft_calloc \
						ft_isalnum \
						ft_isalpha \
						ft_isascii \
						ft_isdigit \
						ft_isprint \
						ft_itoa \
						ft_itoa_hexx\
						ft_memchr \
						ft_memcmp	\
						ft_memcpy	\
						ft_memmove \
						ft_memset \
						ft_putchar_fd \
						ft_putnbr_fd \
						ft_putendl_fd \
						ft_putstr_fd \
						ft_split \
						ft_strchr \
						ft_strcmp \
						ft_strdup \
						ft_striteri \
						ft_strjoin \
						ft_strlcat \
						ft_strlcpy \
						ft_strlen \
						ft_strmapi \
						ft_strncmp \
						ft_strnstr \
						ft_strrchr \
						ft_strtoupper \
						ft_strtrim \
						ft_substr \
						ft_tolower \
						ft_toupper \
						ft_utoa)

GNL_SRC        =   $(addsuffix .c, \
						get_next_line)
					
PRINTF_SRC 	   =   $(addsuffix .c, \
						ft_printf_cases \
						ft_printf\
						ft_printfd_cases\
						ft_printfd)
#####################################################
#					VARIABLES_OBJ				    #
#####################################################

FRACTOL_OBJ = $(addprefix $(OBJ_DIR)/, $(FRACTOL_SRC:.c=.o))
LIBFTX_OBJ  = $(addprefix $(OBJ_DIR)/, $(LIBFTX_SRC:.c=.o))
GNL_OBJ     = $(addprefix $(OBJ_DIR)/, $(GNL_SRC:.c=.o))
PRINTF_OBJ  = $(addprefix $(OBJ_DIR)/, $(PRINTF_SRC:.c=.o))

# MLX_OBJ          =   $(addprefix $(DIR_MLX)/, $(MLX_SRC:.c=.o))

DEPENDANCY_FILES =   $(FRACTOL_OBJ:.o=.d) #to create dep

#####################################################
#					TARGETS						#
#####################################################

all             :    $(NAME)

clean           :	
								@rm -rf $(OBJ_DIR) $(FRACTOL_OBJ) $(LIBFTX_OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
								@rm -f $(DIR_GNL)*.d 
								@rm -f $(DIR_PRINTF)*.d
								@rm -f $(DIR_MLX)*.d
								$(MAKE) -C $(DIR_MLX) clean
								@echo "$(GREEN)Cleaning of .o and .d files completed successfully! ／人◕ ‿‿ ◕人＼"
fclean          :    clean
								@rm -f $(NAME)
								@echo "$(GREEN)Deleting $(NAME) completed successfully! ／人◕ ‿‿ ◕人＼ "
								@echo "$(RED)"
								@echo "┌──────────────────────────────────────────────────────────┐"
								@echo "│      Deletion finished successfully! ( ◔ ω ◔) ノシ         │"
								@echo "└──────────────────────────────────────────────────────────┘"
								
								@echo "                           ╱|、"
								@echo "                         (˚ˎ 。7"
								@echo "                          |、˜|"
								@echo "                         じしˍ,)ノ"
								@echo "$(RESET)"

	
debug           :   
					@echo "Current directory: $(shell pwd)"
					@echo "Checking fractol files\:"
					@ls -l $(DIR_FRACTOL)
					@echo "Checking libftx files\:"
					@ls -l $(DIR_LIBFTX)
					@echo "Checking gnl files\:"
					@ls -l $(DIR_GNL)
					@echo "Checking printf files\:"
					@ls -l $(DIR_PRINTF)
					@echo "Checking printf files\:"
					@ls -l $(DIR_MLX)
					@echo $(shell -e) "${LIGHTPURPLE}I never thought I'd see a Resonance Cascade, let alone create one!"

re               :	fclean all	

#####################################################
#					COMMANDS						#
#####################################################

$(NAME): $(OBJ_DIR) $(FRACTOL_OBJ) $(LIBFTX_OBJ) $(GNL_OBJ) $(PRINTF_OBJ) $(DIR_MLX)/libmlx.a
		 $(CC) $(CFLAGS) -o $(NAME) $(FRACTOL_OBJ) $(LIBFTX_OBJ) $(GNL_OBJ) $(PRINTF_OBJ) $(DIR_MLX)/libmlx.a $(MLXFLAGS)
		@echo "$(GREEN) $(NAME) is now ready to run ／人◕ ‿‿ ◕人＼ "

$(DIR_MLX)/libmlx.a:
		$(MAKE) -C $(DIR_MLX)

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o	   : $(DIR_FRACTOL)/%.c | $(OBJ_DIR)
					 $(CC) $(CFLAGS) -I$(DIR_FRACTOL) -o $@ -c $<

$(OBJ_DIR)/%.o	   : $(DIR_LIBFTX)/%.c | $(OBJ_DIR)
					 $(CC) $(CFLAGS) -I$(DIR_LIBFTX) -o $@ -c $<

$(OBJ_DIR)/%.o	   : $(DIR_GNL)/%.c | $(OBJ_DIR)
					 $(CC) $(CFLAGS) -I$(DIR_GNL) -o $@ -c $<

$(OBJ_DIR)/%.o	   : $(DIR_PRINTF)/%.c | $(OBJ_DIR)
					 $(CC) $(CFLAGS) -I$(DIR_PRINTF) -o $@ -c $<

$(DIR_FRACTOL)/%.o  :      $(DIR_FRACTOL)/%.c $(HEADER_FRACTOL)
											$(CC) $(CFLAGS) -c $< -o $@

$(DIR_LIBFTX)/%.o   :      $(DIR_LIBFTX)/%.c  $(HEADER_FRACTOL)
											$(CC) $(CFLAGS) -c $< -o $@

$(DIR_GNL)/%.o 		:	   $(DIR_GNL)/%.c  	  $(HEADER_GNL)
											$(CC) $(CFLAGS) -c $< -o $@

$(DIR_PRINTF)/%.o   :      $(DIR_PRINTF)/%.c  $(HEADER_PRINTF)
											$(CC) $(CFLAGS) -c $< -o $@

											
$(OBJ_DIR)          :		
							mkdir -p $(OBJ_DIR)

-include $(DEPENDANCY_FILES)

.PHONY :   					all bonus clean fclean re