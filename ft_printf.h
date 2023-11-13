/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreasgjertsenkalicani <andreasgjertse    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:31:22 by akalican          #+#    #+#             */
/*   Updated: 2023/11/11 13:45:55 by andreasgjer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_putchar(int c);
int				ft_putstr(char *str);
int				ft_printnbr(int nb);
unsigned int	ft_put_ptr(unsigned long long nbr);
int				ft_ptr_print(unsigned long long pointer);
void			ft_putchar_fd(char c, int fd);
int				ft_print_hex(unsigned int nb, const char format);
char			*ft_itoa_unsigned(int nb);
int				ft_printf(const char *format, ...);
int				ft_print_unsigned(unsigned int nb);
int				ft_print_precentage(void);
void			ft_add_hex(unsigned int nb, const char format);
char			*ft_itoa(int n);
int				ft_printnbr_second(int nb);
int             test_printnbr(int nb);
#endif