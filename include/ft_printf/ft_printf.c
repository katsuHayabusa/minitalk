/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 23:24:01 by saichaou          #+#    #+#             */
/*   Updated: 2022/12/29 16:46:37 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_type(char *s, va_list param)
{
	int	i;

	i = 0;
	if (*s == 's')
		i += ft_putstr(va_arg(param, char *));
	else if (*s == 'i' || *s == 'd')
		i += ft_putnbr(va_arg(param, int));
	else if (*s == 'c')
		i += ft_putchar(va_arg(param, int));
	else if (*s == 'u')
		i += ft_putnbr_unsigned(va_arg(param, unsigned int));
	else if (*s == 'x')
		i += ft_putnbr_hexa(va_arg(param, unsigned int), 'x');
	else if (*s == 'X')
		i += ft_putnbr_hexa(va_arg(param, unsigned int), 'X');
	else if (*s == '%')
		i += ft_putchar('%');
	else if (*s == 'p')
		i += ft_putptr(va_arg(param, void *));
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	param;

	va_start(param, s);
	i = 0;
	while (*s)
	{
		if (*s == '%' && *(s + 1))
		{
			i += print_type((char *) s + 1, param);
			s++;
		}
		else
		{
			ft_putchar(*s);
			i++;
		}
		s++;
	}
	va_end(param);
	return (i);
}
