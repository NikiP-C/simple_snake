/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   snake.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: niki <niki@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 19:47:57 by niki          #+#    #+#                 */
/*   Updated: 2021/03/14 01:58:28 by niki          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

void dead(t_snake *info)
{
	printf("YOU DIED - Score = %i\n", info->size_snake);
	exit(0);
}

int	fill_square(t_snake *info, int x, int y, int color)
{
	int i  = 0;
	int j = 0;

	while (i < SIZE_SQUARE)
	{
		while (j < SIZE_SQUARE)
		{
			my_pixel_put(&info->img, x + i, y + j, color);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int draw_snake(t_snake *info)
{
	t_snake_b *temp = malloc(sizeof(t_snake_b));
	if (temp == NULL)
		exit(0);
	fill_square(info, info->start_s_x, info->start_s_y, COLOR_SNAKE);
	fill_square(info, info->last->x, info->last->y, COLOR_BG);

	temp->x = info->start_s_x;
	temp->y = info->start_s_y;
	temp->next = info->first;
	if (info->first->next == NULL && info->grow == 0)
		temp->next = NULL;
	temp->previous = NULL;
	info->first->previous = temp;
	info->first = temp;
	if (info->grow == 0)
	{
		if (info->size_snake == 1)
			info->last = info->first;
		else
		{
			temp = info->last->previous;
			free(info->last);
			info->last = temp;
			info->last->next = NULL;
		}
	}
	else
	{
	
		info->grow--;
		if (info->size_snake == 1)
		{
			info->last->previous = info->first;
		}
		info->size_snake++;
	}
	return (1);
}

int move(t_snake *info)
{
	//usleep(50000);
	if (info->direction == 5)
		return (0);
	if (info->direction == left)
		info->start_s_x -= SIZE_SQUARE;
	else if (info->direction == right)
		info->start_s_x += SIZE_SQUARE;
	else if (info->direction == up)
		info->start_s_y -= SIZE_SQUARE;
	else if (info->direction == down)
		info->start_s_y += SIZE_SQUARE;
	if (info->start_s_x < 0 || info->start_s_x >= WINDOW_X || \
	info->start_s_y < 0 || info->start_s_y >= WINDOW_Y)
		dead(info);
	if (check_snake_body(info->start_s_x, info->start_s_y, info))
		dead(info);
	draw_snake(info);
	if (info->start_s_x == info->food_x && info->start_s_y == info->food_y)
	{
		info->grow += 5;
		place_food(info);
	}
	mlx_put_image_to_window(info->mlx, info->window, info->img.img_ptr, 0, 0);
	return (1);
}

int keypress(int keycode, t_snake *info)
{
	if (keycode == 53)
		exit(0);
	else if ((keycode == 126 || keycode == 13) && info->direction != down)
		info->direction = up;
	else if ((keycode == 125|| keycode == 1)  && info->direction != up)
		info->direction = down;
	else if ((keycode == 123 || keycode == 0)  && info->direction != right)
		info->direction = left;
	else if ((keycode == 124 || keycode == 2)  && info->direction != left)
		info->direction = right;
	return (1);

}

int main(void)
{
	t_snake info;

	info.grow = 0;
	info.direction = 5;
	info.mlx = mlx_init();
	info.window = mlx_new_window(info.mlx, WINDOW_X, WINDOW_Y, "Snake");
	info.img.img_ptr = mlx_new_image(info.mlx, WINDOW_X, WINDOW_Y);
	info.img.address = mlx_get_data_addr(info.img.img_ptr, &info.img.bits_per_pixel, &info.img.line_size, &info.img.endian);
	draw_background(&info);
	mlx_put_image_to_window(info.mlx, info.window, info.img.img_ptr, 0, 0);
	mlx_hook(info.window, 2, 1l << 0, keypress, &info);
	mlx_loop_hook(info.mlx, move, &info);
	mlx_loop(info.mlx);
}