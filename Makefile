# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arodiono <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 14:49:52 by arodiono          #+#    #+#              #
#    Updated: 2016/12/08 15:18:12 by arodiono         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
SRC = format_string.c search_format.c printer.c ft_strlen.c \
		ft_strjoin.c ft_printf.c ft_itoa_base.c flags.c util.c \
		get_char_and_string.c get_int_and_unsigned.c w_char.c \
		format_tools.c

OSRC =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OSRC)
	ar rc libftprintf.a $(OSRC)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	rm -f $(OSRC)

fclean: clean
	rm -f libftprintf.a

re: fclean all
