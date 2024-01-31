# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 15:54:27 by danbarbo          #+#    #+#              #
#    Updated: 2024/01/31 17:33:32 by danbarbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fdf
NAME_B	:= fdf_bonus
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g3
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/libft

HEADERS	:= -I ./include \
			-I ${LIBFT}/include \
			-I ${LIBMLX}/include/MLX42

LIBS	:= ${LIBMLX}/build/libmlx42.a \
			${LIBFT}/libft.a \
			-ldl -lglfw -pthread -lm

SRCS	:= src/render/frame.c \
				src/render/transformation.c \
				src/render/images.c \
				src/render/render.c \
				src/render/menu.c \
				src/key_actions/key_actions_loop.c \
				src/key_actions/key_actions_hook.c \
				src/map/map_creation.c \
				src/map/map_parsing.c \
				src/map/map_validation.c \
				src/line_algorithms/xiaolin.c \
				src/line_algorithms/xiaolin_utils.c \
				src/line_algorithms/xiaolin_init.c \
				src/line_algorithms/bresenham.c \
				src/main.c \
				src/utils/utils_map.c \
				src/utils/color.c \
				src/utils/utils.c
OBJS	:= ${SRCS:src/%.c=obj/%.o}

SRCS_BONUS	:= src_bonus/render/frame_bonus.c \
				src_bonus/render/transformation_bonus.c \
				src_bonus/render/images_bonus.c \
				src_bonus/render/render_bonus.c \
				src_bonus/render/menu_bonus.c \
				src_bonus/key_actions/key_actions_loop_bonus.c \
				src_bonus/key_actions/key_actions_hook_bonus.c \
				src_bonus/map/map_creation_bonus.c \
				src_bonus/map/map_parsing_bonus.c \
				src_bonus/map/map_validation_bonus.c \
				src_bonus/line_algorithms/xiaolin_bonus.c \
				src_bonus/line_algorithms/xiaolin_utils_bonus.c \
				src_bonus/line_algorithms/xiaolin_init_bonus.c \
				src_bonus/line_algorithms/bresenham_bonus.c \
				src_bonus/main_bonus.c \
				src_bonus/utils/utils_map_bonus.c \
				src_bonus/utils/color_bonus.c \
				src_bonus/utils/utils_bonus.c
OBJS_BONUS	:= ${SRCS_BONUS:src_bonus/%.c=obj/%.o}

all: ${NAME}
${NAME}: libmlx libft ${OBJS}
	@${CC} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}

bonus: ${NAME_B}

${NAME_B}: libmlx libft ${OBJS_BONUS}
	@${CC} ${OBJS_BONUS} ${LIBS} ${HEADERS} -o ${NAME_B}

obj/%.o: src/%.c
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}
	@printf "Compiling: ${notdir $<}\n"

obj/%.o: src_bonus/%.c
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}
	@printf "Compiling: ${notdir $<}\n"

libmlx:
	@cmake ${LIBMLX} -B ${LIBMLX}/build
	@make -C ${LIBMLX}/build -j4

libft:
	@make -C ${LIBFT} all

clean:
	@rm -rf ${OBJS}
	@rm -rf ${OBJS_BONUS}
	@rm -rf ${LIBMLX}/build
	@make -C ${LIBFT} clean

fclean: clean
	@rm -rf ${NAME}
	@rm -rf ${NAME_B}
	@make -C ${LIBFT} clean

re: fclean all

.PHONY: all clean fclean re libmlx libft bonus
