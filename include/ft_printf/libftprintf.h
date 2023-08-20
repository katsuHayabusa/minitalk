/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:58:52 by saichaou          #+#    #+#             */
/*   Updated: 2022/12/29 16:28:34 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H	
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int num);
int		ft_putnbr_unsigned(unsigned int num);
int		ft_printf(const char *s, ...);
int		ft_putnbr_hexa(unsigned long nbr, char c);
char	*majormin(char c);
int		ft_putptr(void *ptr);
char	*ft_strchr(const char *s, int c);
#endif
