# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/07 11:05:31 by jiezhang          #+#    #+#              #
#    Updated: 2025/12/07 11:08:08 by jiezhang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFALG = -I. -Wall -Wextra -Werror

AR = ar -rcs

NAME = libftprintf.a

HEADER = ft_printf.h 

SRCS = ft_printf.c ft_printf_utils.c 

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o:%.c $(HEADER)
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re