SRCS		= algorithm.c extract_map.c ft_atoi.c main.c map_analizer.c map_analizer2.c read_file.c

OBJS		= ${SRCS:.c=.o}

CFLAGS		= -Wall -Wextra -Werror

NAME		= a.out

CC			= cc

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

clean:	
			rm ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

