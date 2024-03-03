NAME	:=	so_long
BONUS	:=	so_long_bonus

LIB	:=	./src/libft/libft.a

SRC			:=	so_long.c initialize_game.c get_map.c parsing.c parsing1.c load_images.c draw_map.c game_loop.c game_loop_utils.c get_next_line.c get_next_line_utils.c utils.c check_elements.c exit_game.c
MEND_FILES	:=	$(addprefix src/,$(SRC))

#BONUS_FILES :=

OBJS	:=	${MEND_FILES:.c=.o}

#OBJS_B := ${BONUS_FILES:.c=.o}

HEADER	:=	-Iincludes

MEND_HEAD	:=	includes/so_long.h
#BONUS_HEAD := includes/so_long_bonus.h


CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror
MLX_FLAGS	:=	-lmlx -framework OpenGL -framework AppKit

RM	:=	rm -f



all: ${NAME}
bonus: ${BONUS}


${NAME}: ${OBJS} ${LIB} ${MEND_HEAD}
	@tput bold; tput dim; tput setaf 2; printf "Compiling the program: "; tput sgr 0
	${CC} ${CFLAGS} ${OBJS} ${HEADER} ${MLX_FLAGS} -Lsrc/libft -lft -o ${NAME}


#${BONUS}: ${OBJS_B} ${LIB} ${BONUS_HEAD}
#	@tput bold; tput dim; tput setaf 2; printf "Compiling the bonus program: "; tput sgr 0
#	${CC} ${CFLAGS} ${OBJS_B} ${HEADER} ${MLX_FLAGS} -Lsrc/libft -lft -o ${BONUS}

${LIB}:
	@tput bold; tput dim; tput setaf 2; printf "Making libft...\n"; tput sgr 0
	@${MAKE} -C ./src/libft re --quiet

clean:
	@tput bold; tput setaf 1; printf "Deleting the object files...\n"; tput sgr0
	@${RM} ${OBJS}
	@tput bold; tput setaf 1; printf "Cleaning libft...\n"
	@$(MAKE) -C ./src/libft clean --quiet
#clean_b:
#	@tput bold; tput setaf 1; printf "Deleting the bonus object files...\n"; tput sgr0
#	@${RM} ${OBJS_B}
#	@tput bold; tput setaf 1; printf "Cleaning libft...\n"; tput sgr 0
#	@$(MAKE) -C ./src/libft clean --quiet

fclean: clean
	@tput bold; tput setaf 1; printf "Deleting the program...\n"; tput sgr 0
	@${RM} ${NAME}
	@tput bold; tput setaf 1; printf "Fcleaning libft...\n"; tput sgr 0
	@${MAKE} -C ./src/libft fclean --quiet
#fclean_b: clean_b
#	@tput bold; tput setaf 1; printf "Deleting the bonus program...\n"; tput sgr 0
#	@${RM} ${BONUS}
#	@tput bold; tput setaf 1; printf "Fcleaning libft...\n"; tput sgr 0
#	@${MAKE} -C ./src/libft fclean --quiet

re: fclean all
#re_b: fclean_b bonus


.PHONY: all clean fclean re
