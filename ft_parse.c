/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 04:11:04 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/04 04:37:45 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/libftprintf.h"

int				ft_parse(char *str, t_conv *conv, va_list ap)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i += ft_get_conversion(&str[i], conv, ap);
			break ;
		}
		i++;
	}
	if (i == (int)ft_strlen(str))
		i = 0;
	return (i);
}

int				ft_is_conversion(char c)
{
	const char	truc[] = {'s', 'S', 'p', 'd', 'D', 'n',
'i', 'o', 'O', 'u', 'U', 'x', 'X', 'c', 'C', '%', 'B', 'b'};
	int			i;

	i = 0;
	while (i < (int)sizeof(truc))
	{
		if (c == truc[i])
			return (1);
		i++;
	}
	return (0);
}

int				ft_is_unknown(char c)
{
	const char	truc[] = {'s', 'S', 'p', 'n', 'd', 'D', 'b', 'i', 'o', 'O', 'u',
'U', 'x', 'X', 'c', 'C', '+', '-', ' ', '#', 'h', 'l',
'j', 'z', '%', '.', '*', 'B'};
	int			i;

	i = 0;
	if (ft_isdigit(c) || c == 0)
		return (0);
	while (i < (int)sizeof(truc))
	{
		if (c == truc[i++])
			return (0);
	}
	return (1);
}

void			ft_store_lenght(char c, t_conv *conv)
{
	const char	len[] = {'z', 'H', 'h', 'l', 'L', 'j'};
	int			i;
	int			j;

	i = 0;
	while (conv->lenght != -1 && i < (int)sizeof(len))
	{
		if (conv->lenght == len[i])
			break ;
		i++;
	}
	j = i;
	while (j < (int)sizeof(len))
	{
		if (c == len[j])
		{
			if (c == 'h' && conv->lenght == 'H')
				return ;
			conv->lenght = c;
			return ;
		}
		j++;
	}
	return ;
}
