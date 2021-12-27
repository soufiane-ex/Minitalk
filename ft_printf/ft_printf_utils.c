/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:29:54 by schahid           #+#    #+#             */
/*   Updated: 2021/12/10 14:48:46 by schahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	printstr(char *str)
{
	int	i ;

	i = 0 ;
	if (str == NULL)
	{
		printstr("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	printnbr(int nb)
{
	char	*num;
	int		len;

	num = ft_itoa(nb);
	len = printstr(num);
	free(num);
	return (len);
}

int	printpercent(void)
{
	write(1, "%", 1);
	return (1);
}
