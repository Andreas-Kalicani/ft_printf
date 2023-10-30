/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:53:26 by akalican          #+#    #+#             */
/*   Updated: 2023/10/30 12:31:13 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("NULL");
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_printnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_printnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48);
}
