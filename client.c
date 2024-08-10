/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:56:36 by ccodere           #+#    #+#             */
/*   Updated: 2024/08/10 11:46:18 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_bit(int pid, int bit)
{
	if (bit == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(300);
}

void	ft_send_null(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		ft_send_bit(pid, 0);
		i++;
	}
	usleep(100);
}

void	ft_send_msg(int pid, const char *msg)
{
	char	c;
	int		i;

	while (*msg)
	{
		i = 0;
		c = *msg;
		while (i < 8)
		{
			ft_send_bit(pid, (c >> i) & 1);
			i++;
		}
		msg++;
	}
	ft_send_null(pid);
}

int	main(int argc, char **argv)
{
	const char	*msg;
	int			pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		msg = argv[2];
		ft_send_msg(pid, msg);
	}
	else
		ft_printf(RED"format: ./client <server_pid> <message> \n"RESET);
	return (0);
}
