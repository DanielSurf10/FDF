/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:26:27 by dpoveda-          #+#    #+#             */
/*   Updated: 2023/12/30 15:38:51 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <stdlib.h>

int	close_win(t_vars *vars)
{
	free_all(vars);
	exit (EXIT_SUCCESS);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		close_win(vars);
	if (keycode == KEY_R)
		reset_vars(vars);
	if (keycode == KEY_W || keycode == KEY_S
		|| keycode == KEY_A || keycode == KEY_D)
		handle_move(keycode, vars);
	if (keycode == KEY_UP || keycode == KEY_DOWN)
		handle_zoom(keycode, vars);
	if (keycode == KEY_U || keycode == KEY_J || keycode == KEY_I
		|| keycode == KEY_K || keycode == KEY_O || keycode == KEY_L)
		handle_rot(keycode, vars);
	if (keycode == KEY_MINUS || keycode == KEY_PLUS)
		handle_flattening(keycode, vars);
	if (keycode == KEY_P)
	{
		if (vars->iso)
			vars->iso = 0;
		else
			vars->iso = 1;
	}
	if (keycode == KEY_LEFT)
	{
		if (vars->line_tracer)
			vars->line_tracer = 0;
		else
			vars->line_tracer = 1;
	}
	draw(vars);
	return (0);
}
