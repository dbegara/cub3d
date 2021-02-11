# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 19:05:20 by dbegara-          #+#    #+#              #
#    Updated: 2021/02/11 18:09:12 by dbegara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME = $(BIN_DIR)/cub3d

all: libs | $(NAME)

$(NAME) : $(OBJ) | $(BIN_DIR)
	cc -Llib/gnl -lgnl -Llib/libft -lft -Llib/mlx -lmlx -framework OpenGL -framework AppKit -o $@ $(OBJ) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	cc -Wall -Wextra -Werror -Imlx -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

libs: libft gnl

libft:
	make bonus -C lib/libft && make clean -C lib/libft

gnl:
	cd lib/gnl && cc -c get_next_line.c get_next_line_utils.c && ar rcs libgnl.a get_next_line.o get_next_line_utils.o && rm *.o

re: fclean all

fclean: clean
	@$(RM) -rv $(BIN_DIR)

clean:
	@$(RM) -rv $(OBJ_DIR)