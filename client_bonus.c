/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahid <schahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:50:14 by schahid           #+#    #+#             */
/*   Updated: 2021/12/30 18:36:47 by schahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static t_message	msg;

void	send_bit(int pid, char *str, size_t len)
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

void	bit_handler(int bit)
{

	msg.c += ((bit & 1) << msg.i);
	msg.i++;
	if (msg.i == 15)
	{
		ft_printf("%c", msg.c);
		if(!msg.c)
			ft_printf("\n");
		msg.c = 0;
		msg.i = 0;
	}
}

int main(int argc, char **argv)
{
	int		pid;
	char	*str;
	int		my_pid;
	char	*id;

	my_pid =  getpid();
	id = ft_itoa(my_pid);
	
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		send_bit(pid, str, ft_strlen(str));
		send_pid(pid, id, ft_strlen(id));
		while (1)
		{
			signal(SIGUSR2, bit_handler);
			signal(SIGUSR1, bit_handler);
			pause();
		}
	}
	else
		ft_printf("\nPrototype : ./client_bonus [SERVER-PID] [MESSAGE]\n");
}