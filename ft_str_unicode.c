/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_unicode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 01:58:14 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/04 10:00:32 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/libftprintf.h"

int		ft_str_unicode(t_conv *conv, char *buf)
{
	int	i;
	int j;
	int	n_b;
	int	spaces;

	j = 0;
	spaces = 0;
	i = -1;
	if ((ft_weird_cases(conv, buf)))
		return (0);
	ft_init(conv, &spaces);
	if (!(conv->minus) && spaces)
		ft_spaces(conv, buf, spaces);
	while (conv->wstr[++i])
	{
		if ((n_b = ft_nb_bytes_char(conv->wstr[i])) > MB_CUR_MAX || n_b == 0)
			return (-1);
		if (conv->dot && (ft_precision_str_uni(conv, buf, n_b)))
			return (0);
		j += ft_masks_unicode_str(conv, buf, n_b, i);
	}
	if (conv->minus && conv->champ)
		ft_minus_champ_uni(conv, buf, j);
	ft_reinitialize_struct(conv);
	return (0);
}

int		ft_actual_printed_bits(t_conv *conv)
{
	int		cp_preci;
	int		size;
	int		i;

	size = 0;
	i = 0;
	cp_preci = conv->precision;
	while (conv->wstr[i])
	{
		cp_preci -= ft_nb_bytes_char(conv->wstr[i]);
		if (conv->precision && cp_preci < 0)
			return (size);
		size += ft_nb_bytes_char(conv->wstr[i]);
		i++;
	}
	return (size);
}

int		ft_masks_unicode_str(t_conv *conv, char *buf, int nb_bytes, int i)
{
	if (nb_bytes + conv->j >= BUFFER)
		ft_reset_buffer(buf, conv);
	if (nb_bytes == 1 && (buf[conv->j++] = conv->wstr[i]))
		return (1);
	else if (nb_bytes == 2 && (buf[conv->j++] = (conv->wstr[i] >> 6) + 0xC0))
	{
		buf[conv->j++] = (conv->wstr[i] & 0x3F) + 0x80;
		return (2);
	}
	else if (nb_bytes == 3)
	{
		buf[conv->j++] = ((conv->wstr[i] >> 12) + 0xe0);
		buf[conv->j++] = ((conv->wstr[i] >> 6) & 0x3F) + 0x80;
		buf[conv->j++] = (conv->wstr[i] & 0x3F) + 0x80;
		return (3);
	}
	else if (nb_bytes == 4)
	{
		buf[conv->j++] = (conv->wstr[i] >> 18) + 0xF0;
		buf[conv->j++] = ((conv->wstr[i] >> 12) & 0x3F) + 0x80;
		buf[conv->j++] = ((conv->wstr[i] >> 6) & 0x3F) + 0x80;
		buf[conv->j++] = (conv->wstr[i] & 0x3F) + 0x80;
		return (4);
	}
	return (0);
}
