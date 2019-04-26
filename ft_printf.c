/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 03:52:12 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/04 07:16:15 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/libftprintf.h"

int				ft_printf(const char *str, ...)
{
	va_list		ap;
	t_conv		conv;
	char		buf[BUFFER + 1];

	ft_bzero(buf, BUFFER + 1);
	conv.malloc_error = 0;
	ft_reinitialize_struct(&conv);
	conv.j = 0;
	conv.j_tot = 0;
	va_start(ap, str);
	if ((ft_inner_printf(str, ap, buf, &conv)) == -1)
		return (-1);
	conv.j_tot += conv.j;
	va_end(ap);
	write(1, buf, conv.j);
	return (conv.j_tot);
}

int				ft_inner_printf(const char *s, va_list ap, char *buf, t_conv *c)
{
	int			i;

	i = 0;
	while (i < (int)ft_strlen(s) && s[i])
	{
		while (s[i] && s[i] != '%')
		{
			if (c->j >= BUFFER)
				ft_reset_buffer(buf, c);
			buf[c->j++] = (char)s[i++];
			c->actual_buf++;
		}
		i += ft_parse((char *)&s[i], c, ap);
		ft_get_arg(c, ap);
		if ((ft_which_conversion(c, buf)) == -1)
		{
			write(1, buf, c->j_tot + c->j - c->actual_buf);
			return (-1);
		}
		if (c->malloc_error)
			return (-1);
		i++;
	}
	return (0);
}

void			ft_reset_buffer(char *buf, t_conv *conv)
{
	write(1, buf, conv->j);
	ft_bzero(buf, BUFFER + 1);
	conv->j_tot += conv->j;
	conv->j = 0;
}

void			ft_reinitialize_struct(t_conv *conv)
{
	conv->conversion = 0;
	conv->hash = 0;
	conv->zero = 0;
	conv->plus = 0;
	conv->minus = 0;
	conv->space = 0;
	conv->champ = 0;
	conv->precision = 0;
	conv->pointeur = 0;
	conv->dot = 0;
	conv->lenght = -1;
	conv->nb = 0;
	conv->ch = 0;
	conv->wstr = 0;
	conv->str = 0;
	conv->unb = 0;
	conv->address = 0;
	conv->actual_buf = 0;
}

int				ft_malloc_error(t_conv *conv)
{
	conv->malloc_error = 1;
	return (0);
}
