/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:10:21 by akalican          #+#    #+#             */
/*   Updated: 2023/11/16 18:34:58 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_ptr(unsigned long long nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 16;
	}
	return (len);
}

unsigned int	ft_put_ptr(unsigned long long nbr)
{
	if (nbr >= 16)
	{
		ft_put_ptr(nbr / 16);
		ft_put_ptr(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd((nbr + '0'), 1);
		else
			ft_putchar_fd((nbr - 10 + 'a'), 1);
	}
	return (nbr);
}

/*
unsigned int	ft_put_ptr(unsigned long long nbr)
{
	unsigned int	count;
	unsigned int	remainder;

	count = 0;
	while (nbr >= 16)
	{
		remainder = nbr % 16;
		if (nbr <= 9)
			ft_putchar_fd((remainder + 48), 1);
		else
			ft_putchar_fd((remainder - 10 + 'a'), 1);
		nbr = nbr / 16;
		count++;
	}
	if (nbr <= 9)
		ft_putchar_fd((remainder + 48), 1);
	else
		ft_putchar_fd((remainder - 10 + 'a'), 1);
	count++;
	return (count);
}
*/

/*
unsigned int	ft_put_ptr(unsigned long long nbr)
{
	unsigned int	count;
	unsigned int	remainder;
	char			digit;
	char			lastDigit;

	while (nbr > 16)
	{
		remainder = nbr % 16;
		if (remainder <= 9)
			digit = remainder + '0';
		else
			digit = remainder - 10 + 'a';
		ft_putchar_fd(digit, 1);
		nbr /= 16;
		count++;
	}
	if (nbr <= 9)
		lastDigit = nbr + '0';
	else
		lastDigit = nbr - 10 + 'a';
	ft_putchar_fd(lastDigit, 1);
	count++;
	return (count);
}
*/

int	ft_ptr_print(unsigned long long pointer)
{
	int	length_print;

	length_print = 0;
	length_print += write(1, "0x", 2);
	if (pointer == 0)
		length_print += write(1, "0", 1);
	else
	{
		ft_put_ptr(pointer);
		length_print += ft_len_ptr(pointer);
	}
	return (length_print);
}
