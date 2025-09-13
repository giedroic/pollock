/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pollock.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 10:32:42 by agiedroi          #+#    #+#             */
/*   Updated: 2025/09/13 10:58:20 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <time.h>
#define WIDTH 420
#define HEIGHT 420

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;

	srand(time(NULL));
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "pollock");
	x = WIDTH * 0.1;
	while (x < WIDTH * 0.9)
	{
		y = HEIGHT * 0.1;
		while (y < HEIGHT * 0.9)
		{
			mlx_pixel_put(mlx, mlx_win, x, y, rand() % 0x1000000);
			++y;
		}
		++x;
	}
	mlx_string_put(mlx, mlx_win, WIDTH * 0.8, HEIGHT * 0.95, rand() % 0x1000000, "pollock.");
	mlx_loop(mlx);
	return (0);
}
