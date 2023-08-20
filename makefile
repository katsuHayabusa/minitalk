# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saichaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/20 15:15:19 by saichaou          #+#    #+#              #
#    Updated: 2023/08/20 16:12:00 by saichaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR	= src/

SRC_SERVER	= server.c utils.c

SRC_CLIENT	= client.c utils.c

SRCS		= $(addprefix $(SRCS_DIR), $(SRC))

OBJS_DIR	= obj/

OBJ_SERVER	= ${SRC_SERVER:.c=.o}

OBJ_CLIENT	= ${SRC_CLIENT:.c=.o}

OBJS_SERVER	= $(addprefix $(OBJS_DIR), $(OBJ_SERVER))

OBJS_CLIENT	= $(addprefix $(OBJS_DIR), $(OBJ_CLIENT))

NAME_SERVER	= server

NAME_CLIENT	= client

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

INCS		= -I ./include/

LIBS		= include/ft_printf/libftprintf.a -L -I include/ft_printf/libftprintf.h

FT_PRINTF	= include/ft_printf/libftprintf.a

all:		${OBJS_DIR} ${NAME_SERVER} ${NAME_CLIENT}

${FT_PRINTF}:
			make -C include/ft_printf/

${NAME_SERVER}	: ${OBJS_SERVER} ${FT_PRINTF}
			${CC} ${CFLAGS} ${OBJS_SERVER} ${LIBS} -o ${NAME_SERVER}

${NAME_CLIENT}	: ${OBJS_CLIENT} ${FT_PRINTF}
			${CC} ${CFLAGS} ${OBJS_CLIENT} ${LIBS} -o ${NAME_CLIENT}

${OBJS_DIR}	:
			mkdir ${OBJS_DIR}

${OBJS_DIR}%.o: ${SRCS_DIR}%.c
			${CC} ${CFLAGS} -c $< -o $@ ${INCS}

clean:
			rm -rf ${OBJS_DIR} && make clean -C include/ft_printf/

fclean:		clean
			rm -f ${NAME_SERVER} && rm -f ${NAME_CLIENT} && make fclean -C include/ft_printf

re:			fclean all

.PHONY:		all clean fclean re
