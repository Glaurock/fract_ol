/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_frac.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonnier <gmonnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 14:32:32 by gmonnier          #+#    #+#             */
/*   Updated: 2017/12/12 11:56:26 by gmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		init_mandel(t_env *env)
{
	env->param[env->current].move_x = 0;
	env->param[env->current].move_y = -0.525;
	env->param[env->current].zoom = 0.909;
	env->param[env->current].r_freq = 0.5;
	env->param[env->current].g_freq = 0.42;
	env->param[env->current].b_freq = -0.23;
}

static void		init_julia(t_env *env)
{
	env->param[env->current].move_x = START_MOVE_X;
	env->param[env->current].move_y = START_MOVE_Y;
	env->param[env->current].re_const = -0.82;
	env->param[env->current].im_const = 0.18;
	env->param[env->current].max_it = 40;
	env->param[env->current].color_code = 2;
	env->param[env->current].zoom = 0.620;
	env->param[env->current].r_freq = 0.03;
	env->param[env->current].g_freq = 1.89;
	env->param[env->current].b_freq = 0.05;
}

static void		init_ship(t_env *env)
{
	env->param[env->current].move_x = -0.023;
	env->param[env->current].move_y = -1.757;
	env->param[env->current].zoom = 17.44;
	env->param[env->current].r_freq = 0.63;
	env->param[env->current].g_freq = 0.27;
	env->param[env->current].b_freq = 0.21;
	env->param[env->current].max_it -= 5;
}

static void		init_creepy(t_env *env)
{
	env->param[env->current].move_x = -0.058;
	env->param[env->current].move_y = -0.75;
	env->param[env->current].zoom = 68.25;
	env->param[env->current].r_freq = 0.5;
	env->param[env->current].g_freq = 0.42;
	env->param[env->current].b_freq = -0.23;
}

void			init_params(t_env *env)
{
	env->param[env->current].max_it = MAX_IT;
	env->param[env->current].color_code = 1;
	env->help = 1;
	env->fractal[0] = &mandelbrot_set;
	env->fractal[1] = &julia_set;
	env->fractal[2] = &burning_ship;
	env->fractal[3] = &creepy_face;
	if (env->current == MANDEL)
		init_mandel(env);
	else if (env->current == JULIA)
		init_julia(env);
	else if (env->current == SHIP)
		init_ship(env);
	if (env->current == CREEPY)
		init_creepy(env);
}
