/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:16:49 by saichaou          #+#    #+#             */
/*   Updated: 2023/09/02 18:18:28 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	struct sigaction	new_action;

	ft_printf("%d\n", getpid());
	new_action.sa_sigaction = custom_handler;
	sigemptyset(&new_action.sa_mask);
	new_action.sa_flags = 0;
	sigaction(SIGUSR2, &new_action, NULL);
	sigaction(SIGUSR1, &new_action, NULL);
	while (1)
		;
	return (0);
}

void	custom_handler(int signum, siginfo_t *info, void *context)
{
	static char	*str = NULL;
	static int	c = 0;
	static int	n = 7;

	c += (signum == SIGUSR2) << n--;
	kill(info->si_pid, SIGUSR1);
	if (n == -1)
	{
		str = ft_strjoin(str, c);
		if (!str)
			exit(0);
		if (c == '\0')
		{
			ft_printf("%s\n", str);
			free(str);
			str = NULL;
		}
		n = 7;
		c = 0;
	}
	(void) context;
}
