/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:55:43 by saichaou          #+#    #+#             */
/*   Updated: 2022/12/29 16:46:22 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		return (ft_putstr("(null)"));
	}
	while (*str)
	{
		write(1, str, 1);
		str++;
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int num)
{
	int				i;
	unsigned int	n_num;

	i = 0;
	if (num < 0)
	{
		n_num = -num;
		ft_putchar('-');
		i++;
	}
	else
		n_num = num;
	if (n_num >= 10)
	{
		i += ft_putnbr(n_num / 10);
		i += ft_putnbr(n_num % 10);
	}
	else
	{
		ft_putchar(n_num + '0');
		i++;
	}
	return (i);
}

int	ft_putnbr_unsigned(unsigned int num)
{
	int	i;

	i = 0;
	if (num >= 10)
	{
		i += ft_putnbr(num / 10);
		i += ft_putnbr(num % 10);
	}
	else
	{
		ft_putchar(num + '0');
		i++;
	}
	return (i);
}
