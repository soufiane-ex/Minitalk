/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:59:58 by schahid           #+#    #+#             */
/*   Updated: 2021/12/08 18:11:05 by schahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*unsigned_itoa(unsigned int nb)
{
	unsigned int	nbr;
	char			*num;
	int				i;

	nbr = nb;
	i = 0 ;
	while (nb)
	{
		i++ ;
		nb = nb / 10 ;
	}
	num = (char *)malloc(sizeof(char) * (i + 1));
	if (!num)
		return (NULL);
	num[i] = '\0';
	while (nbr)
	{
		num[i - 1] = nbr % 10 + 48 ;
		nbr = nbr / 10 ;
		i-- ;
	}
	return (num);
}

int	printunsigned(unsigned int nb)
{
	char	*num;
	int		printlen;

	printlen = 0 ;
	if (!nb)
		printlen += write(1, "0", 1);
	else
	{
		num = unsigned_itoa(nb);
		printlen += printstr(num);
		free(num);
	}
	return (printlen);
}
