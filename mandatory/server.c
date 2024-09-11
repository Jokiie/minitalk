/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 22:33:48 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/11 15:08:24 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "minitalk.h"

static char		*g_buffer = NULL;

static char	*ft_create_buffer(char *buffer, size_t buffer_size)
{
	buffer = (char *)malloc(sizeof(char) * buffer_size);
	if (!buffer)
	{
		ft_printf(RED"Error\n"GREY"Failed malloc for buffer.\n"RESET);
		buffer = NULL;
		exit(EXIT_FAILURE);
	}
	ft_bzero(buffer, buffer_size);
	return (buffer);
}

static void	ft_assemble_msg(unsigned char *byte)
{
	static size_t	i = 0;
	static size_t	buffer_size = 10240;

	if (!g_buffer)
		g_buffer = ft_create_buffer(g_buffer, buffer_size);
	if (i == buffer_size)
		ft_increase_buffer(&g_buffer, &buffer_size);
	g_buffer[i++] = (char)*byte;
	if ((char)*byte == '\0')
	{
		write(1, g_buffer, i);
		ft_reset_buffer(&g_buffer);
		i = 0;
	}
}

static t_bool	ft_client_changed(int *current_client, int *client_pid)
{
	if (*current_client != 0)
	{
		if (*client_pid == 0)
			*client_pid = *current_client;
		else if (*client_pid != *current_client)
			return (TRUE);
	}
	return (FALSE);
}

static void	ft_signals_handler(int sig, siginfo_t *siginfo, void *context)
{
	static unsigned char	byte = 0;
	static unsigned char	bit_index = 0;
	static int				client_pid = 0;

	if (ft_client_changed(&siginfo->si_pid, &client_pid) == TRUE)
	{
		client_pid = siginfo->si_pid;
		byte = 0;
		bit_index = 0;
		ft_reset_buffer(&g_buffer);
	}
	if (sig == SIGUSR1)
		byte &= ~(1 << bit_index++);
	else if (sig == SIGUSR2)
		byte |= (1 << bit_index++);
	if (bit_index == 8)
	{
		ft_assemble_msg(&byte);
		bit_index = 0;
		byte = 0;
	}
	(void)context;
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;

	(void)argv;
	if (argc > 1)
	{
		ft_printf(RED"Error\n"GREY "Too many arguments\n"RESET);
		return (EXIT_FAILURE);
	}
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = ft_signals_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf(CYAN "\n~~~~Welcome to the server Minitalk!~~~~\n\n" RESET);
	ft_printf(CYAN "         Server PID : " GREEN "%d\n\n" RESET, getpid());
	while (1)
		pause();
	ft_reset_buffer(&g_buffer);
	return (EXIT_SUCCESS);
}
