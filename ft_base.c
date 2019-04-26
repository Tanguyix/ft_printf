/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 01:16:13 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/04 08:52:19 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/libftprintf.h"

int				ft_base(t_conv *conv, char *buf, int base)
{
	char		*str_preci;
	char		*itoaed;
	int			size;

	itoaed = ft_itoa_base(conv->unb, ft_init_str(base), base);
	size = ft_strlen(itoaed);
	if (conv->zero && conv->minus)
		conv->zero--;
	str_preci = ft_create_str_preci(conv, &size, base, itoaed);
	if (conv->malloc_error || !itoaed)
		return (0);
	if (conv->zero && conv->champ >= size && conv->hash && (base != 10) &&
(base != 2) && conv->unb && !conv->dot)
		ft_hash_xo(conv, buf, base);
	ft_base_fill(conv, str_preci, buf, size);
	free(itoaed);
	ft_reinitialize_struct(conv);
	return (0);
}

void			ft_hash_xo(t_conv *conv, char *buf, int base)
{
	if (conv->j + 1 >= BUFFER)
		ft_reset_buffer(buf, conv);
	buf[conv->j++] = '0';
	if (conv->j + 1 >= BUFFER)
		ft_reset_buffer(buf, conv);
	if (base == 16)
		buf[conv->j++] = 'x';
	if (base == 32)
		buf[conv->j++] = 'X';
}

void			ft_base_fill(t_conv *conv, char *str_p, char *buf, int size)
{
	int			j;

	if ((conv->conversion == 'X' || conv->conversion == 'x') && conv->hash &&
conv->unb && (conv->champ && conv->zero) && !conv->dot)
		j = 2;
	else if ((conv->conversion == 'o' || conv->conversion == 'O') &&
conv->hash && conv->unb && conv->champ && conv->zero && !conv->dot)
		j = 1;
	else
		j = 0;
	ft_b_fill_champ(conv, buf, size);
	while (str_p[j])
	{
		if (conv->j >= BUFFER)
			ft_reset_buffer(buf, conv);
		buf[conv->j++] = str_p[j++];
	}
	while (conv->champ-- > size && (conv->minus))
	{
		if (conv->j >= BUFFER)
			ft_reset_buffer(buf, conv);
		buf[conv->j++] = ' ';
	}
	free(str_p);
}

void			ft_b_fill_champ(t_conv *conv, char *buf, int size)
{
	while ((!conv->zero || conv->dot) && !conv->minus && conv->champ-- > size)
	{
		if (conv->j >= BUFFER)
			ft_reset_buffer(buf, conv);
		buf[conv->j++] = ' ';
	}
	while ((conv->zero || !conv->dot) && !conv->minus && conv->champ-- > size)
	{
		if (conv->j >= BUFFER)
			ft_reset_buffer(buf, conv);
		buf[conv->j++] = '0';
	}
}

char			*ft_create_str_preci(t_conv *c, int *size, int base, char *ito)
{
	char		*str_preci;
	int			i;
	int			j;

	i = 0;
	j = 0;
	str_preci = ft_malloc_str_p(c, size);
	if (c->malloc_error)
		return (0);
	if (c->hash && (base != 10) && (c->unb || c->conversion == 'p' ||
(base == 8 && *size != 1)))
		i += ft_str_preci_ox(c, base, str_preci);
	if (c->conversion == 'p' && c->unb == 0 && c->zero)
		c->precision = c->champ - 2;
	while (c->precision-- > *size)
		str_preci[i++] = '0';
	if (!(c->dot && c->unb == 0 && (!c->zero || c->precision)))
		ft_strcpy(&str_preci[i], ito);
	*size = ft_strlen(str_preci);
	return (str_preci);
}
