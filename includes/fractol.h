/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonnier <gmonnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:39:36 by gmonnier          #+#    #+#             */
/*   Updated: 2017/12/12 12:03:15 by gmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "libft.h"
# include "mlx.h"
# include "mlx_keys_macos.h"
# include "/System/Library/Frameworks/Tk.framework/Versions/8.4/Headers/X11/X.h"

# define WINDOW_HEIGHT 600
# define WINDOW_WIDTH 600

# define MOL_UP 7
# define MOL_DOWN 5

# define MAX_IT 30
# define START_MOVE_X 0.0
# define START_MOVE_Y 0.0
# define MOVE_SPEED 0.075
# define ZOOM_FACTOR 1.1
# define MAX_VALUE 4
# define NB_COLORS 20
# define MIN_MOVE_MOUSE 5
# define INC_COLORS 0.01
# define NB_FRAC 4
# define MANDEL 0
# define JULIA 1
# define SHIP 2
# define CREEPY 3

typedef struct		s_rgb
{
	int				a;
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_param
{
	double			move_x;
	double			move_y;
	double			zoom;
	int				max_it;
	int				color_code;
	double			re_const;
	double			im_const;
	double			r_freq;
	double			g_freq;
	double			b_freq;
}					t_param;

typedef struct		s_complex
{
	double			r;
	double			i;
}					t_complex;

typedef struct		s_env
{
	void			*mlx;
	void			*win[NB_FRAC];
	t_img			img;
	t_param			param[NB_FRAC];
	void			(*fractal[NB_FRAC])(struct s_env *env, size_t x, size_t y);
	int				current;
	int				old_x;
	int				old_y;
	int				help :2;
}					t_env;

void				init_params(t_env *env);
int					choose_frac(char *arg, t_env *env);
void				draw_window(t_env *env);

int					get_color(t_env *env, int n, double re, double im);

int					key_event(int keycode, void *param);
int					loop_event(int x, int y, void *param);
int					mouse_wheel_event(int button, int x, int y, void *param);
void				display_help(t_env *env);

void				die(char *msg, t_env *env);
void				mallcheck(void *param);

void				mandelbrot_set(t_env *env, size_t x, size_t y);
void				julia_set(t_env *env, size_t x, size_t y);
void				burning_ship(t_env *env, size_t x, size_t y);
void				creepy_face(t_env *env, size_t x, size_t y);
void				draw(t_env *env);

double				get_slope(double min, double max,
double new_min, double new_max);
double				map(double nb, double min, double slope, double new_min);
int					to_rgb(int a, int r, int g, int b);
int					to_int(t_rgb rgb);
#endif
