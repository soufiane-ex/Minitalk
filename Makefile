# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schahid <schahid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 14:55:53 by schahid           #+#    #+#              #
#    Updated: 2021/12/27 18:41:00 by schahid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1= server
NAME2= client
UTILS= minitalk_utils.c
PRINTF= ft_printf/libftprintf.a
FLAGS= -Wall -Wextra -Werror
CC= cc

all:
		@make -C ft_printf
		@${CC} ${FLAGS} server.c -o ${NAME1} ${UTILS} ${PRINTF}
		@${CC} ${FLAGS} client.c -o ${NAME2} ${UTILS} ${PRINTF}
		@echo "${BOLD}${PURPLE} server ${BOLD}${CYAN}AND ${BOLD}${PURPLE}client ${BOLD}${CYAN}PROGRAMS HAS BEEN COMPILED SUCCESSFULLY"
	
clean:
		@make clean -C ft_printf
		@rm -f ${NAME1}
		@rm -f ${NAME2}
		@echo "${BOLD}${GREEN} THE FILES HAS BEEN CLEANED SUCCESSFULLY (SERVER AND CLIENT)"
		
fclean: clean
		@make fclean -C ft_printf

re: fclean all
		
.PHONY: all