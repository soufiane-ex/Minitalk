/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:20:18 by schahid           #+#    #+#             */
/*   Updated: 2021/12/10 14:18:49 by schahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_hexlen(unsigned int nb)
{
	int	i;

	i = 0 ;
	while (nb)
	{
		i++;
		nb = nb / 16;
	}
	return (i);
}

void	ft_puthex(unsigned int nb, const char type)
{
	if (nb >= 16)
	{
		ft_puthex(nb / 16, type);
		ft_puthex(nb % 16, type);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
		{
			if (type == 'x')
				ft_putchar_fd((nb - 10 + 'a'), 1);
			if (type == 'X')
				ft_putchar_fd((nb - 10 + 'A'), 1);
		}
	}
}

int	printhex(unsigned int nb, const char type)
{
	int	printlen;

	printlen = 0;
	if (nb == 0)
		printlen += write(1, "0", 1);
	else
	{
		ft_puthex(nb, type);
		printlen += ft_hexlen(nb);
	}
	return (printlen);
}
