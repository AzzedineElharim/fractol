/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:32:00 by aelharim          #+#    #+#             */
/*   Updated: 2016/11/18 18:37:31 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int		t;

	if (s)
	{
		t = ft_strlen(s);
		while (t >= 0)
		{
			s[t] = '\0';
			t--;
		}
	}
}
