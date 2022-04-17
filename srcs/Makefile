NAME	=	minitalk

NAMES	=	../server

NAMEC	=	../client

SRCSS	=	server.c \
			exit.c

SRCSC	=	client.c \
			exit.c

HEADER	=	minitalk.h

LIBFT	=	../libft/libft.a

LIBPF	=	../ft_printf/libftprintf.a

OBJSS	=	${SRCSS:%.c=%.o}

OBJSC	=	${SRCSC:%.c=%.o}

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

LFLAGS	=	-L ../libft -lft

PFLAGS	=	-L ../ft_printf -lftprintf

RM		=	rm -f

.PHONY	:	all clean fclean re

all		:	${NAME}

%.o 	:	%.c ${HEADER}
			${CC} ${CFLAGS} -c $< -o $@

${NAME}	:	${NAMEC} ${NAMES}

${NAMES}:	${LIBFT} ${LIBPF} ${OBJSS}
			${CC} ${CFLAGS} ${OBJSS} ${LFLAGS} ${PFLAGS} -o ${NAMES}

${NAMEC}:	${LIBFT} ${LIBPF} ${OBJSC}
			${CC} ${CFLAGS} ${OBJSC} ${LFLAGS} ${PFLAGS} -o ${NAMEC}

${LIBFT}:
			make -C ../libft all

${LIBPF}:
			make -C ../ft_printf all

clean	:
			${RM} ${OBJSS}
			${RM} ${OBJSC}

fclean	:	clean
			${RM} ${NAMES}
			${RM} ${NAMEC}

re		:	fclean all
