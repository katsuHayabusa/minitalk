/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:18:11 by saichaou          #+#    #+#             */
/*   Updated: 2023/09/04 10:19:13 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	i;
	int	rep;
	int	sign;

	i = 0;
	rep = 0;
	sign = 1;
	while ((str[i] >= 7 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		rep *= 10;
		rep += str[i] - '0';
		i++;
	}
	return (rep * sign);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str, char c)
{
	char	*join;
	size_t	i;

	join = malloc(ft_strlen(str) + 2 * sizeof(char));
	if (!join)
		return (free(str), NULL);
	i = 0;
	while (str && str[i])
	{
		join[i] = str[i];
		i++;
	}
	join[i++] = c;
	join[i] = '\0';
	return (free(str), join);
}
