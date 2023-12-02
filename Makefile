# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 13:27:49 by psegura-          #+#    #+#              #
#    Updated: 2023/12/02 20:10:45 by psegura-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = automatas

SRCS =							\
		srcs/main.c				\


OBJS = $(SRCS:.c=.o)

LIB = libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I inc -I libft

$(NAME): $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

all: $(NAME)

clean:
	make clean -C libft
	@rm -rf $(OBJS)

fclean: clean
	make fclean -C libft
	@rm -f $(NAME)

re:: fclean
re:: all

.PHONY: all clean fclean re
