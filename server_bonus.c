/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahid <schahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:52:22 by schahid           #+#    #+#             */
/*   Updated: 2021/12/30 18:35:17 by schahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static t_message	msg;

int	    pid_handler(int bit)
{
    char *str;
    
    str = malloc(sizeof(char) * msg.i);
    if (!str)
        return(0);
	msg.c += ((bit & 1) << msg.i);
	msg.i++;
	if (msg.i == 15)
	{
		msg.c = *str;
		msg.c = 0;
		msg.i = 0;
	}
	return (ft_atoi(str));
}

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

int main(void)
{
	t_data data;
	sa.sa_handler = bit_handler;
	sa.sa_flags = SA_SIGINFO;
	data.c_pid = pid_handler(1); 
	msg.c = 0;
	msg.i = 0;
	ft_printf("********Welcome to the server (Bonus part)**********\n");
	ft_printf("***************************************\n");
	ft_printf("Server PID : %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR2, &sa, NULL);
		sigaction(SIGUSR1, &sa, NULL);
		pause();
	}
	send_bit(data.c_pid, "Message sent", 12);
	return (0);
}