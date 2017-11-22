/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:40:20 by aelharim          #+#    #+#             */
/*   Updated: 2017/05/22 16:06:46 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/libft.h"
#include <math.h>

void	config_mandel(t_mandel *mandel)
{
	mandel->new_re = 0;
	mandel->new_im = 0;
	mandel->old_re = 0;
	mandel->old_im = 0;
}

void	calc_mandel(t_frac *init, t_mandel mandel)
{
	mandel.x = 0;
	while (mandel.x < WIN)
	{
		config_mandel(&mandel);
		mandel.c_re = 1 * (mandel.x - WIN / 2) /
			(0.5 * init->zoom * WIN) + init->movex;
		mandel.c_im = (mandel.y - WIN / 2) /
			(0.5 * init->zoom * WIN) + init->movey;
		mandel.i = 0;
		while (mandel.i < init->it_max)
		{
			mandel.old_re = mandel.new_re;
			mandel.old_im = mandel.new_im;
			mandel.new_re = mandel.old_re * mandel.old_re - mandel.old_im *
				mandel.old_im + mandel.c_re;
			mandel.new_im = 2 * mandel.old_re * mandel.old_im + mandel.c_im;
			if ((mandel.new_re * mandel.new_re +
						mandel.new_im * mandel.new_im) > 2)
				break ;
			mandel.i++;
		}
		put_pixel(init, mandel.y, mandel.x, get_color(mandel.i, init));
		mandel.x++;
	}
}

void	dis_mandel(t_frac *init)
{
	t_mandel	mandel;

	mandel.y = 0;
	while (mandel.y < WIN)
	{
		calc_mandel(init, mandel);
		mandel.y++;
	}
}

int		mandel(t_frac *init)
{
	init->type = 2;
	improve_var(init);
	dis_mandel(init);
	mlx_key_hook(init->win, my_key_mandel, init);
	mlx_mouse_hook(init->win, mouse_mlx, init);
	mlx_hook(init->win, 6, (1L << 6), hook_mandel, init);
	mlx_put_image_to_window(init->mlx, init->win, init->ptr_image, 0, 0);
	put_info(init);
	mlx_loop(init->mlx);
	return (0);
}
