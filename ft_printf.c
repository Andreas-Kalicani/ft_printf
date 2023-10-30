/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:51:16 by akalican          #+#    #+#             */
/*   Updated: 2023/10/30 14:52:23 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_convert(va_list args, const char format)
{
	int	length_print;

	length_print = 0;
	if (format == 'c')
		length_print += ft_putstr(va_arg(args, int));
	else if (format == 's')
		length_print += ft_putstr(va_arg(args, char *));
	else if (format == 'd' || foramt == i)
		length_print += ft_printnbr(va_arg(args, int));
	else if (format == 'p')
		length_print += ft_ptr_print(va_arg(args, unsigned long long));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	va_start(args, str);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_convert(args, str[i + 1]);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
