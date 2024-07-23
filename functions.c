/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <m.abdelmaged@student.42abudha    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:41:57 by mabdelma          #+#    #+#             */
/*   Updated: 2022/10/17 10:41:57 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	digit_count(unsigned long long x, unsigned int base)
{
	int	y;

	y = 1;
	x /= base;
	while (x)
	{
		y++;
		x /= base;
	}
	return (y);
}

int	print_st(char *s)
{
	int	x;

	x = 0;
	if (!s)
	{
		print_st("(null)");
		return (6);
	}
	while (*s)
	{
		x += ft_putchar(*s);
		s++;
	}
	return (x);
}

int	print_int(int x)
{
	int		x2;
	char	*s;

	x2 = 0;
	s = ft_itoa(x);
	x2 = print_st(s);
	free(s);
	return (x2);
}

int	print_hex_low(unsigned int x)
{
	unsigned int	y;
	int				i;
	char			*st;

	i = digit_count(x, 16) + 1;
	st = malloc(sizeof(char) * i);
	st[--i] = '\0';
	if (x == 0)
		st[0] = 48;
	while (x)
	{
		y = x % 16 + 48;
		x /= 16;
		if (y < 58)
			st[--i] = (char)y;
		else
			st[--i] = (char)y + 39;
	}
	i = print_st(st);
	free(st);
	return (i);
}

int	print_hex_high(unsigned int x)
{
	unsigned int	y;
	int				i;
	char			*st;

	i = digit_count(x, 16) + 1;
	st = malloc(sizeof(char) * i);
	st[--i] = '\0';
	if (x == 0)
		st[0] = 48;
	while (x)
	{
		y = x % 16 + 48;
		x /= 16;
		if (y < 58)
			st[--i] = (char)y;
		else
			st[--i] = (char)y + 7;
	}
	i = print_st(st);
	free(st);
	return (i);
}
