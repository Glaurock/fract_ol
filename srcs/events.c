/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:47:24 by gmonnier          #+#    #+#             */
/*   Updated: 2017/12/12 12:13:31 by gmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		move_event(int keycode, t_env *env)
{
	if (keycode == KEY_UP)
		env->param[env->current].move_x -= MOVE_SPEED /
	env->param[env->current].zoom;
	else if (keycode == KEY_DOWN)
		env->param[env->current].move_x += MOVE_SPEED /
	env->param[env->current].zoom;
	else if (keycode == KEY_LEFT)
		env->param[env->current].move_y -= MOVE_SPEED /
	env->param[env->current].zoom;
	else if (keycode == KEY_RIGHT)
		env->param[env->current].move_y += MOVE_SPEED /
	env->param[env->current].zoom;
}

void		color_event(int keycode, t_env *env)
{
	if (keycode == KEY_1)
		env->param[env->current].color_code = 1;
	else if (keycode == KEY_2)
		env->param[env->current].color_code = 2;
	else if (keycode == KEY_R)
		env->param[env->current].r_freq += INC_COLORS;
	else if (keycode == KEY_G)
		env->param[env->current].g_freq += INC_COLORS;
	else if (keycode == KEY_B)
		env->param[env->current].b_freq += INC_COLORS;
	else if (keycode == KEY_E)
		env->param[env->current].r_freq -= INC_COLORS;
	else if (keycode == KEY_F)
		env->param[env->current].g_freq -= INC_COLORS;
	else if (keycode == KEY_V)
		env->param[env->current].b_freq -= INC_COLORS;
}

void		accuracy_event(int keycode, t_env *env)
{
	if (keycode == KEY_N)
		env->param[env->current].max_it += 5;
	else if (keycode == KEY_M)
		env->param[env->current].max_it -= 5;
	env->param[env->current].max_it <= 0 ?
	env->param[env->current].max_it = 5 : 0;
}

void		change_frac(t_env *env)
{
	char *tmp;

	mlx_destroy_window(env->mlx, env->win[env->current]);
	env->current += 1;
	env->current %= NB_FRAC;
	tmp = ft_itoa(env->current + 1);
	choose_frac(tmp, env);
	free(tmp);
	draw_window(env);
}

int			key_event(int keycode, void *param)
{
	t_env *env;

	env = (t_env*)param;
	if (keycode == KEY_ESCAPE)
		die(NULL, env);
	move_event(keycode, env);
	color_event(keycode, env);
	accuracy_event(keycode, env);
	if (keycode == KEY_C)
		change_frac(env);
	else if (keycode == KEY_ENTER)
		init_params(env);
	else if (keycode == KEY_H)
		env->help = env->help ? 0 : 1;
	draw(env);
	return (0);
}
