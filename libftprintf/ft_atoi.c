/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:29:22 by tboissel          #+#    #+#             */
/*   Updated: 2018/08/15 07:54:07 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_atoi(const char *nptr)
{
	int		neg_test;
	int		result;

	neg_test = 1;
	result = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg_test = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
		result = result * 10 + *nptr++ - '0';
	return (result * neg_test);
}
