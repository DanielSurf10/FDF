# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 12:04:19 by lsouza-r          #+#    #+#              #
#    Updated: 2024/06/10 18:22:58 by danbarbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fdf
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -g3
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/LIBFT

HEADERS	:= -I ./include -I \
							$(LIBMLX)/include \
							-I $(LIBFT)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a \
						${LIBFT}/libft.a \
							-ldl -lglfw -pthread -lm
SRCS	:= $(shell find src -iname "*.c")
OBJS	:= ${SRCS:src/%.c=obj/%.o}

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C ${LIBFT}

obj/%.o: src/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf obj
#	@rm -rf $(LIBMLX)/build
	@make clean -C ${LIBFT}

fclean: clean
	@rm -rf $(NAME)

re: clean all

val: readline.supp all
	@valgrind -q --suppressions=readline.supp \
				--leak-check=full \
				--show-leak-kinds=all \
				--track-origins=yes \
				--track-fds=yes \
				./${NAME}

readline.supp:
	@echo '{' >> $@
	@echo '<MLX_CODAM>' >> $@
	@echo 'Memcheck:Leak' >> $@
	@echo 'match-leak-kinds: reachable' >> $@
	@echo '...' >> $@
	@echo 'fun:_dl_catch_exception' >> $@
	@echo '...' >> $@
	@echo '}' >> $@
	@echo '{' >> $@
	@echo '<MLX_CODAM>' >> $@
	@echo 'Memcheck:Leak' >> $@
	@echo 'match-leak-kinds: reachable' >> $@
	@echo '...' >> $@
	@echo 'fun:mlx_init' >> $@
	@echo '...' >> $@
	@echo '}' >> $@
	@echo '{' >> $@
	@echo '<MLX_CODAM>' >> $@
	@echo 'Memcheck:Leak' >> $@
	@echo 'match-leak-kinds: reachable' >> $@
	@echo '...' >> $@
	@echo 'fun:XrmGetStringDatabase' >> $@
	@echo '...' >> $@
	@echo '}' >> $@
	@echo '{' >> $@
	@echo '<MLX_CODAM>' >> $@
	@echo 'Memcheck:Leak' >> $@
	@echo 'match-leak-kinds: reachable' >> $@
	@echo '...' >> $@
	@echo 'fun:_XrmInitParseInfo' >> $@
	@echo '...' >> $@
	@echo '}' >> $@
	@echo '{' >> $@
	@echo '<MLX_CODAM>' >> $@
	@echo 'Memcheck:Leak' >> $@
	@echo 'match-leak-kinds: reachable' >> $@
	@echo '...' >> $@
	@echo 'fun:__tls_get_addr' >> $@
	@echo '...' >> $@
	@echo '}' >> $@
	@echo '{' >> $@
	@echo '<MLX_CODAM>' >> $@
	@echo 'Memcheck:Leak' >> $@
	@echo 'match-leak-kinds: reachable' >> $@
	@echo '...' >> $@
	@echo 'fun:__pthread_once_slow' >> $@
	@echo '...' >> $@
	@echo '}' >> $@
	@echo '{' >> $@
	@echo '<MLX_CODAM>' >> $@
	@echo 'Memcheck:Leak' >> $@
	@echo 'match-leak-kinds: reachable' >> $@
	@echo '...' >> $@
	@echo 'fun:glfwInit' >> $@
	@echo '...' >> $@
	@echo '}' >> $@
	@echo '{' >> $@
	@echo '<MLX_CODAM>' >> $@
	@echo 'Memcheck:Leak' >> $@
	@echo 'match-leak-kinds: reachable' >> $@
	@echo '...' >> $@
	@echo 'fun:_dl_init' >> $@
	@echo '...' >> $@
	@echo '}' >> $@

.PHONY: all, clean, fclean, re, libmlx
