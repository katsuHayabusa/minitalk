/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:38:42 by saichaou          #+#    #+#             */
/*   Updated: 2023/09/02 16:36:14 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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
	ft_printf("%d", ft_strlen(argv[2]));
	return (0);
}

void	ping_pong(int signum)
{
	if (signum == SIGUSR1)
		gpause = 1;
}

void	send_signal(char **str, int pid)
{
	int	i;
	int	j;

	i = 0;
	if (gpause == 1)
	{
		while (str[i])
		{
			j = 0;
			while(str[i][j])
			{
				if (str[i][j] == '0')
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
				gpause = 0;
				usleep(100);
				j++;
			}
			i++;
		}
	}
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
    return (chain);
}

char	**strtobin(char *str)
{
	char	**chain;
	int		i;

	chain = malloc((ft_strlen(str) + 1) * sizeof(char *));
	if (!chain)
		return (NULL);
	i = 0;
	while ((size_t) i <= ft_strlen(str))
	{
		chain[i] = chartobin(str[i]);
		i++;
	}
	chain[i] = NULL;
	return (chain);
}

