# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 18:32:16 by npiya-is          #+#    #+#              #
#    Updated: 2022/04/21 20:21:27 by npiya-is         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = ../push_swap.c \
       ../push_swap_reverse.c \
       ../push_swap_pab.c \
       ../push_swap_sab.c \
       ../push_swap_rotate.c \
       ../push_swap_utils.c \
       ../push_swap_utils2.c \
       ../push_swap_utils3.c \

COUNT = count

CHECK = check

PAB = pab

TEST_PAB = main_pab.c

TEST_COUNT = main_count.c

TEST_SORT = main_sort.c

TEST_PAB = main_pab.c

$(COUNT):
	$(CC) $(CFLAGS) -o $(COUNT) $(TEST_COUNT) $(SRCS) -L ../libft/ -lft

$(CHECK):
	$(CC) $(CFLAGS) -o $(CHECK) $(TEST_SORT) $(SRCS) -L ../libft/ -lft

$(PAB):
	$(CC) $(CFLAGS) -o $(PAB) $(TEST_PAB) $(SRCS) -L ../libft/ -lft


fclean:
	rm -rf $(COUNT) $(CHECK) $(PAB)

recount: fclean count

recheck: fclean check

repab: fclean pab

.PHONY: count sort clean recount resort pab 
