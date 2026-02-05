#==========================================#
#                 SO_LONG                  #
#==========================================#

NAME = so_long

#---------------FLAGS----------------------#

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
DEPFLAGS	= -MMD -MP

RM			= rm -rf
MKDIR		= mkdir -p

MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
INCLUDES	= -I$(INC_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR) -I$(MLX_DIR)

#---------------DIRECTORIES----------------#

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

#---------------LIBS-----------------------#

LIBFT_DIR	= lib/libft
LIBFT		= $(LIBFT_DIR)/libft.a

PRINTF_DIR	= lib/ft_printf
PRINTF		= $(PRINTF_DIR)/libftprintf.a

MLX_DIR		= lib/mlx/minilibx-linux
MLX			= $(MLX_DIR)/libmlx.a

#---------------SOURCES--------------------#

SRC =	main.c \
		map_check.c map_read.c map_read_utils.c \
		check_chars.c check_elements.c check_path.c check_rectangle.c check_walls.c \
		init_game.c \
		mlx_init_game.c load_sprites.c render_map.c \
		move.c hooks.c \
		errors.c destroy.c

SRCS =	$(addprefix $(SRC_DIR)/, $(SRC))
OBJS =	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS =	$(OBJS:.o=.d)
#---------------RULES----------------------#

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re