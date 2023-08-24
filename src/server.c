/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:16:49 by saichaou          #+#    #+#             */
/*   Updated: 2023/08/24 15:33:46 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main() {
    // Set up the signal handler using sigaction
    struct sigaction new_action;
	ft_printf("%d\n", getpid());
    new_action.sa_handler = customHandler;
    sigemptyset(&new_action.sa_mask);
    new_action.sa_flags = 0;
    sigaction(SIGUSR2, &new_action, NULL);
    sigaction(SIGUSR1, &new_action, NULL);
	while(1)
		;;

    // Your main program logic here

    return 0;
}

void customHandler(int signum) {
	if (signum == SIGUSR1)
	{
		ft_printf("%d", 0);
	}
	else
		ft_printf("%d", 1);
    // Additional handling logic can be added here
}
