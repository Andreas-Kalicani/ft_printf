/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:10:21 by akalican          #+#    #+#             */
/*   Updated: 2023/10/30 14:48:27 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_ptr(uintptr_t nbr)
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

void	ft_put_ptr(uintptr_t nbr)
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
}

int	ft_ptr_print(unsigned long long pointer)
{
	int	length_print;

	length_print = 0;
	length_print += write(1, "0x", 2);
	if (pointer == 0)
		length_print += write(1, NULL, 1);
	else
	{
		ft_put_ptr(pointer);
		length_print += ft_len_ptr(pointer);
	}
	return (length_print);
}
