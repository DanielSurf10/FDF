NAME	:= fdf
NAME_BONUS	:=	fdf_bonus
CFLAGS	:= -Wunreachable-code -Ofast -g3
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/libft

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)/libft.a

SRCS	:= $(addprefix ./src/mandatory/, 1_main.c 2_init.c 3_init_map.c \
		4_init_map_utils.c 5_check_map.c 6_init_position.c 7_randomize.c 8_scale.c 9_rotation.c \
		10_translation.c 11_bresenham.c 12_hooks.c 13_utils.c)
OBJS	:= ${SRCS:.c=.o}

SRCS_BONUS	:= $(addprefix ./src/bonus/, 1_main_bonus.c 2_init_bonus.c 3_init_map_bonus.c \
		4_init_map_utils_bonus.c 5_check_map_bonus.c 6_init_position_bonus.c 7_randomize_bonus.c 8_scale_bonus.c 9_rotation_bonus.c \
		10_translation_bonus.c 11_bresenham_bonus.c 12_hooks_bonus.c 13_utils_bonus.c)
OBJS_BONUS	:= ${SRCS_BONUS:.c=.o}

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) $(LIBS) $(HEADERS) -o $(NAME_BONUS)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

bonus: libmlx libft $(NAME_BONUS)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJS_BONUS)
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@make -C $(LIBFT) fclean

re: clean all

norm:
	norminette -R CheckForbiddenSourceHeader $(SRCS) $(SRCS_BONUS) ./include

.PHONY: all, clean, fclean, re, libmlx, libft
