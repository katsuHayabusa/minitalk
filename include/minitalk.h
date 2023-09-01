/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:10:15 by saichaou          #+#    #+#             */
/*   Updated: 2023/09/01 15:05:09 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/libftprintf.h"

void	sig_handler(int signum);
int		ft_atoi(const char *str);
char	**strtobin(char *str);
char	*chartobin(char str);
size_t	ft_strlen(char *str);
void	ft_bzero(void *mem, size_t size);
void	custom_handler(int signum, siginfo_t *info, void *context);
char	*ft_strjoin(char *str, char c);
void	ping_pong(int signum);
void	send_signal(char **str, int pid);
#endif
