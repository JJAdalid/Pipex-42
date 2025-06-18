# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/04 09:05:38 by jadalid-          #+#    #+#              #
#    Updated: 2025/06/17 22:14:46 by jadalid-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRC = pipex_utils.c pipex.c
OBJ = $(SRC:.c=.o)
HEADER = pipex.h

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)


$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "✅✅ Compilado con éxito ✅✅"
	
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -f $(OBJ)
	@echo "🧹 Objetos limpiados"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "🧼 Todo limpito"

re: fclean all

.PHONY: all clean fclean re