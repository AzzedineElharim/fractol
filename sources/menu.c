/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:57:56 by aelharim          #+#    #+#             */
/*   Updated: 2017/05/22 16:25:36 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		put_string(char *s, int l, int c, t_frac *e)
{
	mlx_string_put(e->mlx, e->win, 3 + c * 10, l * 13, 0xFF0000, s);
}

void			put_info(t_frac *e)
{
	put_string("MOVE : Arrow", 0, 0, e);
	put_string("ZOOM : Mouse Wheel", 1, 0, e);
	put_string("Nb it_max = ", 2, 0, e);
	put_string(ft_itoa(e->it_max), 2, 15, e);
	put_string("Increase it_max : +", 3, 0, e);
	put_string("Decrease it_max : -", 4, 0, e);
	put_string("Quit : esc", 5, 0, e);
	put_string("Change color : p", 6, 0, e);
}
