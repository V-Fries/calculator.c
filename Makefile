NAME =			calculator

NAME_DEBUG =	${NAME}_debug


H_FILES =\
	parsing.h	\
	tokens.h

HEADERS =\
			${addprefix includes/, ${H_FILES}}

INCLUDES =\
			-I ${LIBFT_PATH}includes/				\
			-I includes


SRCS_DIR = srcs/

SRCS =\
	parsing/operators.c			\
	parsing/parenthes.c			\
	parsing/parse_arguments.c	\
\
	main.c



TEST_DIR = test/

SRCS_TEST =\
		includes/parsing.h.c	\
		includes/tokens.h.c


DIR_OBJS = 		build/

TEST_OBJS_DIR = ${DIR_OBJS}test/

OBJS =			${addprefix ${DIR_OBJS},${SRCS:.c=.o}}

OBJS_DEBUG =	${addprefix ${DIR_OBJS},${SRCS:.c=_debug.o}}

OBJS_TEST =		${addprefix ${TEST_OBJS_DIR},${SRCS_TEST:.c=.o}}


FLAGS_NO_O3 = 	-Wall -Wextra -Werror

FLAGS =			${FLAGS_NO_O3} -O3

FLAGS_DEBUG	=	${FLAGS_NO_O3} -g3 -fsanitize=address


LIBFT_L =		-L${LIBFT_PATH} -lft

LIBFT_L_DEBUG =	-L${LIBFT_PATH} -lft_debug

LIBFT_A =		${LIBFT_PATH}libft.a

LIBFT_A_DEBUG =	${LIBFT_PATH}libft_debug.a

LIBFT_PATH =	libs/libft/


SHARED_DEPENDENCIES =	Makefile ${HEADERS}

DEFAULT_DEPENDENCIES =	${LIBFT_A}

DEBUG_DEPENDENCIES = 	${LIBFT_A_DEBUG}


DEBUG_L =	${LIBFT_L_DEBUG}

DEFAULT_L =	${LIBFT_L}


RMF =	 				rm -f

MKDIR = 				mkdir -p

MAKE_LIBFT =	${MAKE} -C ${LIBFT_PATH}


all:			${DIR_OBJS}
				${MAKE_LIBFT}
				@${MAKE} ${NAME}

$(NAME):		${OBJS}
				${CC} ${FLAGS} ${INCLUDES}	\
					${DEFAULT_L} ${OBJS} -o ${NAME}

${DIR_OBJS}%.o: ${SRCS_DIR}%.c ${SHARED_DEPENDENCIES} ${DEFAULT_DEPENDENCIES}
				${CC} ${FLAGS} ${INCLUDES} -c $< -o $@

debug:			${DIR_OBJS}
				${MAKE_LIBFT} debug
				${MAKE} ${NAME_DEBUG}

${NAME_DEBUG}:	${OBJS_DEBUG}
				${CC} ${FLAGS_DEBUG} ${INCLUDES}	\
					${DEBUG_L} ${OBJS_DEBUG} -o ${NAME_DEBUG}

${DIR_OBJS}%_debug.o: ${SRCS_DIR}%.c ${SHARED_DEPENDENCIES} ${DEBUG_DEPENDENCIES}
					cc ${FLAGS_DEBUG} ${INCLUDES} -c $< -o $@

clean:
				${MAKE_LIBFT} clean
				${RMF} ${OBJS} ${OBJS_DEBUG} ${OBJS_TEST}

fclean:			clean
				${MAKE_LIBFT} fclean
				${RMF} ${NAME} ${NAME_DEBUG}

re:				fclean
				${MAKE} all

re_debug:		fclean
				${MAKE} debug

both:			all debug

test:			${DIR_OBJS}
				${MAKE_LIBFT}
				${MAKE} compile_tests

compile_tests:	${OBJS_TEST}
				@echo "Test compiled"

${TEST_OBJS_DIR}%.o: ${TEST_DIR}%.c ${SHARED_DEPENDENCIES} ${DEFAULT_DEPENDENCIES}
				${CC} ${FLAGS} ${INCLUDES} -c $< -o $@

${DIR_OBJS}: Makefile
				@echo ${OBJS} ${OBJS_TEST} | tr ' ' '\n'\
					| sed 's|\(.*\)/.*|\1|'\
					| sed 's/^/${MKDIR} /'\
					| sh -s
				@# Prints all OBJS. 1 per line
					@# Removes the .o file names
					@# Adds mkdir -p at start of each lines
					@# Executes the script (Creates all folders)

.PHONY:			all debug clean fclean re re_debug both test compile_tests
