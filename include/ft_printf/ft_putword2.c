/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putword2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:45:34 by saichaou          #+#    #+#             */
/*   Updated: 2022/12/29 16:50:31 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*majormin(char c)
{
	if (c == 'x')
		return ("0123456789abcdef");
	if (c == 'X')
		return ("0123456789ABCDEF");
	return (0);
}

int	ft_putnbr_hexa(unsigned long nbr, char c)
{
	char		*base;
	int			i;

	i = 0;
	base = majormin(c);
	if (nbr >= 16)
	{
		i += ft_putnbr_hexa(nbr / 16, c);
		i += ft_putnbr_hexa(nbr % 16, c);
	}
	else
	{
		ft_putchar(base[nbr]);
	i++;
	}
	return (i);
}

int	ft_putptr(void *ptr)
{
	int	i;

	if (ptr == 0)
		return (ft_putstr("(nil)"));
	i = 0;
	i += ft_putstr("0x");
	i += ft_putnbr_hexa((unsigned long) ptr, 'x');
	return (i);
}
