/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:16:49 by saichaou          #+#    #+#             */
/*   Updated: 2023/08/21 15:03:21 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	ft_printf("%d", getpid());
	signal(SIGUSR1, sig_handler);
	pause();
}

void	sig_handler(int	signum)
{
	static int	n_sig;

	n_sig = 0;
	if(signum == SIGUSR1 || signum == SIGUSR2)
	{
		n_sig++;
		ft_printf("nombres de signaux :%d\n", n_sig);
	}
}
