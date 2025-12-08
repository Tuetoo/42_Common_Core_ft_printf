# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/22 14:02:41 by jiezhang          #+#    #+#              #
#    Updated: 2025/11/12 10:28:49 by jiezhang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# the compiler to use
CC = cc

# compiler flags: show all warnings, extra warnings, treat warnings as errors
CFLAGS = -Wall -Wextra -Werror -I.

#define archiver;command to create a static library 
# ar:create .a static library
# r: replace or add files; c: create the archive; s: write an index (symbol table)
AR = ar -rcs

#name of the final library file
NAME = libft.a

#define header, header file dependency
HEADER = libft.h

#list of source files
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c  \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

#replace all .c extension with .o to get object files
OBJ = $(SRCS:.c=.o)

#list of bonus source files
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJ = $(BONUS:.c=.o)

#build rule for library: create libft.a from all object files
#target is $(NAME)(libft.a), dependence are $(OBJ)(object files)
$(NAME):$(OBJ)
	$(AR) $(NAME) $(OBJ)

#pattern rule: compile each .c into .o
# % matches any filename stem.
# $<:the first dependency eg: .c files; $@: the target eg: .o file
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

#bonus target adds the bonus object files to the library
#both source and bonus objects are archived into libft.a
#if the library exists, AR command just updates it
bonus: $(OBJ) $(BONUS_OBJ)
	$(AR) $(NAME) $(OBJ) $(BONUS_OBJ)


#default target, run make
all: $(NAME)

#remove all object files
clean:
	rm -f $(OBJ) $(BONUS_OBJ)

#remove object files and the final library
fclean: clean
	rm -f $(NAME)

#rebuild everything from scratch
re: fclean all

#declare non-file targets to avoid conflicts
#.PHONY declares phony targets, targets do not represent real files
#"they are just commonds, not files, always run when requested"
.PHONY: all clean fclean re bonus
