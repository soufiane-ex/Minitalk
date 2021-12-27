/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahid <schahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:52:37 by schahid           #+#    #+#             */
/*   Updated: 2021/12/09 14:53:50 by schahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int						printchar(int c);

void					ft_putchar_fd(char c, int fd);

int						printstr(char *str);

int						printnbr(int nb);

int						printpercent(void);

int						ft_printf(const char *str, ...);

int						printf_type(va_list args, const char type);

int						printunsigned(unsigned int nb);

char					*ft_itoa(int n);

char					*unsigned_itoa(unsigned int nb);

int						ft_hexlen(unsigned int nb);

void					ft_puthex(unsigned int nb, const char type);

int						printhex(unsigned int nb, const char type);

int						ft_addlen(unsigned long long ptr);

void					ft_putadd(unsigned long long ptr);

int						printadd(unsigned long long ptr);
#endif
