# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schahid <schahid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 14:55:53 by schahid           #+#    #+#              #
#    Updated: 2022/01/02 12:03:42 by schahid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1= server
NAME2= client
BONUS1= server_bonus
BONUS2= client_bonus
UTILS= minitalk_utils.c
UTILS_B= minitalk_utils_bonus.c
PRINTF= ft_printf/libftprintf.a
FLAGS= -Wall -Wextra -Werror -g
CC= cc

all:
		@make -C ft_printf
		@${CC} ${FLAGS} server.c -o ${NAME1} ${UTILS} ${PRINTF}
		@${CC} ${FLAGS} client.c -o ${NAME2} ${UTILS} ${PRINTF}
		@echo "${BOLD}${PURPLE} server ${BOLD}${CYAN}AND ${BOLD}${PURPLE}client ${BOLD}${CYAN}PROGRAMS HAS BEEN COMPILED SUCCESSFULLY"
		
%.o: %.c minitalk.h
	$(CC) -c $(CFLAGS) $< -o $@
	
bonus: all
		@${CC} ${FLAGS} server_bonus.c -o ${BONUS1} ${UTILS_B} ${PRINTF}
		@${CC} ${FLAGS} client_bonus.c -o ${BONUS2} ${UTILS_B} ${PRINTF}
		@echo "${BOLD}${PURPLE} server_bonus ${BOLD}${CYAN}AND ${BOLD}${PURPLE}client_bonus ${BOLD}${CYAN}PROGRAMS HAS BEEN COMPILED SUCCESSFULLY"
clean:
		@make clean -C ft_printf
		@rm -f ${NAME1} ${BONUS1}
		@rm -f ${NAME2} ${BONUS2}
		@echo "${BOLD}${GREEN} THE FILES HAS BEEN CLEANED SUCCESSFULLY (SERVER AND CLIENT)"
		
fclean: clean
		@make fclean -C ft_printf

re: fclean all
		
.PHONY: all clean fclean re bonus
