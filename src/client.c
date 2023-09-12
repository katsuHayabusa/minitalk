/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:14:17 by saichaou          #+#    #+#             */
/*   Updated: 2023/09/12 11:37:33 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_pause;

int	main(int argc, char **argv)
{
	int					i;
	int					pid;
	struct sigaction	new_action;

	if (argc != 3)
		return (1);
	i = 0;
	g_pause = 1;
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (1);
	new_action.sa_flags = 0;
	new_action.sa_handler = set_signal;
	sigemptyset(&new_action.sa_mask);
	sigaction(SIGUSR1, &new_action, NULL);
	sigaction(SIGUSR2, &new_action, NULL);
	while (argv[2][i])
	{
		send_char(argv[2][i], pid);
		i++;
	}
	send_char('\0', pid);
	return (0);
}

void	send_char(char c, int pid)
{
	int	i;
	int	t;

	i = 7;
	while (i + 1)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		t = 0;
		while (g_pause)
		{
			if (t == 100)
			{
				ft_printf("TIMEOUT");
				exit(1);
			}
			usleep(50);
			t++;
		}
		g_pause = 1;
		i--;
	}	
}

void	set_signal(int signum)
{
	if (signum == SIGUSR1)
		g_pause = 0;
	if (signum == SIGUSR2)
		ft_printf("Message reçu\n");
}
