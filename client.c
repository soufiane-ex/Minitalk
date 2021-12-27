/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahid <schahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:36:46 by schahid           #+#    #+#             */
/*   Updated: 2021/12/27 18:54:33 by schahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(int pid, char *str, size_t len)
{
	int	shift;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		shift = 0 ;
		while (shift < 7)
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
    if (SIGUSR2)
            ft_printf("bien recus");
}
int main(int argc, char **argv)
{
	int		pid;
	char	*str;
	
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		send_bit(pid, str, ft_strlen(str));
	}
	else
		ft_printf("\nPrototype : ./client [SERVER-PID] [MESSAGE]\n");
}