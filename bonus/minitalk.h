/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:45:20 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/04 14:48:03 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>

void	ft_reset_buffer(char **buffer);
void	ft_increase_buffer(char **buffer, size_t *buffer_size);

#endif