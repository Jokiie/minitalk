/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 22:24:23 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/11 15:38:27 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <signal.h>

static void	ft_send_bit(int server_pid, int bit)
{
	if (bit == 0)
		kill(server_pid, SIGUSR1);
	else if (bit == 1)
		kill(server_pid, SIGUSR2);
	usleep(300);
}

static void	ft_send_byte(int server_pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		ft_send_bit(server_pid, (c >> i) & 1);
		i++;
	}
}

static void	ft_send_msg(int server_pid, char *msg)
{
	unsigned char	current_char;

	while (*msg != '\0')
	{
		current_char = *msg;
		ft_send_byte(server_pid, current_char);
		msg++;
	}
	ft_send_byte(server_pid, '\0');
}

static void	ft_signals_handler(int sig, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)siginfo;
	if (sig == SIGUSR2)
	{
		ft_printf(GREEN "Server received the message\n" RESET);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;
	int					pid;

	pid = 0;
	if (argc != 3)
	{
		ft_printf(RED "Error\n" RESET);
		ft_printf(GREY "Usage: ./client <server pid> <message>\n" RESET);
		return(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || ft_str_isdigit(argv[1]) == FALSE)
	{
		ft_printf(RED "Error\n" GREY "Invalid PID.\n" RESET);
		return (EXIT_FAILURE);
	}
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = ft_signals_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR2, &sa, NULL);
	ft_send_msg(pid, argv[2]);
	return (EXIT_SUCCESS);
}
