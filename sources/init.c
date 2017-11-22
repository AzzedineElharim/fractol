/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 17:41:38 by aelharim          #+#    #+#             */
/*   Updated: 2017/05/22 16:15:50 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/libft.h"

t_frac		*init_fractol(void)
{
	t_frac	*frac;

	frac = ft_memalloc(sizeof(t_frac));
	frac->ptr_image = NULL;
	frac->data = NULL;
	frac->mlx = NULL;
	frac->win = NULL;
	frac->zoom = 0.5;
	frac->movex = 0;
	frac->movey = 0;
	frac->c_re = -0.7;
	frac->c_im = 0.27;
	frac->count = 0;
	frac->it_max = 100;
	frac->type = 0;
	frac->color = 0x000000;
	frac->r = 4;
	frac->g = 8;
	frac->b = 4;
	frac->space = 2;
	frac->coul = 1;
	return (frac);
}

t_point		init_point(int x, int y, int z)
{
	t_point	p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

t_julia		*init_julia(void)
{
	t_julia	*julia;

	julia = ft_memalloc(sizeof(t_julia));
	julia->cre = -0.7;
	julia->cim = 0.27015;
	julia->movex = 0;
	julia->movey = 0;
	julia->zoom = 1;
	julia->it_max = 300;
	julia->x = -1;
	julia->y = -1;
	julia->i = -1;
	return (julia);
}

t_line		*init_line(t_point p1, t_point p2)
{
	t_line	*line;

	line = ft_memalloc(sizeof(t_line));
	line->x = p1.x;
	line->y = p1.y;
	line->dx = p2.x - p1.x;
	line->dy = p2.y - p1.y;
	line->xinc = (line->dx > 0) ? 1 : -1;
	line->yinc = (line->dy > 0) ? 1 : -1;
	line->dx = abs(line->dx);
	line->dy = abs(line->dy);
	return (line);
}
