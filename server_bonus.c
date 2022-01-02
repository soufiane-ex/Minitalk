/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahid <schahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:52:22 by schahid           #+#    #+#             */
/*   Updated: 2022/01/01 16:27:25 by schahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_message	g_msg;

void	bit_handler(int bit, siginfo_t *info, void *context)
{
	(void)context;
	g_msg.c += ((bit & 1) << g_msg.i);
	g_msg.i++;
	if (g_msg.i == 8)
	{
		ft_printf("%c", g_msg.c);
		if (!g_msg.c)
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR2);
		}
		g_msg.c = 0;
		g_msg.i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("****************************************************\n");
	ft_printf("********Welcome to the server (Bonus part)**********\n");
	ft_printf("****************************************************\n");
	ft_printf("Server PID : %d\n", getpid());
	sa.sa_sigaction = bit_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
		pause();
	return (0);
}
