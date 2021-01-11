# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/08 11:21:58 by aes-salm          #+#    #+#              #
#    Updated: 2021/01/11 10:06:20 by aes-salm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
SRCS = 	ft_asm/ft_strlen.s \
		ft_asm/ft_write.s \
		ft_asm/ft_strcmp.s \
		ft_asm/ft_strcpy.s \
		ft_asm/ft_read.s\
		ft_asm/ft_strdup.s\

OBJS = $(SRCS:.s=.o)
CC = gcc
FLAGS = -Wall -Werror -Wextra
NA = nasm
NA_FLAGS = -f macho64

%.o:			%.s
				@ $(NA) $(NA_FLAGS) $<

$(NAME):	$(OBJS)
			@ ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
		@ rm -rf $(OBJS)

fclean: clean
		@ rm -rf $(NAME) a.out

re: fclean $(NAME)

test:	re
		@ $(CC) $(FLAGS) -L. -lasm main.c libasm.a
		@ ./a.out