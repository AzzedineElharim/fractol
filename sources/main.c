/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:50:51 by aelharim          #+#    #+#             */
/*   Updated: 2017/05/18 19:28:55 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fractol.h"

static	void	verif_param(int argc, char *str)
{
	char	*julia;
	char	*mandelbrot;
	char	*burnship;
	char	*jules;

	burnship = ft_strdup("burnship");
	julia = ft_strdup("julia");
	mandelbrot = ft_strdup("mandelbrot");
	jules = ft_strdup("jules");
	if (argc != 2)
	{
		ft_putstr_fd("Liste :\n-mandelbrot\n-julia\n-burnshipi\n-jules", 2);
		exit(0);
	}
	if (ft_strcmp(str, julia) != 0 && ft_strcmp(mandelbrot, str) != 0 &&
			ft_strcmp(burnship, str) != 0 && ft_strcmp(jules, str) != 0)
	{
		ft_putstr_fd("Liste :\n-mandelbrot\n-julia\n-burnship\n-jules", 2);
		exit(0);
	}
}

int				main(int argc, char **argv)
{
	t_frac *frac;

	verif_param(argc, argv[1]);
	frac = init_fractol();
	frac->mlx = mlx_init();
	frac->win = mlx_new_window(frac->mlx, WIN, WIN, "fractol");
	frac->ptr_image = mlx_new_image(frac->mlx, WIN, WIN);
	frac->data = mlx_get_data_addr(frac->ptr_image,
			&(frac->bpp), &(frac->size), &(frac->endian));
	if (ft_strcmp("mandelbrot", argv[1]) == 0)
		mandel(frac);
	if (ft_strcmp("julia", argv[1]) == 0)
		julia(frac);
	if (ft_strcmp("burnship", argv[1]) == 0)
		burn(frac);
	if (ft_strcmp("jules", argv[1]) == 0)
		jules(frac);
	return (0);
}
