/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:57:32 by tboissel          #+#    #+#             */
/*   Updated: 2018/08/15 07:54:07 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char			*s_cast;
	int				i;

	i = 0;
	s_cast = (char *)s;
	while (n--)
		s_cast[i++] = (char)c;
	return (s_cast);
}
