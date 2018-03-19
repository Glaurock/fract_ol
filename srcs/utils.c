/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonnier <gmonnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:45:58 by gmonnier          #+#    #+#             */
/*   Updated: 2017/12/12 12:53:16 by gmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	die(char *msg, t_env *env)
{
	ft_putendl_fd(msg, 2);
	if (env)
	{
		if (env->win[env->current])
			mlx_destroy_window(env->mlx, env->win[env->current]);
		free(env);
	}
	exit(EXIT_FAILURE);
}

void	mallcheck(void *param)
{
	if (param == NULL)
	{
		ft_putendl_fd("Malloc error", 2);
		exit(EXIT_FAILURE);
	}
}

double	get_slope(double min, double max, double new_min, double new_max)
{
	return (1.0 * (new_max - new_min) / (max - min));
}

double	map(double nb, double min, double slope, double new_min)
{
	return (new_min + slope * (nb - min));
}

void	display_help(t_env *env)
{
	mlx_string_put(env->mlx, env->win[env->current],
	10, 05, 0xffffff, "Show/hide help : H");
	mlx_string_put(env->mlx, env->win[env->current],
	10, 20, 0xffffff, "Reset : enter");
	mlx_string_put(env->mlx, env->win[env->current],
	10, 35, 0xffffff, "Move with arrows");
	mlx_string_put(env->mlx, env->win[env->current],
	10, 50, 0xffffff, "Zoom in/out : mouse wheel");
	mlx_string_put(env->mlx, env->win[env->current],
	10, 65, 0xffffff, "Change precision : N/M");
	mlx_string_put(env->mlx, env->win[env->current],
	10, 80, 0xffffff, "Change colors : E/R, F/G, V/B");
	mlx_string_put(env->mlx, env->win[env->current],
	10, 95, 0xffffff, "Change fractal : C");
}
