/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 03:17:34 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/04 00:30:17 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ft_itoa_base(uintmax_t unb, char *str, int base)
{
	char		*itoaed;
	int			size;

	if (base == 32)
		base = 16;
	size = ft_size_base(unb, base);
	if (!(itoaed = malloc(size + 1)))
		return (0);
	ft_bzero(itoaed, size + 1);
	while (size--)
	{
		itoaed[size] = str[unb % base];
		unb /= base;
	}
	free(str);
	return (itoaed);
}
