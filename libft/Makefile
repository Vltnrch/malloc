# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vroche <vroche@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/06 17:32:05 by vroche            #+#    #+#              #
#    Updated: 2015/10/18 14:58:58 by vroche           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HDR = -I./includes

CFLAGS = -Wall -Werror -Wextra

CLIB = is/ft_isalnum.c \
	is/ft_isalpha.c \
	is/ft_isascii.c \
	is/ft_isdigit.c \
	is/ft_isprint.c \
	is/ft_isspace.c \
	lst/ft_list_last.c \
	lst/ft_list_size.c \
	lst/ft_lstadd.c \
	lst/ft_lstadd_back.c \
	lst/ft_lstdel.c \
	lst/ft_lstdelone.c \
	lst/ft_lstiter.c \
	lst/ft_lstmap.c \
	lst/ft_lstnew.c \
	mem/ft_bzero.c \
	mem/ft_memalloc.c \
	mem/ft_memccpy.c \
	mem/ft_memchr.c \
	mem/ft_memcmp.c \
	mem/ft_memcpy.c \
	mem/ft_memdel.c \
	mem/ft_memmove.c \
	mem/ft_memset.c \
	mem/ft_realloc.c \
	put/ft_putchar.c \
	put/ft_putchar_fd.c \
	put/ft_putendl.c \
	put/ft_putendl_fd.c \
	put/ft_putnbr.c \
	put/ft_putnbr_fd.c \
	put/ft_putstr.c \
	put/ft_putstr_fd.c \
	str/ft_strcat.c \
	str/ft_strchr.c \
	str/ft_strclr.c \
	str/ft_strcmp.c \
	str/ft_strcpy.c \
	str/ft_strdel.c \
	str/ft_strdup.c \
	str/ft_strequ.c \
	str/ft_striter.c \
	str/ft_striteri.c \
	str/ft_strjoin.c \
	str/ft_strlcat.c \
	str/ft_strlen.c \
	str/ft_strmap.c \
	str/ft_strmapi.c \
	str/ft_strncat.c \
	str/ft_strncmp.c \
	str/ft_strncpy.c \
	str/ft_strnequ.c \
	str/ft_strnew.c \
	str/ft_strnstr.c \
	str/ft_strrchr.c \
	str/ft_strsplit.c \
	str/ft_strstr.c \
	str/ft_strsub.c \
	str/ft_strtrim.c \
	to/ft_atoi.c \
	to/ft_itoa.c \
	to/ft_lltoa.c \
	to/ft_lltouab.c \
	to/ft_tolower.c \
	to/ft_toupper.c

OLIB = $(CLIB:.c=.o)

CGNL = get_next_line/get_next_line.c

OGNL = $(CGNL:.c=.o)

CFPF = ft_printf/ft_ft.c \
	ft_printf/ft_perc.c \
	ft_printf/ft_perc_part1.c \
	ft_printf/ft_perc_part2.c \
	ft_printf/ft_perch.c \
	ft_printf/ft_percopt.c \
	ft_printf/ft_printf.c \
	ft_printf/ft_put_di.c \
	ft_printf/ft_put_ou.c \
	ft_printf/ft_put_p.c \
	ft_printf/ft_put_sc.c \
	ft_printf/ft_put_ss.c \
	ft_printf/ft_put_x.c \
	ft_printf/ft_wctoa.c

OFPF = $(CFPF:.c=.o)

O = $(OLIB) $(OGNL) $(OFPF)

$(NAME): $(O)
	ar rc $(NAME) $(O)
	ranlib $(NAME)

all: $(NAME)

solo: $(OLIB)
	ar rc $(NAME) $(OLIB)
	ranlib $(NAME)

ft_printf: $(OFPF) $(OLIB)
	ar rc $(NAME) $(OFPF) $(OLIB)
	ranlib $(NAME)

gnl: $(OGNL) $(OLIB)
	ar rc $(NAME) $(OGNL) $(OLIB)
	ranlib $(NAME)

%.o:%.c
	gcc $(CFLAGS) $(HDR) -c $< -o $@

clean:
	rm -f $(O)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
