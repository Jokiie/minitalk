/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:44:40 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/05 22:00:42 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	ft_reset_buffer(char **buffer)
{
	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
}

void	ft_increase_buffer(char **buffer, size_t *size)
{
	size_t	new_size;
	char	*new_buffer;

	new_size = (*size) * 2;
	new_buffer = ft_realloc(*buffer, *size, new_size);
	if (!new_buffer)
	{
		ft_printf(RED "Error\n" GREY "Realloc failed\n" RESET);
		exit(EXIT_FAILURE);
	}
	*buffer = new_buffer;
	*size = new_size;
	ft_bzero(*buffer + *size, new_size - *size);
}
