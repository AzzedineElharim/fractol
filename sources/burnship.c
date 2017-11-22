/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:40:20 by aelharim          #+#    #+#             */
/*   Updated: 2017/05/22 16:07:19 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/libft.h"
#include <math.h>

static	void	config_burn(t_mandel *mandel)
{
	mandel->new_re = 0;
	mandel->new_im = 0;
	mandel->old_re = 0;
	mandel->old_im = 0;
}

static	void	calc_burn(t_frac *init, t_mandel mandel)
{
	mandel.x = 0;
	while (mandel.x < WIN)
	{
		config_burn(&mandel);
		mandel.c_re = 1.5 * (mandel.x - WIN / 2) /
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
			mandel.new_im = 2 *
				fabs(mandel.old_re * mandel.old_im) + mandel.c_im;
			if ((mandel.new_re * mandel.new_re +
						mandel.new_im * mandel.new_im) > 4)
				break ;
			mandel.i++;
		}
		put_pixel(init, mandel.y, mandel.x, get_color(mandel.i, init));
		mandel.x++;
	}
}

void			dis_burn(t_frac *init)
{
	t_mandel	mandel;

	mandel.y = 0;
	while (mandel.y < WIN)
	{
		calc_burn(init, mandel);
		mandel.y++;
	}
}

int				burn(t_frac *init)
{
	init->type = 3;
	improve_var(init);
	dis_burn(init);
	mlx_key_hook(init->win, my_key_mandel, init);
	mlx_mouse_hook(init->win, mouse_mlx, init);
	mlx_hook(init->win, 6, (1L << 6), hook_mandel, init);
	mlx_put_image_to_window(init->mlx, init->win, init->ptr_image, 0, 0);
	put_info(init);
	mlx_loop(init->mlx);
	return (0);
}
