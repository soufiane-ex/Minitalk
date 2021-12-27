/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:48:40 by schahid           #+#    #+#             */
/*   Updated: 2021/12/10 14:29:10 by schahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	printf_type(va_list args, const char type)
{
	int	printlen;

	printlen = 0 ;
	if (type == 'c')
		printlen += printchar(va_arg(args, int));
	else if (type == 's')
		printlen += printstr(va_arg(args, char *));
	else if (type == 'p')
		printlen += printadd(va_arg(args, unsigned long long));
	else if (type == 'd' || type == 'i')
		printlen += printnbr(va_arg(args, int));
	else if (type == 'u')
		printlen += printunsigned(va_arg(args, unsigned int));
	else if (type == 'X' || type == 'x')
		printlen += printhex(va_arg(args, unsigned int), type);
	else if (type == '%')
		printlen += printpercent();
	return (printlen);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		printlen;

	i = 0 ;
	printlen = 0 ;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			printlen += printf_type(args, str[i + 1]);
			i++;
		}
		else
			printlen += printchar(str[i]);
		i++;
	}
	va_end(args);
	return (printlen);
}
