/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:00:00 by aelharim          #+#    #+#             */
/*   Updated: 2017/05/22 16:24:35 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fractol.h"

void		cut_a(t_frac *init)
{
	mlx_put_image_to_window(init->mlx, init->win, init->ptr_image, 0, 0);
	put_info(init);
	mlx_key_hook(init->win, my_key_julia, init);
	mlx_mouse_hook(init->win, mouse_mlx, init);
	if (init->space % 2 == 0)
		mlx_hook(init->win, 6, (1L << 6), hook_julia, init);
	mlx_loop(init->mlx);
}

void		julia(t_frac *fr)
{
	t_julia	j;

	fr->type = 1;
	j.y = -1;
	while (++j.y < WIN)
	{
		j.x = -1;
		while (++j.x < WIN)
		{
			j.nre = 1 * (j.x - WIN / 2) / (0.5 * fr->zoom * WIN) + fr->movex;
			j.nim = (j.y - WIN / 2) / (0.5 * fr->zoom * WIN) + fr->movey;
			j.i = -1;
			while (++j.i < fr->it_max)
			{
				j.oldre = j.nre;
				j.oldim = j.nim;
				j.nre = j.oldre * j.oldre - j.oldim * j.oldim + fr->c_re;
				j.nim = 2 * j.oldre * j.oldim + fr->c_im;
				if ((j.nre * j.nre + j.nim * j.nim) > 4)
					break ;
			}
			put_pixel(fr, j.y, j.x, get_color(j.i, fr));
		}
	}
	cut_a(fr);
}
