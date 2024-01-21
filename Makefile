# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajawad <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 14:38:49 by ajawad            #+#    #+#              #
#    Updated: 2024/01/20 11:44:52 by ajawad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

MAIN := utils/so_long.c
LIB := utils/lib/libft.a
GNL := utils/gnl/get_next_line.c utils/gnl/get_next_line_utils.c
PARS := utils/parsing/parsing_map.c utils/parsing/valid_elements_checker.c \
	utils/parsing/wall_surround_checker.c utils/parsing/valid_path_checker.c \
	utils/parsing/map_rectangle_checker.c
REND := utils/rendering/rendering.c

OBJS := ${MAIN:.c=.o} ${GNL:.c=.o} ${PARS:.c=.o} ${REND:.c=.o}

HEADER := -Iincludes

MEND_HEAD := includes/so_long.h

CC := cc
CFLAGS := -Wall -Wextra -Werror -g -fsanitize=address
MINILIBX := -lmlx -lXext -lX11

RM := rm -f



all: ${NAME}

${NAME}: ${OBJS} ${LIB} ${MEND_HEAD}
	@tput bold; tput dim; tput setaf 2; printf "Compiling the program: "; tput sgr 0
	${CC} ${CFLAGS} ${HEADER} ${OBJS} ${LIB} ${MINILIBX} -o ${NAME}

${LIB}:
	@tput bold; tput dim; tput setaf 2; printf "Making libft...\n"; tput sgr 0
	@${MAKE} -C utils/lib re --quiet

clean:
	@tput bold; tput setaf 1; printf "Deleting the object files...\n"; tput sgr0
	@${RM} ${OBJS}
	@tput bold; tput setaf 1; printf "Cleaning libft...\n"
	@$(MAKE) -C utils/lib clean --quiet

fclean: clean
	@tput bold; tput setaf 1; printf "Deleting the program...\n"; tput sgr 0
	@${RM} ${NAME}
	@tput bold; tput setaf 1; printf "Fcleaning libft...\n"; tput sgr 0
	@${MAKE} -C utils/lib fclean --quiet

re: fclean all

.PHONY: all clean fclean re
