/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:21:31 by gd-auria          #+#    #+#             */
/*   Updated: 2024/02/07 14:23:55 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
void	*ft_calloc(size_t count, size_t size);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		slen(long n);
char	*ft_itoa(long n);
int		ft_putnbr_base(long n, int type);
int		ft_y_putnbr(unsigned int n);
int		ft_x_putnbr(void *ptr, int i);

#endif
