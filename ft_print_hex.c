/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:40:39 by akalican          #+#    #+#             */
/*   Updated: 2023/11/02 12:00:37 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_print_hexlen(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

void	ft_add_hex(unsigned int nb, const char format)
{
	if (nb >= 16)
	{
		ft_print_hex(nb / 16, format);
		ft_print_hex(nb % 16, format);
	}
	else
	{
		if (nb >= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((nb - 10 + 'a'), 1);
			if (format == "X")
				ft_putchar_fd((nb - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int nb, const char format)
{
	if (nb == 0)
		return (write(1, "0", 1));
	else
		ft_add_hex(nb, format);
	return (ft_print_hexlen(nb));
}
