/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: niki <niki@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/18 01:02:54 by niki          #+#    #+#                 */
/*   Updated: 2021/02/18 07:53:54 by niki          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <unistd.h>

int main(void)
{
	void	*mlx;
	void	*mlx_window;
	void	*mlx_image;
	int i;
	int j;

	i = 100;
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 300, 300, "hoi hoi hoi");
	mlx_image = mlx_new_image(mlx, 300, 300);
	while (i < 200)
	{
		j = 100;
		while (j < 200)
		{
			mlx_pixel_put(mlx, mlx_window, i, j, 455);
			j++;
		}
		i++;
	}	
	//mlx_put_image_to_window(mlx, mlx_window, mlx_image, 0, 0);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, mlx_window);
	mlx_destroy_image()
}