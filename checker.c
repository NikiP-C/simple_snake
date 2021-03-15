/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: niki <niki@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/13 15:47:48 by niki          #+#    #+#                 */
/*   Updated: 2021/03/13 17:04:11 by niki          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

int check_snake_body(int x, int y, t_snake *info)
{
	t_snake_b *temp;

	temp = info->first;
	while (temp != NULL)
	{
		if (temp->x == x)
		{
			if (temp->y == y)
			{
				return (1);
			}
		}
		temp = temp->next;
	}
	return (0);
}