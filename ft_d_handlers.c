/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 06:43:10 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/04 04:40:23 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/libftprintf.h"

char			*ft_precision_d(t_conv *conv, int *size, char *cp_itoaed)
{
	int			i;
	char		*str_precision;

	i = 0;
	if (!(str_precision = malloc(conv->precision + 1)))
	{
		ft_malloc_error(conv);
		return (0);
	}
	if (conv->nb < 0)
	{
		str_precision[0] = cp_itoaed[0];
		i = 1;
		conv->precision++;
	}
	if (conv->plus && conv->nb >= 0)
		str_precision[i++] = '+';
	while (conv->precision-- > *size)
		str_precision[i++] = '0';
	if (conv->nb < 0)
		cp_itoaed++;
	ft_strcpy(&str_precision[i], cp_itoaed);
	*size = ft_strlen(str_precision);
	return (str_precision);
}

char			*ft_general_d(t_conv *conv, int *size, char *cp_itoaed)
{
	int			i;
	char		*str_precision;

	i = 0;
	if (conv->champ > *size)
		str_precision = malloc(conv->champ + 1);
	else
		str_precision = malloc(*size + 1);
	if (conv->nb < 0)
	{
		str_precision[0] = cp_itoaed[0];
		i = 1;
		cp_itoaed++;
	}
	if (conv->plus && conv->nb >= 0 && (str_precision[i++] = '+'))
		conv->champ--;
	if (conv->space)
		conv->champ--;
	while (conv->champ-- > *size)
		str_precision[i++] = '0';
	ft_strcpy(&str_precision[i], cp_itoaed);
	*size = ft_strlen(str_precision);
	return (str_precision);
}

char			*ft_zero_champ(t_conv *conv, int size, char *cp_itoaed)
{
	int			i;
	char		*str_precision;

	i = 0;
	if (!(str_precision = malloc(size + 1)))
	{
		ft_malloc_error(conv);
		return (0);
	}
	if (conv->plus && conv->nb >= 0)
		str_precision[i++] = '+';
	ft_strcpy(&str_precision[i], cp_itoaed);
	return (str_precision);
}

void			ft_fill_buf_d(t_conv *conv, char *str_pr, char *buf, int size)
{
	int			j;

	if (conv->space && !conv->plus && (conv->nb >= 0) && (buf[conv->j++] = ' '))
		size++;
	while (!(conv->minus) && (conv->champ-- > size))
	{
		if (conv->j >= BUFFER)
			ft_reset_buffer(buf, conv);
		buf[conv->j++] = ' ';
	}
	j = 0;
	while (str_pr[j])
	{
		if (conv->j >= BUFFER)
			ft_reset_buffer(buf, conv);
		buf[conv->j++] = str_pr[j++];
	}
	while (conv->champ-- > size && (conv->minus))
	{
		if (conv->j >= BUFFER)
			ft_reset_buffer(buf, conv);
		buf[conv->j++] = ' ';
	}
	ft_bzero(str_pr, ft_strlen(str_pr));
	free(str_pr);
}

int				ft_plus_dot_zero(t_conv *conv, char *buf)
{
	if (!conv->champ && conv->plus && conv->dot && conv->nb == 0)
	{
		if (conv->j >= BUFFER)
			ft_reset_buffer(buf, conv);
		buf[conv->j++] = '+';
		ft_reinitialize_struct(conv);
		return (1);
	}
	return (0);
}
