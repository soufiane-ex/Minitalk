/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahid <schahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:50:01 by schahid           #+#    #+#             */
/*   Updated: 2022/01/01 16:02:09 by schahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include "ft_printf/ft_printf.h"

typedef struct s_message
{
	char	c;
	size_t	i;
}	t_message;

void						bit_handler(int bit,
								siginfo_t *info, void *context);
void						send_bit(int pid, char *str, size_t len);
void						fucking_handler(int sig);

void						send_pid(int pid, char *str, size_t len);
int							pid_handler(int bit);
size_t						ft_strlen(const char *str);
int							ft_atoi(const char *str);

#endif
