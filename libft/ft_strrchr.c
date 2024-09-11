/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:01:59 by ccodere           #+#    #+#             */
/*   Updated: 2023/11/08 11:47:07 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*last_occ;

	last_occ = NULL;
	if (str != NULL)
	{
		while (1)
		{
			if (*str == (char)c)
				last_occ = str;
			if (*str == '\0')
				return ((char *)last_occ);
			str++;
		}
	}
	return (NULL);
}
