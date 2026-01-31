/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 19:56:39 by masantos          #+#    #+#             */
/*   Updated: 2025/09/06 01:42:59 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s(long n, int base, char *symbols, int is_signed)
{
	int	count;

	count = 0;
	if (is_signed && n < 0)
	{
		count += print_char('-');
		n = -n;
	}
	if (n >= (long)base)
		count += print_s(n / base, base, symbols, 0);
	count += print_char(symbols[n % base]);
	return (count);
}

int	print_u(unsigned int num, int base, char *symbols)
{
	int	count;

	count = 0;
	if (num >= (unsigned int)base)
		count += print_u(num / base, base, symbols);
	count += print_char(symbols[num % base]);
	return (count);
}

int	print_hex_uintptr(uintptr_t num, char *symbols)
{
	char	buffer[sizeof(uintptr_t) * 2];
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (num == 0)
		return (count + print_char('0'));
	while (num > 0)
	{
		buffer[i] = symbols[num % 16];
		i++;
		num /= 16;
	}
	while (i > 0)
	{
		i--;
		count += print_char(buffer[i]);
	}
	return (count);
}
