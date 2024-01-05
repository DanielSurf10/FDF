NAME	:= fdf
CFLAGS	:= -Wunreachable-code -Ofast -g3 -c
LIBMLX	:= lib/MLX42
LIBFT	:= lib/libft

HEADERS	:= -I include -I $(LIBMLX)/include -I $(LIBFT)
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)/libft.a

SRCS	:= $(addprefix src/, 1_main_bonus.c 2_init_bonus.c 3_init_map_bonus.c \
		4_init_map_utils_bonus.c 5_check_map_bonus.c 6_init_position_bonus.c 7_randomize_bonus.c 8_scale_bonus.c 9_rotation_bonus.c \
		10_translation_bonus.c 11_bresenham_bonus.c 12_hooks_bonus.c 13_utils_bonus.c)
OBJS	:= ${SRCS:src/%.c=obj/%.o}

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(NAME_BONUS): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME_BONUS)

obj/%.o: src/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) $(HEADERS) $< -o $@ && printf "Compiling: $(notdir $<)\n"

bonus: all

clean:
	@rm -rf $(OBJS)
#	@rm -rf $(LIBMLX)/build
#	@make -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)
#	@make -C $(LIBFT) fclean

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader $(SRCS) $(SRCS) include

.PHONY: all, clean, fclean, re, libmlx, libft
