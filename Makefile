#Program name
NAME	= cub3d

# Compiler
CC		= @cc
CFLAGS	=  -Wall -Wextra -Werror

# Minilibx
MLX_PATH	= minilibx/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

# Libft
LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# Includes
INC			=	-I ./includes/\
				-I ./libft/\
				-I ./minilibx/

# Sources
SRC_PATH	=	src/
SRC			=	main.c events.c mouse_events.c draw.c draw_line.c\
			draw_scene.c map.c raycast.c texture.c\
			cub_parser.c cub_readset.c cub_validate.c cub_helper.c\
			hit_dir.c init.c player_setup.c\
			map_img_setup.c free.c

SRCS		= $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(LIBFT):
	@echo "Making libft..."
	@make -sC $(LIBFT_PATH)

$(MLX_PATH) :
	@echo "mlx not found, downloading..."
	wget -q https://cdn.intra.42.fr/document/document/17607/minilibx-linux.tgz
	tar -xvf minilibx-linux.tgz
	rm minilibx-linux.tgz
	mv minilibx-linux minilibx
	@make -C $(MLX_PATH)

$(NAME): $(MLX_PATH) $(OBJS)
	@echo "Compiling cub3d..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) -lXext -lX11 -lm -lz
	@echo "cub3d compiled."

bonus: all

clean:
	@echo "Removing .o object files..."
	@rm -rf $(OBJ_PATH)
	@make clean -sC $(LIBFT_PATH)

fclean: clean
	@echo "Removing cub3d..."
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all re clean fclean