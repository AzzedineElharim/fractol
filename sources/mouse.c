/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 18:53:45 by aelharim          #+#    #+#             */
/*   Updated: 2017/05/22 17:34:00 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fractol.h"

void			put_pixel(t_frac *init, int x, int y, int color)
{
	if (0 <= x && x <= WIN && 0 <= y && y <= WIN)
		ft_memcpy(&init->data[(y * init->bpp / 8) +
				(x * (init->bpp / 8) * WIN)], &color, 4);
}

unsigned int	get_color(int a, t_frac *init)
{
	unsigned int	c;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (a == init->it_max)
		return (init->color);
	r = (255 - (a * init->r)) * init->coul;
	g = (255 - (a * init->g)) * init->coul;
	b = ((a * init->b)) * 3;
	c = (r << 16) + (g << 8) + b;
	return (c);
}

void			restart(t_frac *init)
{
	init->count = 1;
	improve_var(init);
	if (init->type == 1)
		julia(init);
	else if (init->type == 2)
		mandel(init);
}

int				mouse_mlx(int button, int x, int y, t_frac *init)
{
	if (button == 4)
	{
		init->zoom *= 1.1;
		y > WIN / 2 ? (init->movey += 0.1 / init->zoom) :
			(init->movey -= 0.1 / init->zoom);
		x > WIN / 2 ? (init->movex += 0.1 / init->zoom) :
			(init->movex -= 0.1 / init->zoom);
	}
	else if (button == 5)
	{
		init->zoom /= 1.1;
		y > WIN / 2 ? (init->movey += 0.1 / init->zoom) :
			(init->movey -= 0.1 / init->zoom);
		x > WIN / 2 ? (init->movex += 0.1 / init->zoom) :
			(init->movex -= 0.1 / init->zoom);
	}
	if (init->it_max <= 0)
		init->it_max = 1;
	restart(init);
	return (0);
}
