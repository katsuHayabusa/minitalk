/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:38:42 by saichaou          #+#    #+#             */
/*   Updated: 2023/08/20 14:02:49 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <minitalk.h>

int main(int argc, char **argv)
{
	pid_t	pid;
	if (argc != 3 || !argv[2])
		return (0);
	pid = atoi(argv[1]);
	if (pid > 0)
		kill(pid, SIGTERM);
}

/*
int	client(pid_t pid, char *str)
{
}
*/
