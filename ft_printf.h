/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:31:22 by akalican          #+#    #+#             */
/*   Updated: 2023/10/31 13:57:27 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int			ft_putchar(int c);
int			ft_putstr(char *str);
int			ft_printnbr(int nb);
uintptr_t	ft_put_ptr(uintptr_t nbr);
int			ft_ptr_print(unsigned long long pointer);
void		ft_putchar_fd(char c, int fd);
#endif