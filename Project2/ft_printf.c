/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:24:08 by gd-auria          #+#    #+#             */
/*   Updated: 2024/02/07 15:11:15 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_a(va_list *argp, const char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		return (ft_putchar(va_arg(*argp, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*argp, char *)));
	else if (c == 'p')
		return (ft_putstr("0x") + ft_x_putnbr(va_arg(*argp, void *), i));
	else if (c == 'd')
		return (ft_putnbr(va_arg(*argp, int)));
	else if (c == 'i')
		return (ft_putnbr(va_arg(*argp, int)));
	else if (c == 'u')
		return (ft_y_putnbr(va_arg(*argp, int)));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(*argp, int), 1));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(*argp, int), 2));
	else
		return (ft_putchar(c));
}

int	ft_printf(const char *str, ...)
{
	size_t	count;
	size_t	i;
	va_list	argp;

	va_start(argp, str);
	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '%')
			count += ft_a(&argp, str[++i]);
		else
			count += ft_putchar(str[i]);
	}
	va_end(argp);
	return (count);
}
