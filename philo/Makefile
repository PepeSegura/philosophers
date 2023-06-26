# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 12:09:16 by psegura-          #+#    #+#              #
#    Updated: 2023/06/26 05:43:12 by psegura-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS =						\
		srcs/actions.c		\
		srcs/init_data.c	\
		srcs/routines.c		\
		srcs/main.c			\
		srcs/parser.c		\
		srcs/time.c			\
		srcs/utils.c		\

OBJS = $(SRCS:%.c=objs/%.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=thread
CFLAGS += -I inc
LDFLAGS = -lpthread

$(NAME): objs $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME)
	@echo "🧵 philo Done 🍽"

objs:
	@mkdir -p	objs/srcs/	\

objs/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@rm -rf objs

fclean: clean
	@rm -f $(NAME)

re: fclean all

norma:
	@echo 6e6f726d696e65747465207372637320696e6320313e2f6465762f6e756c6c3b206966205b5b20243f202d65712030205d5d3b207468656e206e6f726d696e65747465207372637320696e633b20656c7365206e6f726d696e65747465207372637320696e63207c206772657020274572726f7227203b206669 | xxd -r -p | zsh

.PHONY: all clean fclean re norma
