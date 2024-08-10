/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:17:18 by ccodere           #+#    #+#             */
/*   Updated: 2024/08/10 11:22:27 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define RESET "\033[0m"

typedef struct s_sigdata
{
	int				bit_count;
	unsigned char	current_char;
}					t_sigdata;
int		ft_atoi(const char *str);
void	*ft_memset(void *byte, int c, size_t len);
char	*ft_itoa_base(unsigned long value, char *buffer, int base);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putbase(long n, int base);
int		ft_putbase_hex(long n, int uppercase);
int		ft_printf(const char *format, ...);
#endif
