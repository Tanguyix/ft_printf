/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 21:15:24 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/04 05:12:55 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/libftprintf.h"

void	ft_get_arg(t_conv *c, va_list ap)
{
	if (c->conversion == 'd' || c->conversion == 'i' || c->conversion == 'D' ||
c->conversion == 'B')
		ft_get_arg_di(c, ap);
	if (c->conversion == 'u' || c->conversion == 'U' || c->conversion == 'x' ||
c->conversion == 'X' || c->conversion == 'o' || c->conversion == 'O' ||
c->conversion == 'b')
		ft_get_arg_uxo(c, ap);
	if (c->conversion == 'c' || c->conversion == 'C')
	{
		if (c->lenght == 'l' || c->conversion == 'C')
			c->ch = va_arg(ap, wchar_t);
		else
			c->ch = (char)va_arg(ap, int);
	}
	if (c->conversion == 's' || c->conversion == 'S')
		ft_get_arg_s(c, ap);
	if (c->conversion == 'p' || c->conversion == 'n')
		c->address = va_arg(ap, int *);
}

void	ft_get_arg_di(t_conv *c, va_list ap)
{
	if (c->lenght == 'L')
		c->nb = va_arg(ap, long long int);
	else if (c->lenght == 'l' || c->conversion == 'D' ||
c->conversion == 'O')
		c->nb = va_arg(ap, long int);
	else if (c->lenght == 'j')
		c->nb = va_arg(ap, intmax_t);
	else if (c->lenght == 'h')
		c->nb = (short int)va_arg(ap, int);
	else if (c->lenght == 'H')
		c->nb = (char)va_arg(ap, int);
	else if (c->lenght == 'z')
		c->nb = va_arg(ap, ssize_t);
	else
		c->nb = va_arg(ap, int);
}

void	ft_get_arg_uxo(t_conv *c, va_list ap)
{
	if (c->conversion == 'U' || c->conversion == 'O')
	{
		c->unb = va_arg(ap, unsigned long long int);
		return ;
	}
	if (c->lenght == 'l')
		c->unb = va_arg(ap, unsigned long long);
	else if (c->lenght == 'j')
		c->unb = va_arg(ap, uintmax_t);
	else if (c->lenght == 'h')
		c->unb = (unsigned short int)va_arg(ap, int);
	else if (c->lenght == 'L')
		c->unb = va_arg(ap, unsigned long long int);
	else if (c->lenght == 'H')
		c->unb = (unsigned char)va_arg(ap, int);
	else if (c->lenght == 'z')
		c->unb = va_arg(ap, size_t);
	else
		c->unb = va_arg(ap, unsigned int);
}

void	ft_get_arg_s(t_conv *c, va_list ap)
{
	if (c->lenght == 'l' || c->conversion == 'S')
		c->wstr = va_arg(ap, wchar_t*);
	else
		c->str = va_arg(ap, char*);
}
