/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   begin.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: niki <niki@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 21:57:49 by niki          #+#    #+#                 */
/*   Updated: 2021/03/13 01:44:05 by niki          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

void my_pixel_put(t_img *img, int x, int y, unsigned int colour) 
{
    char	*dst;
    int		offset;

	offset = y * img->line_size + x * (img->bits_per_pixel / 8); 
	dst = img->address + offset;
	*(unsigned int *)dst = colour;
}

void draw_snake_start(t_snake *info)
{	
	info->start_s_x = SIZE_SQUARE;
	info->start_s_y = SIZE_SQUARE;
	info->end_s_x = SIZE_SQUARE;
	info->end_s_y = SIZE_SQUARE;

	int x = info->start_s_x;
	int y = info->start_s_y;

	while (x < SIZE_SQUARE * 2)
	{
		while (y < SIZE_SQUARE * 2)
		{
			my_pixel_put(&info->img, x, y, COLOR_SNAKE);
			y++;
		}
		y = SIZE_SQUARE;
		x++;
	}
}

int	start_linked_list(t_snake *info)
{
	t_snake_b *temp;

	temp = malloc(sizeof(t_snake_b));
	temp->y = info->start_s_y;
	temp->x = info->start_s_x;
	temp->next = NULL;
	temp->previous = NULL;

	info->first = temp;
	info->last = temp;
	
	return (1);
}

void	draw_background(t_snake	*info)
{
	int x = 0;
	int y = 0;

	info->size_snake = 1;
	start_linked_list(info);
	while (x < WINDOW_X)
	{
		while (y < WINDOW_Y)
		{
			my_pixel_put(&info->img, x, y, COLOR_BG);
			y++;
		}
		y = 0;
		x++;
	}
	draw_snake_start(info);
	place_food(info);
}