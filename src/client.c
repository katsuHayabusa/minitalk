/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:38:42 by saichaou          #+#    #+#             */
/*   Updated: 2023/08/24 14:55:26 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <minitalk.h>

int main(int argc, char **argv)
{
	char	**str;
	int		i;
	int		j;

	if (argc == 3)
	{
		str = strtobin(argv[2]);
		i = -1;
		while(str[++i])
		{
			j = -1;
			while(str[i][++j])
			{	
				if (str[i][j] == '0')
					kill(ft_atoi(argv[1]), SIGUSR1);
				else
					kill(ft_atoi(argv[1]), SIGUSR2);
				usleep(100);
			}
		}
	}
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
            chain[7 - i] = '0';
		else 
            chain[7 - i] = '1';
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

char	**strtobin(char *str)
{
	char	**chain;
	int		i;

	chain = malloc(ft_strlen(str) * sizeof(char *));
	if (!chain)
		return (NULL);
	i = 0;
	while ((size_t) i < ft_strlen(str))
	{
		chain[i] = chartobin(str[i]);
		i++;
	}
	chain[i] = NULL;
	return (chain);
}

