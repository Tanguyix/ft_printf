/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 01:21:06 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/04 00:02:02 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/libftprintf.h"

int		ft_which_conversion(t_conv *conv, char *buf)
{
	if (conv->conversion == 'B')
		return (ft_bool(conv, buf));
	if (conv->conversion == 's' && conv->lenght != 'l')
		return (ft_s(conv, buf));
	if (conv->conversion == 'S' || (conv->conversion == 's' &&
conv->lenght == 'l'))
		return (ft_str_unicode(conv, buf));
	if (conv->conversion == 'p')
		return (ft_p(conv, buf));
	if (conv->conversion == 'd' || conv->conversion == 'i')
		return (ft_d(conv, buf));
	if (conv->conversion == 'D')
		return (ft_d(conv, buf));
	if (conv->conversion == 'o')
		return (ft_base(conv, buf, OCTAL));
	if (conv->conversion == 'O')
		return (ft_base(conv, buf, OCTAL));
	return (ft_which_conversion_2(conv, buf));
}

int		ft_which_conversion_2(t_conv *conv, char *buf)
{
	if (conv->conversion == 'b')
		return (ft_base(conv, buf, BINAIRE));
	if (conv->conversion == 'u')
		return (ft_base(conv, buf, DECIMAL));
	if (conv->conversion == 'U')
		return (ft_base(conv, buf, DECIMAL));
	if (conv->conversion == 'x')
		return (ft_base(conv, buf, HEXA));
	if (conv->conversion == 'X')
		return (ft_base(conv, buf, HEXA_MAJ));
	if (conv->conversion == 'c' && conv->lenght != 'l')
		return (ft_c(conv, buf));
	if (conv->conversion == 'C' || (conv->conversion == 'c' &&
conv->lenght == 'l'))
		return (ft_char_unicode(conv, (char *)buf));
	if (conv->conversion == '%')
	{
		conv->ch = '%';
		return (ft_c(conv, buf));
	}
	if (conv->conversion == 'E')
		return (ft_c(conv, buf));
	if (conv->conversion == 'n')
		return (ft_n(conv));
	return (0);
}
