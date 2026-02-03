/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 05:58:49 by masantos          #+#    #+#             */
/*   Updated: 2025/08/06 06:05:10 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_F_H
# define FT_PRINT_F_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *str, ...);

int	print_char(int c);

int	print_str(char *str);

int	print_s(long n, int base, char *symbols, int is_signed);

int	print_u(unsigned int num, int base, char*symbols);

int	print_hex_uintptr(uintptr_t num, char *symbols);

int	print_pointer(void *ptr);

int	print_conversion(char especifier, va_list ap);

#endif

