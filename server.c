/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:56:29 by ccodere           #+#    #+#             */
/*   Updated: 2024/08/10 11:41:18 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_init_sigdata(void)
{
	t_sigdata	data;

	ft_memset(&data, 0, sizeof(t_sigdata));
	data.bit_count = 0;
	data.current_char = 0;
}

void	ft_signal_handler(int sig)
{
	static t_sigdata	data;
	char				c;

	if (sig == SIGUSR1)
		data.current_char |= (0 << data.bit_count);
	else if (sig == SIGUSR2)
		data.current_char |= (1 << data.bit_count);
	data.bit_count++;
	if (data.bit_count == 8)
	{
		c = (char)data.current_char;
		if (c == '\0')
			ft_printf("\n");
		ft_printf(MAGENTA"%c"RESET, c);
		data.bit_count = 0;
		data.current_char = 0;
	}
}

int	main(void)
{
	ft_init_sigdata();
	signal(SIGUSR1, ft_signal_handler);
	signal(SIGUSR2, ft_signal_handler);
	ft_printf(CYAN"\n~~~~Welcome to the server Minitalk!~~~~\n\n"RESET);
	ft_printf(GREEN"server"RESET": PID is "BLUE"%d"RESET"\n\n", getpid());
	while (1)
		pause();
	return (0);
}
