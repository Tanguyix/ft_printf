/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 23:50:30 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/04 00:33:38 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/libftprintf.h"

int		ft_bool(t_conv *conv, char *buf)
{
	int	ret;

	if (conv->nb)
		conv->str = ft_strdup("True");
	else
		conv->str = ft_strdup("False");
	ret = ft_s(conv, buf);
	free(conv->str);
	ft_reinitialize_struct(conv);
	return (ret);
}
