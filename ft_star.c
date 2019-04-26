/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 03:50:35 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/04 04:13:07 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/libftprintf.h"

void		ft_champ_star(t_conv *conv, char *str, int i, va_list ap)
{
	int		star;

	star = va_arg(ap, int);
	if ((ft_isdigit(str[i + 1])))
		;
	else if (star < 0)
	{
		conv->minus++;
		conv->champ = -star;
	}
	else if (star == 0 && !(conv->champ = 0))
	{
		conv->zero++;
	}
	else
		conv->champ = star;
}

int			ft_dot(t_conv *conv, char *str, va_list ap)
{
	int		star;

	if (str[1] == '*')
	{
		if ((star = va_arg(ap, int)) >= 0)
		{
			conv->precision = star;
			conv->dot++;
		}
		return (1);
	}
	else
	{
		conv->precision = ft_atoi(&str[1]);
		conv->dot++;
	}
	return (0);
}
