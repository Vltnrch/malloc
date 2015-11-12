# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vroche <vroche@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/06 17:32:05 by vroche            #+#    #+#              #
#    Updated: 2015/10/29 18:23:16 by vroche           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

CFLAGS = -Wall -Werror -Wextra

C = management.c \
	malloc.c \
	free.c 

O = $(C:.c=.o)

$(NAME): $(O)
	gcc -o $(NAME) -shared $(O)
	ln -s $(NAME) libft_malloc.so

all: $(NAME)

%.o:%.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(O)

fclean: clean
	rm -f $(NAME)
	rm libft_malloc.so

re: fclean all

.PHONY: all clean fclean re
