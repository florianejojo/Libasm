# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flolefeb <flolefeb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 20:03:06 by flolefeb          #+#    #+#              #
#    Updated: 2020/10/22 16:53:28 by flolefeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a

SRCS		=	ft_strlen.s ft_read.s ft_write.s ft_strcpy.s ft_strdup.s 

HEADER		=	libasm.h

OBJS		=	$(SRCS:.s=.o)

CC			= 	clang

NA			=	nasm
NA_FLAGS	=	-f macho64

%.o:			%.s
				$(NA) $(NA_FLAGS) $<

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

test:			$(NAME) $(HEADER)
				clang -Wall -Wextra -Werror libasm.h main.c libasm.a
				./a.out

clean:
				rm -rf $(OBJS)
				rm -rf ./a.out

fclean:			clean
				rm -rf $(NAME) 

re:				fclean $(NAME)