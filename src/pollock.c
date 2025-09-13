/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pollock.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 10:32:42 by agiedroi          #+#    #+#             */
/*   Updated: 2025/09/13 14:38:50 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pollock.h"
#define WIDTH 1280
#define HEIGHT 720

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);

int	main(void)
{
	t_mlx_data	data;
	t_data	img;
	int		x;
	int		y;

	srand(time(NULL));
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (EXIT_FAILURE);
	img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	data.mlx_win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "pollock");
	if (data.mlx_win == NULL)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		return (EXIT_FAILURE);
	}
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
	mlx_put_image_to_window(data.mlx, data.mlx_win, img.img, 0, 0);
	mlx_string_put(data.mlx, data.mlx_win, WIDTH * 0.8, HEIGHT * 0.95, rand() % 0x1000000, "pollock.");
	mlx_loop(data.mlx);
	return (0);
}

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
