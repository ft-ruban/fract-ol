# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 15:21:37 by ldevoude          #+#    #+#              #
#    Updated: 2025/04/08 14:52:45 by ldevoude         ###   ########lyon.fr    #
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
CFLAGS         =   -Wall -Wextra -Werror #dl -g before push
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
DIR_LIBFTX     =   ./libftx
OBJ_DIR        =   obj_fractol


#####################################################
#					HEADER  						#
#####################################################
HEADER_FRACTOL =   $(DIR_FRACTOL)/fractol.h
HEADER_MLX     =   $(DIR_MLX)/mlx.h\
				   					$(DIR_MLX)/mlx_int.h
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
						ft_atop\
						main\
						math_formula\
						mlx\
						sets\
						color\
						error\
						fractol\
						commands)
						
#####################################################
#					VARIABLES_OBJ				    #
#####################################################

FRACTOL_OBJ = $(addprefix $(OBJ_DIR)/, $(FRACTOL_SRC:.c=.o))
#DEPENDANCY_FILES =   $(FRACTOL_OBJ:.o=.d) 
DEPENDANCY_FILES = $(addprefix $(OBJ_DIR)/, $(FRACTOL_SRC:.c=.d))

#####################################################
#					TARGETS						#
#####################################################

all             :    $(LIBLIBFTX) $(LIBMLX) $(NAME)

clean:
	@rm -rf $(OBJ_DIR) $(DEPENDANCY_FILES)
	$(MAKE) -C $(DIR_LIBFTX) clean
	$(MAKE) -C $(DIR_MLX) clean
	@echo "$(GREEN)Cleaning completed!$(RESET)"

fclean          :    clean
								@rm -f $(NAME)
								$(MAKE) -C $(DIR_LIBFTX) fclean
								$(MAKE) -C $(DIR_MLX) clean
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

re               :	fclean 
						$(MAKE) all	

#####################################################
#					COMMANDS						#
#####################################################


	
$(NAME): $(FRACTOL_OBJ) $(LIBLIBFTX) $(LIBMLX) Makefile
		 $(CC) $(CFLAGS) -o $@ $(FRACTOL_OBJ) $(LIBLIBFTX) $(LIBMLX) $(MLXFLAGS)
		 @echo "$(GREEN) $(NAME) is now ready to run ／人◕ ‿‿ ◕人＼ "



$(LIBLIBFTX): ./libftx/Makefile
	$(MAKE) -C $(DIR_LIBFTX)

$(OBJ_DIR)/%.d: $(DIR_FRACTOL)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(DIR_FRACTOL) -MM -MP -MT '$(@:.d=.o) $@' -MF $@ $<

$(DIR_MLX)/libmlx.a:
		$(MAKE) -C $(DIR_MLX)

$(OBJ_DIR)/%.o	   : $(DIR_FRACTOL)/%.c $(HEADER_FRACTOL) | $(OBJ_DIR)
				     @echo "Recompiling due to header changes..."
					 $(CC) $(CFLAGS) -I$(DIR_FRACTOL) -MMD -MP -c $< -o $@

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

