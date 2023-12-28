// #include <mlx.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stdio.h>

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "MLX42/MLX42.h"
#define WIDTH 800
#define HEIGHT 800

// typedef struct	s_data
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }	t_data;
//
// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// 	void	*img;
// }	t_vars;
//
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

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;
//
// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

void	print_big_pixel(void *img, int x, int y, int color)
{
	x *= 10;
	y *= 10;
	for (int i = x; i < x + 10; i++)
		for (int j = y; j < y + 10; j++)
			mlx_put_pixel(img, i, j, color);
}
//
void	desenhar_linha(void *img, int x0, int y0, int x1, int y1, int cor)
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

// int	close(int keycode, t_vars *vars)
// {
// 	if (keycode == 97)
// 	{
// 		mlx_destroy_window(vars->mlx, vars->win);
// 		mlx_loop_end(vars->mlx);
// 	}
// 	return (0);
// }
//
// int	main(void)
// {
// 	void	*mlx;
// 	void	*window;
// 	t_data	img;
// 	t_vars	vars;
//
// 	mlx = mlx_init();
// 	window = mlx_new_window(mlx, 800, 800, "Hello world!");
// 	img.img = mlx_new_image(mlx, 800, 800);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	for (int i = 0; i < 6; i++)
// 	{
// 		desenhar_linha(&img, 5 + i, 3 + i * 2, 24 - i, 13, 0x00FF00FF);
// 		desenhar_linha(&img, 24 - i, 13, 5 + i, 23 - i * 2, 0x00FFFF00);
// 		desenhar_linha(&img, 5 + i, 23 - i * 2, 5 + i, 3 + i * 2, 0x0000FFFF);
// 	}
// 	mlx_put_image_to_window(mlx, window, img.img, 0, 0);
// 	vars.mlx = mlx;
// 	vars.win = window;
// 	vars.img = &img;
// 	mlx_hook(window, 2, 1L<<0, close, &vars);
// 	mlx_loop(vars.mlx);
//
// 	return (EXIT_SUCCESS);
// }

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void ft_hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
}

int	main(void)
{

	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		ft_error();

	/* Do stuff */

	// Create and display the image.
	mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	memset(img->pixels, 0xAF, img->width * img->height * sizeof(int32_t));

	// Even after the image is being displayed, we can still modify the buffer.
	mlx_put_pixel(img, 10, 10, 0xFF0000FF);

	for (int i = 0; i < 6; i++)
	{
		desenhar_linha(img, 5 + i, 3 + i * 2, 24 - i, 13, 0x00FF00FF);
		desenhar_linha(img, 24 - i, 13, 5 + i, 23 - i * 2, 0x00FFFF00);
		desenhar_linha(img, 5 + i, 23 - i * 2, 5 + i, 3 + i * 2, 0x0000FFFF);
	}

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
