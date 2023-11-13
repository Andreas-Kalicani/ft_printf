/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:53:26 by akalican          #+#    #+#             */
/*   Updated: 2023/11/13 17:30:47 by akalican         ###   ########.fr       */
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

	len = 1;
	while (nb > 9)
	{
		nb /= 10;
		len++;
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
	int	fd;

	fd = 1;
	len = number_length(nb);
	if (nb < 0 && nb != -2147483648)
	{
		ft_putchar('-');
		nb = -nb;
		len++;
	}
	if (nb > 10)
	{
		ft_printnbr(abs(nb) / 10);
		ft_putchar_fd(nb % 10 + '0', fd);
		len++;
	}
	if (nb < 10)
	{
		ft_putchar(abs(nb) + '0');
		len++;
	}
	return (len);
}
*/
void	ft_putnbr_fd(int n, int fd)
{
	long long int	t;

	t = n;
	if (t < 0)
	{
		t *= -1;
		ft_putchar_fd('-', fd);
	}
	if (t > 9)
	{
		ft_putnbr_fd((t / 10), fd);
		ft_putchar_fd((t % 10 + '0'), fd);
	}
	else
		ft_putchar_fd((t + '0'), fd);
}

int	ft_printnbr(int nb)
{
	int	len;
	int	n;

	n = nb;
	len = 1;
	if (n < 0 && n != -2147483648)
	{
		n = -nb;
		len++;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	ft_putnbr_fd(nb, 1);
	if (nb == -2147483648)
		return (11);
	return (len);
}

/*
int	print_nbr(int n)
{
	int	nb;
	int	i;

	nb = n;
	i = 1;
	if (n < 0 && n != -2147483648)
	{
		nb = -n;
		i++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	ft_putnbr_fd(n, 1);
	if (n == -2147483648)
		return (11);
	return (i);
}
*/
/*int test_printnbr(int nb)
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
*/

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

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
