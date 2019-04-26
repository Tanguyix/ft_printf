/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 03:46:15 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/04 03:48:51 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/libftprintf.h"

char			*ft_malloc_str_p(t_conv *c, int *size)
{
	char		*str_preci;

	if (c->dot && c->unb == 0 && !c->zero && (str_preci = ft_strdup("")))
		*size = 0;
	if (c->precision > *size)
		str_preci = malloc(c->precision + 1);
	else
		str_preci = malloc(*size + 1);
	if (!str_preci)
		ft_malloc_error(c);
	return (str_preci);
}

int				ft_str_preci_ox(t_conv *conv, int base, char *str_preci)
{
	int			i;

	i = 0;
	if (base == 2)
		return (0);
	if (conv->dot && base == 8 && conv->precision)
		conv->precision--;
	str_preci[i++] = '0';
	if (base == 16)
		str_preci[i++] = 'x';
	if (base == 32)
		str_preci[i++] = 'X';
	return (i);
}

char			*ft_init_str(int base)
{
	char		*str;

	if (base != 32)
		str = ft_strdup("0123456789abcdef");
	else
		str = ft_strdup("0123456789ABCDEF");
	if (base < 16)
		str[base + 1] = '\0';
	return (str);
}
