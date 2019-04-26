/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_unicode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 02:47:59 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/04 08:51:40 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/libftprintf.h"

int		ft_char_unicode(t_conv *conv, char *buf)
{
	int	nb_bytes;

	nb_bytes = ft_nb_bytes_char(conv->ch);
	if (nb_bytes == 0)
		return (-1);
	if (conv->j + nb_bytes >= BUFFER)
		ft_reset_buffer(buf, conv);
	if (MB_CUR_MAX == 1 && conv->ch >= 128 && conv->ch <= 255)
	{
		nb_bytes = 1;
		conv->ch = (char)conv->ch;
	}
	else if (nb_bytes > MB_CUR_MAX)
		return (-1);
	conv->champ -= nb_bytes - 1;
	if (conv->champ && !conv->minus)
		ft_champ_precision_c(conv, buf);
	ft_fill_buff_c(buf, conv, nb_bytes);
	if (conv->minus)
		ft_champ_precision_c(conv, &buf[1]);
	ft_reinitialize_struct(conv);
	return (0);
}

int		ft_nb_bytes_char(unsigned int va)
{
	if (va >= 0xdc00 && va <= 0xdfff)
		return (0);
	if (va <= 0x7f)
		return (1);
	else if (va <= 0x7ff)
		return (2);
	else if (va <= 0xFFFF)
		return (3);
	else if (va <= 0x10FFFF)
		return (4);
	else
		return (0);
}

void	ft_fill_buff_c(char *buf, t_conv *conv, int nb_bytes)
{
	if (nb_bytes == 1)
		buf[conv->j++] = conv->ch;
	else if (nb_bytes == 2)
	{
		buf[conv->j++] = (conv->ch >> 6) + 0xC0;
		buf[conv->j++] = (conv->ch & 0x3F) + 0x80;
	}
	else if (nb_bytes == 3)
	{
		buf[conv->j++] = ((conv->ch >> 12) + 0xe0);
		buf[conv->j++] = ((conv->ch >> 6) & 0x3F) + 0x80;
		buf[conv->j++] = (conv->ch & 0x3F) + 0x80;
	}
	else if (nb_bytes == 4)
	{
		buf[conv->j++] = (conv->ch >> 18) + 0xF0;
		buf[conv->j++] = ((conv->ch >> 12) & 0x3F) + 0x80;
		buf[conv->j++] = ((conv->ch >> 6) & 0x3F) + 0x80;
		buf[conv->j++] = (conv->ch & 0x3F) + 0x80;
	}
}
