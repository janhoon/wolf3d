#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By:  <>                                        +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/08/02 12:22:37 by                   #+#    #+#             *#
#*   Updated: 2016/08/25 15:42:58 by                  ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = libft.a
FLAGS = -Wall -Wextra -Werror -g3 -O3
SRC = ft_bzero.c\
	ft_getchar.c\
	ft_getchar_fd.c\
	ft_memccpy.c\
	ft_memcpy.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memmove.c\
	ft_memset.c\
	get_next_line.c\
	ft_realloc.c\
	ft_strlen.c\
	ft_putchar.c\
	ft_putstr.c\
	ft_strtok.c\
	ft_strdup.c\
	ft_strcpy.c\
	ft_listalpha.c\
	ft_strcmp.c\
	ft_putnbr.c\
	ft_strsplit.c\
	ft_atoi.c\
	ft_strsplitcount.c\
	ft_isdigit.c\
	ft_isalpha.c\
	ft_ishexa.c\
	ft_hextoi.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -c $(SRC)
	ar cr $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
