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

int main(int argc, char **argv)
{
	char	*tab;

	tab = chartobin(argv[1][0]);
	ft_printf("%s", tab);
	(void) argc;
	return (0);
}

char *chartobin(char c) 
{ 
    char *chain; 
    int i; 
 
    c = (int) c;
    i = 0; 
    chain = malloc(9 * sizeof(char)); 
    if (!chain) 
        return NULL; 
    chain[8] = '\0'; 
    while(c > 0) 
    { 
        if (c % 2 == 0) 
            chain[7 - i] = '0';  // Store the binary digit in reverse order
        else 
            chain[7 - i] = '1';  // Store the binary digit in reverse order
        c /= 2; 
        i++;
    }
    while(7 - i != -1)
    {
	    chain[7 - i] = '0';
	    i++;
    }
    return chain;
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

