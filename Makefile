# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjairus <tjairus@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 00:19:23 by tjairus           #+#    #+#              #
#    Updated: 2022/03/27 10:35:07 by tjairus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol

HEADER = src/includes/fractal.h

SRC_FILES = main.c
SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR),$(SRC_FILES))
OBJ = $(SRC_FILES:.c=.o)
ENGINE_FILES =	color_and_draw.c  burningship.c  hooks.c  init_sets.c  julia.c \
				mandelbrot.c zoom_move.c \

ENGINE_OBJ = $(ENGINE_FILES:.c=.o)
ENGINE_DIR = src/engine/
ENGINE = $(addprefix $(ENGINE_DIR),$(ENGINE_FILES))

LIBFT_FILES = libft.h libft.a
LIBFT_DIR = src/lib/libft/
LIBFT = $(addprefix $(LIBFT_DIR),$(LIBFT_FILES))


FLAGS = -Wall -Werror -Wextra

LIBS = -lm

OS:= $(shell uname -s)
ifeq ($(OS),Darwin)
	KEYS= -D OS=1
	MLX_FILES = libmlx.a
	MLX_DIR = src/lib/mlx_Darwin/
	MLX = $(addprefix $(MLX_DIR),$(MLX_FILES))
	LINKS_OBJ = -I$(MLX_DIR)
	LINKS = -L$(MLX_DIR) -framework OpenGL -framework AppKit
	CFLAG = -lm -I
endif

ifeq ($(OS),Linux)
	MLX_FILES = libmlx_Linux.a
	MLX_DIR = src/lib/mlx/
	MLX = $(addprefix $(MLX_DIR),$(MLX_FILES))
	X11 = /usr/lib/x86_64-linux-gnu/libX11.so /usr/lib/x86_64-linux-gnu/libXext.so
	LINKS = -Isrc/lib/mlx -lX11 -lXext -lm  -L/usr/include/X11
	LINKS_OBJ = -Isrc/lib/mlx
endif

LIB = $(CFLAG) $(LIBFT)

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ) $(ENGINE_OBJ)
	@gcc $(FLAGS) $(LINKS) $(OBJ) $(ENGINE_OBJ) $(MLX) $(X11) $(LIB) -o $(NAME) $(LIBS)
	@rm $(OBJ) $(ENGINE_OBJ)

$(OBJ): $(SRC)
	@gcc $(FLAGS) $(KEYS) $(LINKS_OBJ) -c $(SRC)

$(ENGINE_OBJ): $(ENGINE)
	@gcc $(FLAGS) $(KEY) $(LINKS_OBJ) -c $(ENGINE)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	@rm -rf $(OBJ)
	@rm -rf $(ENGINE_OBJ)

fclean: clean
	@rm -rf $(NAME)
	make clean -C $(MLX_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all