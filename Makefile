# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 11:30:37 by npiya-is          #+#    #+#              #
#    Updated: 2022/04/16 11:44:51 by npiya-is         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c \
       push_swap_reverse.c \
       push_swap_pab.c \
       push_swap_sab.c \
       push_swap_rotate.c \
       push_swap_utils.c \
       push_swap_utils2.c \
       push_swap_utils3.c \

NAME = swap

all:$(NAME)

$(NAME):$(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) main_swap.c $(SRCS) -L libft/ -lft

fclean:
	rm -rf $(NAME)

re: fclean all
