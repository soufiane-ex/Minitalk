/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahid <schahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:16:51 by schahid           #+#    #+#             */
/*   Updated: 2021/12/27 18:40:10 by schahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "ft_printf/ft_printf.h"

typedef struct s_message
{
    char    c;
    size_t  i;   
}   t_message;

void                        bit_handler(int bit);
void                        send_bit(int pid, char *str, size_t len);

size_t	                    ft_strlen(const char *str);
int                         ft_atoi(const char *str);

#endif
