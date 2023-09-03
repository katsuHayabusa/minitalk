/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:10:15 by saichaou          #+#    #+#             */
/*   Updated: 2023/09/02 16:34:21 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/libftprintf.h"

void	sig_handler(int signum);
int	ft_atoi(char *str);
size_t	ft_strlen(char *str);
void	custom_handler(int signum, siginfo_t *info, void *context);
char	*ft_strjoin(char *str, char c);
void	send_char(char c, int pid);
void	set_signal(int signum);
#endif
