# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schahid <schahid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 15:35:45 by schahid           #+#    #+#              #
#    Updated: 2021/12/27 15:26:16 by schahid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Files
NAME = libftprintf.a
SRC = ft_itoa.c ft_printf_address.c ft_printf_hex.c ft_printf_unsigned.c ft_printf_utils.c ft_printf.c ft_putchar_fd.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ = $(patsubst %.c,%.o,$(SRC))
#Text
END=$'\x1b[0m
BOLD=$'\x1b[1m
UNDER=$'\x1b[4m
REV=$'\x1b[7m
#Colors
GREY=$'\x1b[30m
RED=$'\x1b[31m
GREEN=$'\x1b[32m
YELLOW=$'\x1b[33m
BLUE=$'\x1b[34m
PURPLE=$'\x1b[35m
CYAN=$'\x1b[36m
WHITE=$'\x1b[37m

all: $(NAME)

%.o: %.c ft_printf.h
		@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@echo "${BOLD}${PURPLE} ft_Printf ${BOLD}${CYAN}HAS BEEN COMPILED SUCCESSFULLY"

clean:
		@rm -f $(OBJ)
		@echo "${BOLD}${GREEN} THE FILES HAS BEEN CLEANED SUCCESSFULLY (FT_PRINTF)"
fclean:
		@rm -f $(NAME)
		@echo "${BOLD}${PURPLE} libftprintf.a ${BOLD}${WHITE}HAS BEEN CLEANED SUCCESSFULLY"

re: fclean all

.PHONY: all clean fclean re