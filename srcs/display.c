/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonnier <gmonnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:17:51 by gmonnier          #+#    #+#             */
/*   Updated: 2017/12/12 12:01:28 by gmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_window(t_env *env)
{
	init_params(env);
	draw(env);
	mlx_hook(env->win[env->current], KeyPress, KeyPressMask, key_event, env);
	mlx_hook(env->win[env->current], MotionNotify, PointerMotionMask,
	loop_event, env);
	mlx_hook(env->win[env->current], ButtonPress, Button4Mask,
	mouse_wheel_event, env);
	mlx_loop(env->mlx);
}

void		draw(t_env *env)
{
	size_t	y;
	size_t	x;

	mallcheck(env->img.img_ptr = mlx_new_image(env->mlx,
	WINDOW_WIDTH, WINDOW_HEIGHT));
	env->img.data = (int*)mlx_get_data_addr(env->img.img_ptr, &env->img.bpp,
	&env->img.size_l, &env->img.endian);
	y = -1;
	while (++y < WINDOW_HEIGHT)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
			env->fractal[env->current](env, x, y);
	}
	mlx_put_image_to_window(env->mlx, env->win[env->current],
	env->img.img_ptr, 0, 0);
	mlx_destroy_image(env->mlx, env->img.img_ptr);
	if (env->help)
		display_help(env);
}

int			choose_frac(char *arg, t_env *env)
{
	char	tmp[20];
	int		ret;

	if (!ft_strcmp(arg, "1") || !ft_strcmp(arg, "2") || !ft_strcmp(arg, "3") ||
	!ft_strcmp(arg, "4"))
	{
		ret = ft_atoi(arg) - 1;
		env->current = ret;
		if (ret == 0)
			ft_strcpy(tmp, "Mandelbrot_set");
		else if (ret == 1)
			ft_strcpy(tmp, "Julia_set");
		else if (ret == 1)
			ft_strcpy(tmp, "Burning_ship");
		else if (ret == 1)
			ft_strcpy(tmp, "Creepy_face");
		mallcheck(env->win[env->current] =
		mlx_new_window(env->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, tmp));
		return (1);
	}
	return (-1);
}
