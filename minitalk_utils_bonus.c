/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahid <schahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 13:07:05 by schahid           #+#    #+#             */
/*   Updated: 2022/01/01 16:03:00 by schahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i ;

	i = 0 ;
	while (str[i])
	{
		i++;
	}
	return (i);
}

static int	ft_isspace(const char str)
{
	return ((str >= 9 && str <= 13) || str == 32);
}

int	ft_atoi(const char *str)
{
	int	res ;
	int	i ;
	int	sign ;

	res = 0 ;
	i = 0 ;
	sign = 1 ;
	while (ft_isspace(*str))
		str++ ;
	if (*str == '-')
	{
		sign = -1 ;
		str++;
	}
	else if (*str == '+')
		str++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0') * sign ;
		i++;
	}
	return (res);
}
