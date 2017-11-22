/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:28:22 by aelharim          #+#    #+#             */
/*   Updated: 2017/05/22 17:26:53 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/libft.h"

void			improve_var(t_frac *init)
{
	mlx_destroy_image(init->mlx, init->ptr_image);
	init->ptr_image = mlx_new_image(init->mlx, WIN, WIN);
	init->data = mlx_get_data_addr(init->ptr_image,
			&(init->bpp), &(init->size), &(init->endian));
	init->count = 1;
}

int				my_key_julia(int keycode, t_frac *frac)
{
	frac->count = 1;
	if (frac->it_max <= 0)
		frac->it_max = 1;
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
		frac->it_max += 10;
	if (keycode == 78)
		frac->it_max -= 10;
	if (frac->it_max <= 0)
		frac->it_max = 1;
	if (keycode == 123)
		frac->movex += 0.1 / frac->zoom;
	if (keycode == 124)
		frac->movex -= 0.1 / frac->zoom;
	if (keycode == 126)
		frac->movey += 0.1 / frac->zoom;
	if (keycode == 125)
		frac->movey -= 0.1 / frac->zoom;
	if (keycode == 49)
		frac->space++;
	if (keycode == 35)
		frac->coul += 5;
	improve_var(frac);
	julia(frac);
	return (0);
}

int				hook_julia(int x, int y, t_frac *init)
{
	if (init->space % 2 == 0)
	{
		if (x > WIN / 2)
			init->c_re += 0.005 / init->zoom;
		else
			init->c_re -= 0.005 / init->zoom;
		if (y > WIN / 2)
			init->c_im += 0.005 / init->zoom;
		else
			init->c_im -= 0.005 / init->zoom;
		improve_var(init);
		julia(init);
	}
	return (0);
}

int				my_key_mandel(int keycode, t_frac *frac)
{
	frac->count = 1;
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
		frac->it_max += 10;
	if (keycode == 78)
		frac->it_max -= 10;
	if (frac->it_max <= 0)
		frac->it_max = 1;
	if (keycode == 124)
		frac->movex += 0.1 / frac->zoom;
	if (keycode == 123)
		frac->movex -= 0.1 / frac->zoom;
	if (keycode == 125)
		frac->movey += 0.1 / frac->zoom;
	if (keycode == 126)
		frac->movey -= 0.1 / frac->zoom;
	if (keycode == 35)
		frac->coul += 5;
	improve_var(frac);
	if (frac->type == 2)
		mandel(frac);
	else if (frac->type == 3)
		burn(frac);
	else if (frac->type == 4)
		jules(frac);
	return (0);
}

int				hook_mandel(int x, int y, t_frac *init)
{
	if (init->type != 4)
	{
		if (x > WIN / 2)
			init->c_re += 0.005 / init->zoom;
		else
			init->c_re -= 0.005 / init->zoom;
		if (y > WIN / 2)
			init->c_im += 0.005 / init->zoom;
		else
			init->c_im -= 0.005 / init->zoom;
	}
	improve_var(init);
	if (init->type == 2)
		mandel(init);
	else if (init->type == 3)
		burn(init);
	else if (init->type == 4)
		jules(init);
	return (0);
}
