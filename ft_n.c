/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 23:34:40 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/04 04:19:41 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/libftprintf.h"

int		ft_n(t_conv *conv)
{
	*conv->address = (conv->j + conv->j_tot);
	ft_reinitialize_struct(conv);
	return (0);
}
