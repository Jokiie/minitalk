/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:37:47 by ccodere           #+#    #+#             */
/*   Updated: 2024/08/10 11:42:08 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*ft_memset(void *byte, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = byte;
	if (byte == NULL)
		return (NULL);
	while (len--)
		*ptr++ = (unsigned char)c;
	return (byte);
}
