# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 11:30:37 by npiya-is          #+#    #+#              #
#    Updated: 2022/09/18 22:30:25 by npiya-is         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra 

SRCS = push_swap.c \
       push_swap_reverse.c \
       push_swap_pab.c \
       push_swap_sab.c \
       push_swap_rotate.c \
       push_swap_utils.c \
       push_swap_utils2.c \
       push_swap_utils3.c \
       push_swap_utils4.c \
       push_swap_utils5.c \


SRCS2 = push_swap2.c \
       push_swap_reverse.c \
       push_swap_pab.c \
       push_swap_sab.c \
       push_swap_rotate.c \
       push_swap_utils.c \
       push_swap_utils2.c \
       push_swap_utils3.c \
       push_swap_utils4.c \

NAME = push_swap

NAME2 = push_swap2

all:$(NAME)

$(NAME):$(SRCS)
	$(CC) -g $(CFLAGS) -o $(NAME) main_swap.c $(SRCS) -L libft/ -lft


$(NAME2):$(SRCS)
	$(CC) -g $(CFLAGS) -o $(NAME2) main_swap.c $(SRCS2) -L libft/ -lft

fclean:
	rm -rf $(NAME)

fclean1:
	rm -rf $(NAME2)

re: fclean all

re1: fclean1 $(NAME2) 
