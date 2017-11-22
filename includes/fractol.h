/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:51:56 by aelharim          #+#    #+#             */
/*   Updated: 2017/05/22 16:15:01 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define FD_WHITE 0xFFFFFF
# define FD_SILVER 0xC0C0C0
# define FD_YELLOW 0xFFFF00
# define FD_RED 0xFF0000
# define FD_GRAY 0x808080
# define FD_AQUA 0x00FFFF
# define FD_GREEN 0x008000
# define FD_BLUE 0x0000FF
# define FD_BUFF_SIZE 4096
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# define WIDTH  600
# define HEIGHT 600
# define WIN 600

typedef struct		s_frac
{
	void			*ptr_image;
	char			*data;
	int				bpp;
	int				size;
	int				endian;
	void			*mlx;
	void			*win;
	int				test;
	int				win_size;
	double			c_re;
	double			c_im;
	double			movex;
	double			movey;
	double			zoom;
	int				it_max;
	int				count;
	int				type;
	int				color;
	int				r;
	int				g;
	int				b;
	int				space;
	int				coul;
}					t_frac;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct		s_line
{
	int				dx;
	int				dy;
	int				i;
	int				xinc;
	int				yinc;
	int				cumul;
	int				x;
	int				y;
}					t_line;

typedef	struct		s_mandel
{
	int		x;
	int		y;
	int		i;
	double	c_re;
	double	c_im;
	double	new_re;
	double	new_im;
	double	old_re;
	double	old_im;
}					t_mandel;

typedef	struct		s_julia
{
	double			cre;
	double			cim;
	double			nre;
	double			nim;
	double			oldre;
	double			oldim;
	double			zoom;
	double			movex;
	double			movey;
	int				it_max;
	int				x;
	int				y;
	int				i;
}					t_julia;

t_frac				*init_fractol(void);
t_mandel			*init_mandel(void);
t_julia				*init_julia(void);
t_line				*init_line(t_point p1, t_point p2);
t_point				init_point(int x, int y, int z);
void				ligne(t_point p1, t_point p2, t_frac *frac, long couleur);
int					hook_mandel(int x, int y, t_frac *init);
void				put_pixel(t_frac *frac, int x, int y, int color);
int					mandel(t_frac *frac);
void				dis_mandel(t_frac *init);
void				dis_burn(t_frac *init);
int					burn(t_frac *frac);
void				julia(t_frac *frac);
int					my_key_julia(int keycode, t_frac *frac);
int					my_key_mandel(int keycode, t_frac *frac);
int					hook_julia(int x, int y, t_frac *init);
void				improve_var(t_frac *init);
int					mouse_mlx(int button, int x, int y, t_frac *init);
unsigned int		get_color(int a, t_frac *init);
void				my_menu(t_frac *fdf);
void				jules(t_frac *fr);
void				put_info(t_frac *e);

#endif
