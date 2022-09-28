# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 11:30:37 by npiya-is          #+#    #+#              #
#    Updated: 2022/09/29 00:59:47 by npiya-is         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

SRCS = main_swap.c \
       push_swap.c \
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

SRCS_BONUS = push_swap_checker.c \
       push_swap_formatinput.c \
       push_swap_checksort.c \
       push_swap_checkinput.c \
       push_swap_findindex.c \
       push_swap_reverse.c \
       push_swap_pab.c \
       push_swap_sab.c \
       push_swap_rotate.c \
       push_swap_lstmethod.c \
       push_swap_lstmethod2.c \
       push_swap_printlst.c \
       ft_atoi.c \
       ft_isdigit.c \
       ft_split.c \
       ft_strncmp.c \
       ft_strjoin.c \
       push_swap_utils.c \
       checker_operation.c \
       checker_readinput.c \

OBJS=$(SRCS:.c=.o)
OBJS_BONUS=$(SRCS_BONUS:.c=.o)

NAME = push_swap

DEBUG = debug

BONUS = checker_bonus

PRINTF = ft_printf

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(PRINTF)
	$(CC) -g $(CFLAGS) $(OBJS) -L ft_printf/ -lftprintf -o $(NAME)

$(DEBUG): $(SRCS)
	make -C $(PRINTF)
	$(CC) -g $(CFLAGS) $(SRCS) -L ft_printf/ -lftprintf -o $(DEBUG)

bonus: $(SRCS_BONUS)
	$(CC) -g $(CFLAGS) $(SRCS_BONUS) -L ft_printf/ -lftprintf -o $(BONUS)

clean:
	make -C $(PRINTF) clean 
	rm -rf $(OBJS)

fclean:clean
	rm -rf $(NAME)
	rm -rf $(BONUS)

re: fclean all

.PHONY:clean fclean re all
