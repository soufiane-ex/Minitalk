/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:19:39 by schahid           #+#    #+#             */
/*   Updated: 2021/12/10 14:18:30 by schahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_addlen(unsigned long long ptr)
{
	int	i;

	i = 0 ;
	while (ptr)
	{
		i++;
		ptr = ptr / 16;
	}
	return (i);
}

void	ft_putadd(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_putadd(ptr / 16);
		ft_putadd(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + '0'), 1);
		else
			ft_putchar_fd((ptr - 10 + 'a'), 1);
	}
}

int	printadd(unsigned long long ptr)
{
	int	printlen;

	printlen = 0 ;
	printlen += write(1, "0x", 2);
	if (!ptr)
		printlen += write(1, "0", 1);
	else
	{
		ft_putadd(ptr);
		printlen += ft_addlen(ptr);
	}
	return (printlen);
}
