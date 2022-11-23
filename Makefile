# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 16:09:15 by lhafsi            #+#    #+#              #
#    Updated: 2022/11/18 04:20:36 by lhafsi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	push_swap.c\
			algo/algo_order_small.c\
			algo/algo_order_big.c\
			algo/algo_utils_minmax.c\
			arg_check/arg_check_utils.c\
			arg_check/arg_check_1.c\
			arg_check/error_manager.c\
			operations/operations.c\
			operations/operations_call_push.c\
			operations/operations_call_swap.c\
			operations/operations_call_rotate.c\
			operations/operations_call_reverse.c\
			list_init.c\

OBJS = ${SRCS:.c=.o}

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
