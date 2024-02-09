/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a_putx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:29:13 by gd-auria          #+#    #+#             */
/*   Updated: 2024/02/07 14:23:13 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	slen(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_reverse_print(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
		i++;
	while (--i > -1)
	{
		len += ft_putchar(str[i]);
	}
	return (len);
}

int	ft_x_putnbr(void *ptr, int i)
{
	unsigned char	*tem;
	int				x;
	int				len;
	uintptr_t		tdt;

	if (!ptr)
		return (ft_putchar('0'));
	tdt = (uintptr_t)ptr;
	x = sizeof(void *) * 2 + 1;
	tem = ft_calloc((x), sizeof(char));
	if (!tem)
		return (0);
	len = 0;
	while (tdt)
	{
		i = tdt & 0xF;
		tem[len] = ("0123456789abcdef")[i];
		tdt >>= 4;
		len++;
	}
	tem[len] = '\0';
	len = ft_reverse_print((char *)tem);
	free(tem);
	return (len);
}

char	*ft_itoa(long n)
{
	char	*rt;
	int		i;

	i = slen(n);
	rt = ft_calloc(i + 1, sizeof(char));
	if (!rt)
		return (NULL);
	rt[i] = '\0';
	if (n < 0)
		rt[0] = '-';
	else if (n < 10 && n >= 0)
	{
		rt[0] = n + 48;
		return (rt);
	}
	while (--i >= 0 && n)
	{
		if (n < 0)
			rt[i] = (-(n % 10)) + 48;
		else
			rt[i] = (n % 10) + 48;
		n /= 10;
	}
	return (rt);
}

int	ft_y_putnbr(unsigned int n)
{
	char	*tem;

	tem = ft_itoa(n);
	ft_putstr(tem);
	free(tem);
	return (slen(n));
}
