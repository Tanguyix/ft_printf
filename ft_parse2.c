/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 02:06:43 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/04 04:12:29 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/libftprintf.h"

char			ft_get_lenght(char *str)
{
	if (str[0] == 'z')
		return ('z');
	else if (str[0] == 'j')
		return ('j');
	else if (str[0] == 'h')
		if (str[1] == 'h')
			return ('H');
		else
			return ('h');
	else if (str[0] == 'l')
	{
		if (str[1] == 'l')
			return ('L');
		else
			return ('l');
	}
	return (0);
}

int				ft_get_conversion(char *str, t_conv *conv, va_list ap)
{
	int			i;

	i = 0;
	while (str[i++])
	{
		ft_check_str(conv, str, i, ap);
		if (ft_isdigit(str[i]) && str[i] != '0' &&
(conv->champ = ft_atoi(&str[i])))
			i += ft_get_size_nb(conv->champ) - 1;
		if (ft_set_conv(&str[i], conv))
			return (i);
		if (str[i] == '.')
		{
			if (ft_dot(conv, &str[i], ap))
				i++;
			if (ft_isdigit(str[i + 1]))
				i += ft_get_size_nb(conv->precision);
			if (ft_is_conversion(str[i + 1]) && (conv->conversion = str[i + 1]))
				return (i + 1);
		}
	}
	return (i);
}

void			ft_check_str(t_conv *conv, char *str, int i, va_list ap)
{
	if (str[i] == ' ')
		conv->space = 1;
	if (str[i] == '0')
		conv->zero = 1;
	if (str[i] == '*')
		ft_champ_star(conv, str, i, ap);
}

int				ft_set_conv(char *str, t_conv *conv)
{
	int			i;

	i = 0;
	if (str[i] == '+')
		conv->plus = 1;
	if (str[i] == '-')
		conv->minus = 1;
	if (str[i] == '#')
		conv->hash = 1;
	if (str[i] == 'h' || str[i] == 'l' || str[i] == 'j' || str[i] == 'z')
		ft_store_lenght(ft_get_lenght(&str[i]), conv);
	if (ft_is_conversion(str[i]) && (conv->conversion = str[i]))
	{
		conv->conversion = str[i];
		return (1);
	}
	else if (ft_is_unknown(str[i]))
	{
		conv->ch = str[i];
		conv->conversion = 'E';
		return (1);
	}
	return (0);
}
