/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreasgjertsenkalicani <andreasgjertse    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:53:26 by akalican          #+#    #+#             */
/*   Updated: 2023/11/11 13:58:31 by andreasgjer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	number_length(int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

int	abs(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

/* int	ft_printnbr(int nb)
{
	int	len;

	len = number_length(nb);
	if (nb < 0)
	{
		ft_putchar('-');
		len++;
	}
	if (nb >= 10)
	{
		ft_printnbr(abs(nb) / 10);
		ft_printnbr(abs(nb) % 10);
	}
	if (nb < 10)
	{
		ft_putchar(abs(nb) + '0');
		len++;
	}
	return (len);
}
*/

int test_printnbr(int nb)
{
	int len;

	len = number_length(nb);
	if (nb < 0)
	{
		ft_putchar('-');
		len++;
	}
	if (nb >= 10)
	{
		test_printnbr(nb / 10);
		test_printnbr(nb % 10);
	}
	if (nb < 10)
	{
		ft_putchar(nb + '0');
		len++;
	}
	return (len);
}

/*static int	number_length_second(int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}
*/

int	ft_printnbr_second(int nb)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(nb);
	len = ft_putstr(num);
	free(num);
	return (len);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
