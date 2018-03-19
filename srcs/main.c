/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:26:17 by gmonnier          #+#    #+#             */
/*   Updated: 2017/12/12 12:13:06 by gmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		usage(void)
{
	ft_putstr("Usage: ./fractol [enter a number]\n1: Mandelbrot_set\n");
	ft_putstr("2: Julia_set\n3: Burning_ship\n4: Creepy_face\n");
	exit(EXIT_FAILURE);
}

int			main(int argc, char **argv)
{
	t_env	*env;

	env = NULL;
	if (argc != 2)
		usage();
	mallcheck(env = (t_env*)ft_memalloc(sizeof(t_env)));
	mallcheck(env->mlx = mlx_init());
	if (choose_frac(argv[1], env) == -1)
	{
		free(env);
		usage();
	}
	draw_window(env);
	free(env);
	return (0);
}
