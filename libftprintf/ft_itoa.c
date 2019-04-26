/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:57:56 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/02 07:39:44 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <string.h>
#include <stdlib.h>

static int		ft_size_int(intmax_t n)
{
	int			len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(intmax_t n)
{
	int			isneg;
	char		*i;
	int			size;

	isneg = 0;
	if (n < 0)
	{
		isneg = 1;
		if (n < -9223372036854775807 && (i = ft_strdup("-9223372036854775808")))
			return (i);
		else
			n = -n;
	}
	size = ft_size_int(n) + isneg;
	if (!(i = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i[size] = '\0';
	while (size--)
	{
		i[size] = (n % 10) + '0';
		n /= 10;
	}
	if (isneg)
		i[0] = '-';
	return (i);
}
