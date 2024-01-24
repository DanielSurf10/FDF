# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 15:54:27 by danbarbo          #+#    #+#              #
#    Updated: 2024/01/24 16:16:12 by danbarbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fdf
# CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
CFLAGS	:= -Wunreachable-code -Ofast -g3
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/libft

HEADERS	:= -I ./include \
			-I ${LIBFT}/include \
			-I $(LIBMLX)/include/MLX42

LIBS	:= $(LIBMLX)/build/libmlx42.a \
			${LIBFT}/libft.a \
			-ldl -lglfw -pthread -lm

SRCS	:= $(shell find src -iname "*.c")
OBJS	:= ${SRCS:src/%.c=obj/%.o}

all: $(NAME)
$(NAME): libmlx libft $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

obj/%.o: src/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	@printf "Compiling: $(notdir $<)\n"

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build
	@make -C $(LIBMLX)/build -j4

libft:
	@make -C ${LIBFT} all

clean:
	@rm -rf $(OBJS)
#	@rm -rf $(LIBMLX)/build		# Tirar o comentário dessa bosta

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libmlx libft
