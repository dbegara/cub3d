# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 19:05:20 by dbegara-          #+#    #+#              #
#    Updated: 2021/02/25 18:48:21 by dbegara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SRC = $(SRC_DIR)/args.c $(SRC_DIR)/color_parse.c $(SRC_DIR)/game_init.c $(SRC_DIR)/img_to_bmp.c $(SRC_DIR)/main.c $(SRC_DIR)/map_parse.c \
$(SRC_DIR)/raycast.c $(SRC_DIR)/sprite_cast.c $(SRC_DIR)/window.c $(SRC_DIR)/aux.c $(SRC_DIR)/exit.c $(SRC_DIR)/game_loop.c $(SRC_DIR)/key_handle.c \
$(SRC_DIR)/map_check.c $(SRC_DIR)/move.c $(SRC_DIR)/raycast_aux.c $(SRC_DIR)/sprites.c $(SRC_DIR)/color.c $(SRC_DIR)/file_parse.c $(SRC_DIR)/image.c \
$(SRC_DIR)/load_image.c $(SRC_DIR)/map_objects.c $(SRC_DIR)/player.c $(SRC_DIR)/res_parse.c $(SRC_DIR)/tex_parse.c
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME = $(BIN_DIR)/cub3D

all: libs | $(NAME)

$(NAME) : $(OBJ) | $(BIN_DIR)
	gcc -Llib/gnl -lgnl -Llib/libft -lft -lmlx -framework OpenGL -framework AppKit -o $@ $(OBJ) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	gcc -Wall -Wextra -Werror -Imlx -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

libs: libft

libft:
	make -C lib/libft

re: fclean all

fclean: clean
	@$(RM) -rv $(BIN_DIR)

clean:
	@$(RM) -rv $(OBJ_DIR)  && make clean -C lib/libft