/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <m.abdelmaged@student.42abudha    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 07:53:38 by m.abdelmage       #+#    #+#             */
/*   Updated: 2022/10/19 09:08:07 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num_len(int num)
{
	int	count;

	count = 0;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	*handle_zero(void)
{
	char	*result;

	result = malloc(2 * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

void	handle_negative(size_t *result_length, long *n_holder)
{
	*result_length = num_len(*n_holder) + 1;
	*n_holder = -(*n_holder);
}

void	convert(long *number, char *result, size_t *result_index)
{
	while (*number != 0)
	{
		result[*result_index] = '0' + (*number % 10);
		*number /= 10;
		(*result_index)--;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	result_length;
	size_t	result_index;
	long	n_holder;

	n_holder = n;
	if (n_holder < 0)
		handle_negative(&result_length, &n_holder);
	else if (n_holder == 0)
		return (handle_zero());
	else
		result_length = num_len(n_holder);
	result = malloc(result_length + 1);
	if (result == NULL)
		return (NULL);
	result_index = result_length;
	result[result_index] = '\0';
	result_index--;
	convert(&n_holder, result, &result_index);
	if (result_index == 0)
		result[result_index] = '-';
	return (result);
}
