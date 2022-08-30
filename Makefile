SRCS		= algorithm.c extract_map.c ft_atoi.c main.c map_analizer.c map_analizer2.c read_file.c matrix_funcs.c analyze_input.c

OBJS		= ${SRCS:.c=.o}

CFLAGS		= -Wall -Wextra -Werror

NAME		= bsq

CC			= gcc

.PHONY		= all clean fclean re

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:	
			rm ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

