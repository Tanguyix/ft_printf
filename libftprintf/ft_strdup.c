/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:36:20 by tboissel          #+#    #+#             */
/*   Updated: 2018/08/15 07:47:19 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		length;
	int		i;
	char	*dupped;

	i = 0;
	length = ft_strlen(s);
	if (!(dupped = (char*)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	while (s[i])
	{
		dupped[i] = s[i];
		i++;
	}
	dupped[i] = '\0';
	return (dupped);
}
