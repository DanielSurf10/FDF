#include <mlx.h>
#include <stdlib.h>
#include <string.h>


int	main(void)
{
	void *mlx = mlx_init(256, 256, "MLX42", 1);

	void *mlx_win = mlx_new_window(mlx, 800, 600, "Hello world!");
	mlx_loop(mlx);

	return (EXIT_SUCCESS);
}
