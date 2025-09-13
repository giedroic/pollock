/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pollock.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 10:32:42 by agiedroi          #+#    #+#             */
/*   Updated: 2025/09/13 11:56:17 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pollock.h"
#define WIDTH 420
#define HEIGHT 420

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x;
	int		y;

	srand(time(NULL));
	mlx = mlx_init();
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "pollock");
	x = WIDTH * 0.1;
	while (x < WIDTH * 0.9)
	{
		y = HEIGHT * 0.1;
		while (y < HEIGHT * 0.9)
		{
			ft_mlx_pixel_put(&img, x, y, rand() % 0x1000000);
			++y;
		}
		++x;
	}
	mlx_string_put(mlx, mlx_win, WIDTH * 0.8, HEIGHT * 0.95, rand() % 0x1000000, "pollock.");
	mlx_loop(mlx);
	return (0);
}

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
