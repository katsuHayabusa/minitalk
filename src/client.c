/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:38:42 by saichaou          #+#    #+#             */
/*   Updated: 2023/08/22 14:02:31 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <minitalk.h>

int main(void)
{
	char	*tab;

	tab = chartobin('c');
	while (tab)
	{
		ft_printf("%c", *tab);
		tab++;
	}
	return (0);
}

char	*chartobin(char c)
{
	char	*chain;
	int		i;

	i = 0;
	chain = malloc(9 * sizeof(char));
	if (!chain)
		return (NULL);
	chain[8] = '\0';
	while(c / 2 == 0)
	{
		if (c % 2 == 0)
			chain[i] = '0';
		else
			chain[i] = '1';
		c /= 2;
		i++;
	}
	return (chain);
}

int	**strtobin(char *str)
{
	int		**chain;
	int		i;
	int		j;

	chain = malloc(ft_strlen(str) * sizeof(int *));
	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ft_printf("occurence numero %d", i);
		chain[i] = malloc(9 * sizeof(int));
		if (!chain)
			return (NULL);
		j = 8;
		while (str[i] > 0)
		{
			if (str[i] % 2 == 0)
				chain[i][j]	= 0;
			else
				chain[i][j] = 1;
			j--;
			str[i] /= 2;
		}
		chain[i][j] = '\0';
		i++;
	}
	chain[i][j] = '\0';
	return (chain);
}

