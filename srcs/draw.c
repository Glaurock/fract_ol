/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonnier <gmonnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:39:35 by gmonnier          #+#    #+#             */
/*   Updated: 2017/12/12 11:39:21 by gmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_set(t_env *env, size_t x, size_t y)
{
	t_complex	c;
	t_complex	z;
	int			n;
	double		tmp;

	n = 0;
	c.r = (2.0 * x - WINDOW_WIDTH) / (WINDOW_WIDTH *
	env->param[env->current].zoom) + env->param[env->current].move_y;
	c.i = (2.0 * y - WINDOW_HEIGHT) / (WINDOW_HEIGHT *
	env->param[env->current].zoom) + env->param[env->current].move_x;
	z.r = 0;
	z.i = 0;
	while (z.r * z.r + z.i * z.i <= MAX_VALUE
	&& n < env->param[env->current].max_it)
	{
		tmp = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.r * z.i + c.i;
		z.r = tmp;
		n++;
	}
	env->img.data[y * WINDOW_WIDTH + x] = get_color(env, n, z.r, z.i);
}

void	julia_set(t_env *env, size_t x, size_t y)
{
	int			n;
	t_complex	z;
	double		tmp;

	n = 0;
	z.r = (2.0 * x - WINDOW_WIDTH) / (WINDOW_WIDTH *
	env->param[env->current].zoom) + env->param[env->current].move_y;
	z.i = (2.0 * y - WINDOW_HEIGHT) / (WINDOW_HEIGHT *
	env->param[env->current].zoom) + env->param[env->current].move_x;
	while (z.r * z.r + z.i * z.i <= MAX_VALUE
	&& n < env->param[env->current].max_it)
	{
		tmp = z.r * z.r - z.i * z.i + env->param[env->current].re_const;
		z.i = 2 * z.r * z.i + env->param[env->current].im_const;
		z.r = tmp;
		n++;
	}
	env->img.data[y * WINDOW_WIDTH + x] = get_color(env, n, z.i, z.r);
}

void	burning_ship(t_env *env, size_t x, size_t y)
{
	t_complex	c;
	t_complex	z;
	int			n;
	double		tmp;

	n = 0;
	c.r = (2.0 * x - WINDOW_WIDTH) / (WINDOW_WIDTH
	* env->param[env->current].zoom) + env->param[env->current].move_y;
	c.i = (2.0 * y - WINDOW_HEIGHT) / (WINDOW_HEIGHT
	* env->param[env->current].zoom) + env->param[env->current].move_x;
	z.r = 0;
	z.i = 0;
	while (z.r * z.r + z.i * z.i <= MAX_VALUE
	&& n < env->param[env->current].max_it)
	{
		tmp = fabs(z.r * z.r - z.i * z.i + c.r);
		z.i = fabs(2 * z.r * z.i + c.i);
		z.r = tmp;
		n++;
	}
	env->img.data[y * WINDOW_WIDTH + x] = get_color(env, n, z.r, z.i);
}

void	creepy_face(t_env *env, size_t x, size_t y)
{
	t_complex	c;
	t_complex	z;
	int			n;
	double		tmp;

	n = 0;
	c.r = (2.0 * x - WINDOW_WIDTH) / (WINDOW_WIDTH
	* env->param[env->current].zoom) + env->param[env->current].move_y;
	c.i = (2.0 * y - WINDOW_HEIGHT) / (WINDOW_HEIGHT
	* env->param[env->current].zoom) + env->param[env->current].move_x;
	z.r = 0;
	z.i = 0;
	while (z.r * z.r + z.i * z.i <= MAX_VALUE
	&& n < env->param[env->current].max_it)
	{
		tmp = fabs(2 * z.r * z.r - z.i * z.i + c.r);
		z.i = 2 * z.r * z.i + c.i;
		z.r = tmp;
		n++;
	}
	env->img.data[y * WINDOW_WIDTH + x] = get_color(env, n, z.r, z.i);
}
