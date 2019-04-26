/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_uni_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 07:46:57 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/04 10:05:53 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/libftprintf.h"

int			ft_precision_str_uni(t_conv *conv, char *buf, int nb_bytes)
{
	int		spaces;

	conv->precision -= nb_bytes;
	if (conv->precision < 0)
	{
		if (conv->minus && conv->champ && (spaces = conv->champ - conv->j))
		{
			if (!conv->zero)
				while (spaces-- > 0)
				{
					if (conv->j >= BUFFER)
						ft_reset_buffer(buf, conv);
					buf[conv->j++] = ' ';
				}
			if (conv->zero)
				while (spaces-- > 0)
				{
					if (conv->j >= BUFFER)
						ft_reset_buffer(buf, conv);
					buf[conv->j++] = '0';
				}
		}
		return (1);
	}
	return (0);
}

void		ft_minus_champ_uni(t_conv *conv, char *buf, int i)
{
	int		spaces;

	spaces = conv->champ - i;
	if (!conv->zero)
		while (spaces-- > 0)
		{
			if (conv->j >= BUFFER)
				ft_reset_buffer(buf, conv);
			buf[conv->j++] = ' ';
		}
	if (conv->zero)
		while (spaces-- > 0)
		{
			if (conv->j >= BUFFER)
				ft_reset_buffer(buf, conv);
			buf[conv->j++] = '0';
		}
}

int			ft_weird_cases(t_conv *conv, char *buf)
{
	if (conv->dot && conv->precision == 0)
	{
		if (!(conv->zero))
			while (conv->champ--)
			{
				if (conv->j >= BUFFER)
					ft_reset_buffer(buf, conv);
				buf[conv->j++] = ' ';
			}
		if (conv->zero)
			while (conv->champ--)
			{
				if (conv->j >= BUFFER)
					ft_reset_buffer(buf, conv);
				buf[conv->j++] = '0';
			}
		ft_reinitialize_struct(conv);
		return (1);
	}
	if (conv->wstr == NULL)
	{
		ft_s_null(conv, buf, 0);
		return (1);
	}
	return (0);
}

void		ft_spaces(t_conv *conv, char *buf, int spaces)
{
	if (!conv->zero)
		while (spaces--)
		{
			if (conv->j >= BUFFER)
				ft_reset_buffer(buf, conv);
			buf[conv->j++] = ' ';
		}
	else
		while (spaces--)
		{
			if (conv->j >= BUFFER)
				ft_reset_buffer(buf, conv);
			buf[conv->j++] = '0';
		}
}

void		ft_init(t_conv *conv, int *spaces)
{
	int		nb_char;

	nb_char = ft_actual_printed_bits(conv);
	if (conv->dot && (conv->precision < nb_char))
		nb_char = conv->precision;
	if (conv->champ > nb_char)
		*spaces = conv->champ - nb_char;
}
