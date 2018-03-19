/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonnier <gmonnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 09:56:04 by gmonnier          #+#    #+#             */
/*   Updated: 2017/12/12 11:54:31 by gmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(t_env *env, int n, double re, double im)
{
	double index;

	if (n == env->param[env->current].max_it)
		return (0);
	if (env->param[env->current].color_code == 1)
	{
		index = n + 1 - log(log(sqrt(re * re + im * im))) / log(2);
		return (to_rgb(0,
		cos(env->param[env->current].r_freq * index) * 127.5 + 127.5,
		cos(env->param[env->current].g_freq * index + 1) * 127.5 + 127.5,
		cos(env->param[env->current].b_freq * index + 2) * 127.5 + 127.5));
	}
	if (env->param[env->current].color_code == 2)
	{
		return (to_rgb(0,
		(1 - n / env->param[env->current].max_it) *
		fmod(255 * env->param[env->current].r_freq, 255),
		fmod(255 * env->param[env->current].g_freq, 255) * n /
		env->param[env->current].max_it,
		fmod(255 * env->param[env->current].b_freq, 255) * n /
		env->param[env->current].max_it));
	}
	return (0);
}

int		to_rgb(int a, int r, int g, int b)
{
	return ((a << 24) | (r << 16) | (g << 8) | b);
}

t_rgb	give_rgb(int hex)
{
	t_rgb color;

	color.a = (hex >> 24) & 0xff;
	color.r = (hex >> 16) & 0xff;
	color.g = (hex >> 8) & 0xff;
	color.b = hex & 0xff;
	return (color);
}

int		to_int(t_rgb rgb)
{
	return ((rgb.a << 24) | (rgb.r << 16) | (rgb.g << 8) | rgb.b);
}
