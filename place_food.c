/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   place_food.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: niki <niki@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 21:57:51 by niki          #+#    #+#                 */
/*   Updated: 2021/03/13 15:55:41 by niki          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

void place_food(t_snake *info)
{
	int x;
	int y;
	int i = 0;
	int j = 0;
	int check = 1;
	time_t t;

	srand(time(&t));

	while (check == 1)
	{
		x = (rand() % WINDOW_X);
		info->food_x = x - (x % SIZE_SQUARE);
		y = (rand() % WINDOW_Y );
		info->food_y = y - (y % SIZE_SQUARE);
		check = check_snake_body(info->food_x, info->food_y, info);
	}

	while (i < SIZE_SQUARE)
	{
		while (j < SIZE_SQUARE)
		{
			my_pixel_put(&info->img, info->food_x + i, info->food_y + j, COLOR_FOOD);
			j++;
		}
		j = 0;
		i++;
	}
}