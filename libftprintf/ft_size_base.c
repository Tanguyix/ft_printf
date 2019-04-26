/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 04:15:24 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/01 04:16:17 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_size_base(uintmax_t va, int base)
{
	intmax_t	i;

	i = 0;
	if (va == 0)
		return (1);
	while (va)
	{
		va /= base;
		i++;
	}
	return (i);
}
