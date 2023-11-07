/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreasgjertsenkalicani <andreasgjertse    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:51:16 by akalican          #+#    #+#             */
/*   Updated: 2023/11/07 16:04:47 by andreasgjer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_convert(va_list args, const char format)
{
	int				length_print;
	char			*str;
	int				integer;
	unsigned int	ptr;
	unsigned int	hex;

	length_print = 0;
	if (format == 'c')
	{
		length_print += ft_putchar(va_arg(args, int));
		length_print++;
	}
	else if (format == 's')
	{
		str = va_arg(args, char *);
		length_print += ft_putstr(str);
	}
	else if (format == 'd' || format == 'i')
	{
		integer = va_arg(args, int);
		length_print += ft_printnbr(integer);
	}
	else if (format == 'p')
	{
		ptr = va_arg(args, unsigned int);
		length_print += ft_ptr_print(ptr);
	}
	else if (format == 'x' || format == 'X')
	{
		hex = va_arg(args, unsigned int);
		length_print += ft_print_hex(hex, format);
	}
	return (length_print);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_convert(args, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

int	main(void)
{
	unsigned int	nb;
	int				num;

	num = 234;
	nb = 10;
	ft_printf("%x", nb);
	printf("\n%s", ft_itoa_unsigned(num));
}
