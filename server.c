/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahid <schahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:36:16 by schahid           #+#    #+#             */
/*   Updated: 2021/12/27 18:54:12 by schahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_message	msg;

void	bit_handler(int bit)
{
	msg.c += ((bit & 1) << msg.i);
	msg.i++;
	if (msg.i == 7)
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
	msg.c = 0;
	msg.i = 0;
	ft_printf("********Welcome to the server**********\n");
	ft_printf("***************************************\n");
	ft_printf("Server PID : %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, bit_handler);
		signal(SIGUSR1, bit_handler);
		pause();
	}
	return (0);
}
