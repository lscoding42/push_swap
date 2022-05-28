# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 16:09:15 by lhafsi            #+#    #+#              #
#    Updated: 2022/05/23 18:47:39 by lhafsi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	push_swap.c\
			arg_check/arg_check_utils.c\
			arg_check/arg_check_1.c\
			operations/operations.c\
			operations/operations_utils.c\
			operations/operations_caller.c\
			algo/algo_order.c\

OBJS = ${SRCS:.c=.o}

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} libft/libft.a -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
