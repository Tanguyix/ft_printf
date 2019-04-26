/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 06:41:16 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/04 10:06:43 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/libftprintf.h"

int				ft_s(t_conv *conv, char *buf)
{
	int			j;
	int			i;
	int			size_string_print;
	char		*str_precise;

	i = 0;
	j = 0;
	size_string_print = 0;
	if (conv->str)
		size_string_print = ft_size_string(conv);
	if (!(str_precise = malloc(size_string_print + 1)))
		return (ft_malloc_error(conv));
	ft_bzero(str_precise, size_string_print + 1);
	if (conv->str == NULL)
		return (ft_s_null(conv, buf, str_precise));
	while (!(conv->precision) && !conv->dot && (conv->str[i] || (i == 0 &&
conv->str[0])))
		str_precise[j++] = conv->str[i++];
	while ((conv->precision--) && (conv->str[i] || (i == 0 && conv->str[0])))
		str_precise[j++] = conv->str[i++];
	size_string_print = ft_strlen(str_precise);
	ft_s2(conv, size_string_print, buf, str_precise);
	free(str_precise);
	ft_reinitialize_struct(conv);
	return (0);
}

void			ft_s2(t_conv *conv, int s_s_p, char *buf, char *str_precise)
{
	while (!conv->zero && !conv->minus && conv->champ-- > s_s_p)
	{
		if (conv->j >= BUFFER)
			ft_reset_buffer(buf, conv);
		buf[conv->j++] = ' ';
	}
	while (conv->zero && !conv->minus && conv->champ-- > s_s_p)
	{
		if (conv->j >= BUFFER)
			ft_reset_buffer(buf, conv);
		buf[conv->j++] = '0';
	}
	ft_s_fill(conv, buf, str_precise);
	while (!conv->zero && conv->minus && conv->champ-- > s_s_p)
	{
		if (conv->j >= BUFFER)
			ft_reset_buffer(buf, conv);
		buf[conv->j++] = ' ';
	}
	while (conv->zero && conv->minus && conv->champ-- > s_s_p)
	{
		if (conv->j >= BUFFER)
			ft_reset_buffer(buf, conv);
		buf[conv->j++] = '0';
	}
}

int				ft_s_null(t_conv *conv, char *buf, char *str_precise)
{
	char		*str;

	str = ft_strdup("(null)");
	conv->str = str;
	ft_s(conv, buf);
	free(str);
	if (str_precise)
		free(str_precise);
	ft_reinitialize_struct(conv);
	return (0);
}

void			ft_s_fill(t_conv *conv, char *buf, char *str_precise)
{
	int			j;

	j = 0;
	while (str_precise[j])
	{
		if (conv->j >= BUFFER)
			ft_reset_buffer(buf, conv);
		buf[conv->j++] = str_precise[j++];
	}
}

int				ft_size_string(t_conv *conv)
{
	int			size_string_print;
	int			size_string;

	size_string = ft_strlen((char *)conv->str);
	if (conv->precision && (conv->precision < size_string))
		size_string_print = conv->precision;
	else
		size_string_print = size_string;
	return (size_string_print);
}
