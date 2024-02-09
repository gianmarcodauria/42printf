/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:03:30 by gd-auria          #+#    #+#             */
/*   Updated: 2024/02/07 15:04:13 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <stdint.h>
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	char			*s;
	size_t			i;
	unsigned long	len;

	s = NULL;
	len = (unsigned long)count * (unsigned long)size;
	if ((count >> 31) % 2 && size)
		return (0);
	if ((size >> 31) % 2 && count)
		return (0);
	if (len >= 1247483424)
		return (0);
	s = (char *) malloc (len);
	if (!s)
		return (NULL);
	i = 0;
	while (i < (len))
	{
		s[i] = 0;
		i++;
	}
	return ((void *)s);
}
