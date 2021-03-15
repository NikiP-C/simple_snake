/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   snake.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: niki <niki@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 19:47:55 by niki          #+#    #+#                 */
/*   Updated: 2021/03/13 15:55:35 by niki          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_H

# define SNAKE_H
# include "mlx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define COLOR_SNAKE 0X6d88F6
# define COLOR_BG 0Xb19cd9
# define COLOR_FOOD 0XFF69B4
# define WINDOW_X 800
# define WINDOW_Y 500
# define SIZE_SQUARE 20

typedef struct s_img 
{
	void    *img_ptr;
	char    *address;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}				t_img;

enum direction {left, right, up, down};

typedef struct 			s_snake_b
{
	int					y;
	int					x;
	struct s_snake_b 	*next;
	struct s_snake_b	*previous;

}						t_snake_b;

typedef struct s_snake
{
	t_img		img;
	void 		*window;
	void		*mlx;
	int			start_s_x;
	int			end_s_x;
	int			start_s_y;
	int			end_s_y;
	int 		size_snake;
	int 		direction;
	int			grow;
	int			food_x;
	int			food_y;
	t_snake_b	*first;
	t_snake_b	*last;
}			t_snake;

void draw_background(t_snake *info);
void place_food(t_snake *info);
void my_pixel_put(t_img *img, int x, int y, unsigned int colour);
int fill_square(t_snake *info, int x, int y, int color);
int check_snake_body(int x, int y, t_snake *info);

#endif