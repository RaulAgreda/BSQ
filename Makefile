SRCS		= algorithm.c extract_map.c ft_atoi.c main.c map_analizer.c map_analizer2.c read_file.c matrix_funcs.c
OBJS		= ${SRCS:.c=.o}
CFLAGS		= -Wall -Wextra -Werror
DELINP		= .stdin.txt
NAME		= bsq
CC			= gcc
RM			= rm -rf
.PHONY		= all clean fclean re

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:	
			${RM} ${OBJS} ${DELINP}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

