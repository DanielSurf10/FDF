# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/26 16:56:12 by lsouza-r          #+#    #+#              #
#    Updated: 2024/06/10 19:06:05 by danbarbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library name
NAME	= libft.a

# Compilation and Flags
CC		= cc
FLAGS	= -Wall -Wextra -Werror -c -g3

# Source files
SRC		= ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_gnl.c

SRC_BONUS = ft_lstnew_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c

# Objects files
OBJ		= $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

# Generate library rule
all: ${NAME}
${NAME}: ${OBJ}
bonus: ${OBJ_BONUS}
# Generate objects rule
%.o: %.c
	@$(CC) $(FLAGS) -I ./include $< -o $@
	@ar rcs ${NAME} $@
	@printf "Compiling $<\n"

# Delete files rules
clean:
		rm -f ${OBJ}
		rm -f ${OBJ_BONUS}

fclean: clean
		rm -f ${NAME}

re: fclean all
