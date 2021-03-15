# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: niki <niki@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/18 01:35:57 by niki          #+#    #+#                  #
#    Updated: 2021/03/13 15:55:52 by niki          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


NAME = snake

SRC = snake.c place_food.c begin.c checker.c

INC = -Lmlx -lmlx -framework OpenGL -framework AppKit

FLAGS = -Wall -Werror -Wextra 

all: $(NAME)

$(NAME): $(SRC)
	gcc $(FLAGS) $(SRC) $(INC) -o $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all