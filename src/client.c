/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:38:42 by saichaou          #+#    #+#             */
/*   Updated: 2023/09/02 18:14:51 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

int	gpause;

int main(int argc, char **argv)
{
	char				**str;
	struct sigaction	new_action;
	int					pid;
	
	if (argc != 3)
		return (-1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (0);
	new_action.sa_flags = 0;
	new_action.sa_handler = ping_pong;
	sigemptyset(&new_action.sa_mask);
	sigaction(SIGUSR1, &new_action, NULL);
	gpause = 1;
	str = strtobin(argv[2]);
	send_signal(str, pid);
	free_all(str, ft_strlen(argv[2]));
	return (0);
}

void	ping_pong(int signum)
{
	if (signum == SIGUSR1)
		gpause = 0;
}

void	send_signal(char **str, int pid)
{
	int	i;
	int	j;
	int	time;

	i = 0;
	time = 0;
	while (str[i])
	{
			j = 0;
		while(str[i][j])
		{
			if (str[i][j] == '0')
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (gpause)
			{
				if (time == 10)
				{
					ft_printf("timeout");
					return ;
				}
 				usleep (500);
				time++;
			}
			gpause = 1;
			j++;
		}
		i++;
	}
}

char *chartobin(char c) 
{ 
    char *chain; 
    int i; 

    c = (int) c;
    i = 0; 
    chain = malloc(10 * sizeof(char)); 
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
    return (chain);
}

char	**strtobin(char *str)
{
	char	**chain;
	size_t	i;

	chain = malloc((ft_strlen(str) + 2) * sizeof(char *));
	if (!chain)
		return (NULL);
	i = 0;
	while (i <= ft_strlen(str))
	{
		chain[i] = chartobin(str[i]);
		i++;
	}
	chain[i] = NULL;
	return (chain);
}

