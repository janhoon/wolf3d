MAKEFLAGS += --silent
CC=gcc
CFLAGS=-Wall -Werror -Wextra -g3 -O3
NAME=fdf
LIBFT= -I Includes -I libft -L libft -lft
SOURCES=main.c\
		Sources/hooks.c\
		Sources/map_loader.c\
		Sources/draw.c\
		Sources/rotation.c\
		Sources/init_coords.c\
		Sources/draw_line.c

$(NAME): all

all :
	cd libft; make all
	echo "Libft Compiled"
	$(CC) $(CFLAGS) $(SOURCES) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME) -lm
	echo "FdF Compiled"

linux :
	cd libft; make all
	echo "Libft Compiled"
	$(CC) $(CFLAGS) $(SOURCES) $(LIBFT) $(shell pkg-config --libs --static mlx) -o $(NAME) -lm
	echo "FdF Compiled"

clean :
	cd libft; make clean

fclean : clean
	cd libft; make fclean
	rm $(NAME)
	echo "All build files have been removed"

re : fclean all
