/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:11:05 by akalican          #+#    #+#             */
/*   Updated: 2023/11/08 11:21:45 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_unsigned_len(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa_unsigned(int nb)
{
	char	*num;
	int		len;

	len = ft_unsigned_len(nb);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
	{
		free(num);
		return (0);
	}
	num[len] = '\0';
	while (nb != 0)
	{
		num[len - 1] = nb % 10 + 48;
		nb = nb / 10;
		len--;
	}
	return (num);
}

int	ft_print_unsigned(unsigned int nb)
{
	char	*num;
	int		print_length;

	print_length = 0;
	if (nb == 0)
		print_length += write(1, "0", 1);
	else
	{
		num = ft_itoa_unsigned(nb);
		print_length += ft_putstr(num);
		free(num);
	}
	return (print_length);
}

int	ft_print_precentage(void)
{
	write(1, "%", 1);
	return (1);
}
