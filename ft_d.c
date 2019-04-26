/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 03:25:18 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/04 00:43:34 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/libftprintf.h"

int		ft_d(t_conv *conv, char *buf)
{
	char	*itoaed;
	int		size;
	char	*str_precision;
	char	*cp_itoaed;

	if (ft_plus_dot_zero(conv, buf))
		return (0);
	itoaed = ft_itoa(conv->nb);
	if (!itoaed)
		return (ft_malloc_error(conv));
	cp_itoaed = itoaed;
	size = ft_strlen(cp_itoaed);
	if (conv->zero && conv->minus)
		conv->zero--;
	str_precision = ft_set_precision(conv, &size, cp_itoaed);
	if (conv->malloc_error)
		return (0);
	ft_fill_buf_d(conv, str_precision, buf, size);
	free(itoaed);
	ft_reinitialize_struct(conv);
	return (0);
}

char	*ft_set_precision(t_conv *conv, int *size, char *cp_itoaed)
{
	char *str_precision;

	if (conv->dot && conv->nb == 0 && !conv->zero)
	{
		*size = 0;
		str_precision = ft_strdup("");
	}
	else if (conv->precision > *size)
		str_precision = ft_precision_d(conv, size, cp_itoaed);
	else if (!conv->zero && conv->champ)
		str_precision = ft_zero_champ(conv, *size, cp_itoaed);
	else
		str_precision = ft_general_d(conv, size, cp_itoaed);
	return (str_precision);
}
