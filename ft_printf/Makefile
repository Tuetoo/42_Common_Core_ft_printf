# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/08 10:24:03 by jiezhang          #+#    #+#              #
#    Updated: 2025/12/08 11:10:48 by jiezhang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# the compiler to use
CC = cc

# compiler flags: show all warnings, extra warnings, treat warning as errors
# -I <dir>: include directory, add an include directory for header files
# it tells the compiler where to look for .h files
# -I. :search headers in current folder; # -I./libft :search headers in ./libft
CFLAGS =  -I. -I./libft -Wall -Wextra -Werror
# define archiver, commond to create a static library
# ar: create .a static library
# r: replace or add files, c: create the archiver, s: write an index (symbol table)
AR = ar -rcs

# name of the library file 
NAME = libftprintf.a

# define header, header file dependency
HEADER = ft_printf.h

# list of source files
SRCS = ft_printf.c ft_putnchar.c ft_putchar_format.c ft_putstr_format.c ft_putdigit_format.c \
		ft_putnbr_base.c ft_putpointer_format.c

# replace all .c extension with .o to get object files
OBJ = $(SRCS:.c=.o)

# path to libft directory and library
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# default target, run make
all: $(NAME)

bonus: all

# build rule for library: create libftprintf.a library from all object files
# target is $(NMAE)(libftprintf.a), dependence are $(OBJ) (object files)
# "make" or "make all" will compile the libft first
# then build the ft_printf static library by combining both
# -C: change directory to <dir> before reading the Makefile
# cp: copy the libft library to the target library
$(NAME):$(OBJ)
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ)

exec: $(NAME)
	$(CC) $(CFLAGS) ft_printf.c -L. -lftprintf -o printf_test

# pattern rule: compile each .c into .o
# % matches any filename stem
# $<: the first dependency, eg: .c files; $@: the target, eg: .o files
%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# remove all object files (1. files in libft 2. ft_printf obj)
clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

# remove object fileas and the library
fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

# rebuild everything from scrach
re: fclean all

# declare non-file target to avoid conflicts
# .PHONY declares PHONY targets, targets do not represent real files
# "they are just commonds not files, always run when requested"
.PHONY: all clean fclean re bonus
