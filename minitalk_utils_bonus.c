/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahid <schahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:42:30 by schahid           #+#    #+#             */
/*   Updated: 2021/12/30 18:09:04 by schahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_pid(int pid, char *str, size_t len)
{
	int	shift;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		shift = 0 ;
		while (shift < 15)
		{
			if ((str[i] >> shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			shift++;
			usleep(100);
		}
		i++;
	}
}

