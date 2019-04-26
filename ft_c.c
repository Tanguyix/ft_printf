/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 03:36:30 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/02 06:12:47 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/libftprintf.h"

int			ft_c(t_conv *conv, char *buf)
{
	if (conv->champ && !conv->minus)
		ft_champ_precision_c(conv, buf);
	if (conv->j + 1 >= BUFFER)
		ft_reset_buffer(buf, conv);
	buf[conv->j++] = conv->ch;
	if (conv->minus)
		ft_champ_precision_c(conv, buf);
	ft_reinitialize_struct(conv);
	return (0);
}

void		ft_champ_precision_c(t_conv *conv, char *buf)
{
	if (!conv->zero)
		while (conv->champ-- > 1)
		{
			if (conv->j >= BUFFER)
				ft_reset_buffer(buf, conv);
			buf[conv->j++] = ' ';
		}
	if (conv->zero)
		while (conv->champ-- > 1)
		{
			if (conv->j >= BUFFER)
				ft_reset_buffer(buf, conv);
			buf[conv->j++] = '0';
		}
}
