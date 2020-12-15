# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 19:05:20 by dbegara-          #+#    #+#              #
#    Updated: 2020/12/15 19:08:33 by dbegara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME = $(BIN_DIR)/cub3d

all: $(NAME)

$(NAME) : $(OBJ) | $(BIN_DIR)
	cc -Llib/gnl -lgnl -Llib/libft -lft -Llib/mlx -lmlx -framework OpenGL -framework AppKit -o $@ $(OBJ) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	cc -Wall -Wextra -Werror -Imlx -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

re: fclean all

fclean: clean
	@$(RM) -rv $(BIN_DIR)

clean:
	@$(RM) -rv $(OBJ_DIR)