# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 11:30:37 by npiya-is          #+#    #+#              #
#    Updated: 2022/09/24 22:48:20 by npiya-is         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra 

SRCS = push_swap.c \
       push_swap_formatinput.c \
       push_swap_checkinput.c \
       push_swap_findindex.c \
       push_swap_sortcondition.c \
       push_swap_sorta.c \
       push_swap_sorta2.c \
       push_swap_reverse.c \
       push_swap_pab.c \
       push_swap_sab.c \
       push_swap_rotate.c \
       push_swap_checksort.c \
       push_swap_lstmethod.c \
       push_swap_lstmethod2.c \
       push_swap_printlst.c \
       ft_atoi.c \
       ft_isdigit.c \
       ft_split.c \
       push_swap_utils.c \


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

NAME3 = test_pab

all:$(NAME)

$(NAME):$(SRCS)
	$(CC) -g $(CFLAGS) -o $(NAME) main_swap.c $(SRCS) -L libft/ -lft


$(NAME2):$(SRCS)
	$(CC) -g $(CFLAGS) -o $(NAME2) main_swap.c $(SRCS2) -L libft/ -lft

$(NAME3):$(SRCS)
	$(CC) -g $(CFLAGS) -o $(NAME3) test_pab.c $(SRCS) -L libft/ -lft

fclean:
	rm -rf $(NAME)

fclean1:
	rm -rf $(NAME2)

fclean2:
	rm -rf $(NAME3)

re: fclean all

re1: fclean1 $(NAME2) 

re2: fclean2 $(NAME3) 
