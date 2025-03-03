# 🏗️ Variables de fichiers
SRC = ft_printf.c ft_printf_cases.c ft_printfd.c ft_printfd_cases.c
OBJ = $(SRC:.c=.o)

# 📌 Chemin vers libft
LIBFT_PATH = ../
LIBFT = $(LIBFT_PATH)/libftx.a

# ⚙️ Compiler + flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# 📦 Nom de la bibliothèque finale
NAME = printf.a

# 🎯 Règle par défaut : construire la lib
all: $(NAME)

# 🏛️ Création de la bibliothèque statique
$(NAME): $(OBJ) $(LIBFT)
	ar rcs $(NAME) $(OBJ) $(LIBFT)

# 📌 Compilation des fichiers `.c` en `.o`
%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

# 🧪 Exécutable de test
TEST_EXEC = test_printf
$(TEST_EXEC): $(OBJ) main.c $(LIBFT)
	$(CC) $(CFLAGS) main.c $(OBJ) $(LIBFT) -o $(TEST_EXEC)

# 🧹 Nettoyage des fichiers objets
clean:
	rm -f $(OBJ)

# 🧼 Nettoyage total
fclean: clean
	rm -f $(NAME) $(TEST_EXEC) $(OBJ)

# 🔄 Rebuild propre
re: fclean all

debug :
								@echo "Current directory: $(PWD)"
								@echo "Checking libft files:"
								@ls -l $(DIR_LIBFT)

# ⚠️ S'assurer que `libft` est bien construite avant `printf.a`
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH) all

.PHONY: all clean fclean re
