/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:04:20 by gd-auria          #+#    #+#             */
/*   Updated: 2024/02/07 15:06:32 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[++i])
		ft_putchar(s[i]);
	return (i);
}

static int	ft_ics_put(long n, int i, char *base)
{
	unsigned int	ics;

	ics = (unsigned int)n;
	if (ics >= 16)
	{
		i = ft_ics_put(ics / 16, i, base);
		i = ft_ics_put(ics % 16, i, base);
	}
	else
		i += ft_putchar(base[ics]);
	return (i);
}

int	ft_putnbr_base(long n, int type)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (!n)
		return (ft_putchar(48));
	if (type == 2)
		base = "0123456789ABCDEF";
	count = ft_ics_put(n, count, base);
	return (count);
}

int	ft_putnbr(int n)
{
	char	*tem;

	tem = ft_itoa(n);
	ft_putstr(tem);
	free(tem);
	return (slen(n));
}
