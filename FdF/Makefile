NAME = fdf
SRC = check_exit.c draw_map.c fdf_utils.c\
      fdf.c read_map.c set_position.c

CC = gcc

INCLUDES = libft/libft.a minilibx_macos/libmlx.a

FRAMEWORKS = -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror

OBJ = $(patsubst %.c,%.o,$(SRC))

all : $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C libft/ all
	$(MAKE) -C minilibx_macos/ all
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INCLUDES) $(FRAMEWORKS)

%.o : %.c fdf.h
	gcc $(CFLAGS) -c $< -o $@ -g

clean :
	rm -f $(OBJ)
	$(MAKE) -C libft/ clean
	$(MAKE) -C minilibx_macos/ clean

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re