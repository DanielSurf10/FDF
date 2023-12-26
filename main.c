#include <mlx.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img;
}	t_vars;

int	abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	ternary(int condition, int if_true, int if_false)
{
	if (condition)
		return (if_true);
	return (if_false);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	print_big_pixel(t_data *img, int x, int y, int color)
{
	x *= 10;
	y *= 10;
	for (int i = x; i < x + 10; i++)
		for (int j = y; j < y + 10; j++)
			my_mlx_pixel_put(img, i, j, color);
}

void	desenhar_linha(t_data *img, int x0, int y0, int x1, int y1, int cor)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	error;
	int	e2;

	dx = abs(x1 - x0);
	dy = -abs(y1 - y0);
	sx = ternary(x0 < x1, 1, -1);
	sy = ternary(y0 < y1, 1, -1);
	error = dx + dy;
	while (1)
	{
		print_big_pixel(img, x0, y0, cor);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * error;
		if (e2 >= dy)
		{
			if (x0 == x1)
				break ;
			error += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			if (y0 == y1)
				break ;
			error += dx;
			y0 += sy;
		}
	}
}

int	close(int keycode, t_vars *vars)
{
	if (keycode == 97)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_loop_end(vars->mlx);
	}
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*window;
	t_data	img;
	t_vars	vars;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 800, 800, "Hello world!");
	img.img = mlx_new_image(mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	for (int i = 0; i < 6; i++)
	{
		desenhar_linha(&img, 5 + i, 3 + i * 2, 24 - i, 13, 0x00FF00FF);
		desenhar_linha(&img, 24 - i, 13, 5 + i, 23 - i * 2, 0x00FFFF00);
		desenhar_linha(&img, 5 + i, 23 - i * 2, 5 + i, 3 + i * 2, 0x0000FFFF);
	}
	mlx_put_image_to_window(mlx, window, img.img, 0, 0);
	vars.mlx = mlx;
	vars.win = window;
	vars.img = &img;
	mlx_hook(window, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);

	return (EXIT_SUCCESS);
}
