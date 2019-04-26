/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 05:16:35 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/02 03:28:35 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/libftprintf.h"

int		ft_p(t_conv *conv, char *buf)
{
	conv->unb = (unsigned long)conv->address;
	conv->hash++;
	(ft_base(conv, buf, HEXA));
	return (0);
}
