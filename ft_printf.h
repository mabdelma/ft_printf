/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <m.abdelmaged@student.42abudha    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:18:08 by m.abdelmage       #+#    #+#             */
/*   Updated: 2022/10/19 12:26:48 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h>
# include <stdarg.h>

char	*ft_itoa(int n);
int		ft_printf(char const *str, ...);
int		print_int(int x);
int		digit_count(unsigned long long x, unsigned int base);
int		ft_putchar(int c);
int		print_pointer(unsigned long long x);
int		print_hex_low(unsigned int x);
int		print_hex_high(unsigned int x);
int		print_st(char *s);

#endif
