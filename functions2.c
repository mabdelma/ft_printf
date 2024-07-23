/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <m.abdelmaged@student.42abudha    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 08:22:42 by mabdelma          #+#    #+#             */
/*   Updated: 2022/10/19 13:03:02 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

int	print_pointer(unsigned long long x)
{
	unsigned long long	y;
	int					i;
	char				*st;

	i = digit_count(x, 16) + 3;
	st = malloc(sizeof(char) * i);
	st[--i] = '\0';
	if (x == 0)
		st[2] = 48;
	while (x)
	{
		y = x % 16 + 48;
		x /= 16;
		if (y < 58)
			st[--i] = (char)y;
		else
			st[--i] = (char)y + 39;
	}
	st[0] = '0';
	st[1] = 'x';
	i = print_st(st);
	free(st);
	return (i);
}

int	ft_putchar(int c)
{
	char	x;

	x = (char)c;
	write(1, &x, 1);
	return (1);
}

int	print_uint(unsigned int x)
{
	unsigned int	y;
	int				i;
	char			*st;

	i = digit_count(x, 10) + 1;
	st = malloc(sizeof(char) * i);
	st[--i] = '\0';
	if (x == 0)
		st[0] = 48;
	while (x)
	{
		y = x % 10 + 48;
		x /= 10;
		st[--i] = (char)y;
	}
	i = print_st(st);
	free(st);
	return (i);
}

static	int	handle(va_list *vl, char const *str, int x)
{
	if (*str == 'c')
		x += ft_putchar(va_arg(*vl, int));
	else if (*str == 's')
		x += print_st(va_arg(*vl, char *));
	else if (*str == 'i' || *str == 'd')
		x += print_int(va_arg(*vl, int));
	else if (*str == 'u')
		x += print_uint(va_arg(*vl, unsigned int));
	else if (*str == 'p')
		x += print_pointer(va_arg(*vl, unsigned long long));
	else if (*str == 'x')
		x += print_hex_low(va_arg(*vl, unsigned int));
	else if (*str == 'X')
		x += print_hex_high(va_arg(*vl, unsigned int));
	else
		x += ft_putchar(*str);
	return (x);
}

int	ft_printf(char const *str, ...)
{
	va_list	vl;
	int		c;

	va_start(vl, str);
	c = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (*str == '\0')
				break ;
			else
				c += handle(&vl, str, 0);
		}
		else
			c += ft_putchar(*str);
		str++;
	}
	va_end(vl);
	return (c);
}
