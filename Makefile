# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 08:08:33 by kkamashi          #+#    #+#              #
#    Updated: 2021/03/27 13:36:10 by kkamashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
PUSH_SWAP = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = # -g -fsanitize=address
DEPENDENCY_OPTION = -MMD -MP -MF
LIBS_DIR = ./libs
RM = rm -f

INCLUDE = -I./includes/ \
			-I./libs/libft/ \
			-I./libs/get_next_line/

SRCS = ${shell find ./srcs/utils -type f -name "*.c"}
SRCS += ${shell find ./debug -type f -name "*.c"}
SRCS += ${shell find ./srcs/commands -type f -name "*.c"}
SRCS += ${shell find ./srcs/commands_with_stdout -type f -name "*.c"}
SRCS += ${shell find ./libs/get_next_line -type f -name "*.c"}
SRCS_CHECKER = ${shell find ./srcs/checker_srcs -type f -name "*.c"}
SRCS_PUSH_SWAP = ${shell find ./srcs/push_swap_srcs -type f -name "*.c"}

OBJS = $(SRCS:.c=.o)
DEPS = ${SRCS:.c=.d}
OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)
DEPS_CHECKER = ${SRCS_CHECKER:.c=.d}
OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)
DEPS_PUSH_SWAP = ${SRCS_PUSH_SWAP:.c=.d}
LIBFT = ./libs/libft/libft.a

.c.o:
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDE) -c $(DEPENDENCY_OPTION) ${<:.c=.d} \
	$< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_CHECKER) $(OBJS_PUSH_SWAP)
	$(MAKE) bonus -C ./libs/libft
	${CC} ${CFLAGS} -o $(CHECKER) $(DEBUG) $(LIBFT) ${OBJS_CHECKER} $(OBJS)
	${CC} ${CFLAGS} -o $(PUSH_SWAP) $(DEBUG) $(LIBFT) ${OBJS_PUSH_SWAP} $(OBJS)

clean:
	$(RM) $(OBJS) $(OBJS_CHECKER) $(OBJS_PUSH_SWAP) $(DEPS) $(DEPS_CHECKER) $(DEPS_PUSH_SWAP)

fclean: clean
	$(MAKE) fclean -C ./libs/libft
	$(RM) $(CHECKER) $(PUSH_SWAP)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS) $(DEPS_CHECKER) $(DEPS_PUSH_SWAP)
