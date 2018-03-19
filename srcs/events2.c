/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:26:57 by gmonnier          #+#    #+#             */
/*   Updated: 2017/12/12 12:12:53 by gmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			loop_event(int x, int y, void *param)
{
	t_env	*env;
	double	slope;

	env = (t_env*)param;
	if (env->current == JULIA)
	{
		if (abs(x - env->old_x) > MIN_MOVE_MOUSE
		|| abs(y - env->old_y) > MIN_MOVE_MOUSE)
		{
			slope = get_slope(0, WINDOW_WIDTH, -2, 2);
			env->param[env->current].re_const = map(x, 0, slope, -2);
			env->param[env->current].im_const = map(y, 0, slope, -2);
			env->old_x = x;
			env->old_y = y;
			draw(env);
		}
	}
	return (0);
}

int			mouse_wheel_event(int button, int x, int y, void *param)
{
	t_env	*env;

	env = (t_env*)param;
	(void)x;
	(void)y;
	if (button == 4)
		env->param[env->current].zoom *= ZOOM_FACTOR;
	if (button == 5)
		env->param[env->current].zoom /= ZOOM_FACTOR;
	draw(env);
	return (0);
}
