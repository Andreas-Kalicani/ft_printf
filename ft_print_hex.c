/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:40:39 by akalican          #+#    #+#             */
/*   Updated: 2023/11/16 16:45:05 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_print_hexlen(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}
/*
void	ft_add_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_add_hex(num / 16, format);
		ft_add_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}
*/

void	ft_add_hex(unsigned int num, const char format)
{
	int		index;
	int		remainder;
	char	buffer[32];

	index = 0;
	while (num > 0)
	{
		remainder = num % 16;
		if (remainder <= 9)
			buffer[index++] = '0' + remainder;
		else
		{
			if (format == 'x')
				buffer[index++] = 'a' + remainder - 10;
			else if (format == 'X')
				buffer[index++] = 'A' + remainder - 10;
		}
		num /= 16;
	}
	if (index == 0)
		buffer[index++] = '0';
	while (index > 0)
	{
		write(1, &buffer[--index], 1);
	}
}

int	ft_print_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_add_hex(num, format);
	return (ft_print_hexlen(num));
}
