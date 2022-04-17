NAME	=	minitalk

NAMES	=	server

NAMEC	=	client

SRCSS	=	./srcs/server.c \
			./srcs/exit.c

SRCSC	=	./srcs/client.c \
			./srcs/exit.c

HEADER	=	./srcs/minitalk.h

LIBFT	=	./libft/libft.a

LIBPF	=	./ft_printf/libftprintf.a

OBJSS	=	${SRCSS:%.c=%.o}

OBJSC	=	${SRCSC:%.c=%.o}

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

LFLAGS	=	-L ./libft -lft

PFLAGS	=	-L ./ft_printf -lftprintf

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
			make -C ./libft all

${LIBPF}:
			make -C ./ft_printf all

bonus	:
			make -C ./srcs_bonus all

clean	:
			make -C ./srcs clean
			make -C ./srcs_bonus clean
			make -C ./libft clean
			make -C ./ft_printf clean

fclean	:	clean
			${RM} ${NAMES}
			${RM} ${NAMEC}
			${RM} ${LIBFT}
			${RM} ${LIBPF}

re		:	fclean all
