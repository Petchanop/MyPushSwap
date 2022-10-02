# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 11:30:37 by npiya-is          #+#    #+#              #
#    Updated: 2022/10/03 03:13:25 by npiya-is         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

SRCS_DIR = ./srcs
UTILS_DIR = ./utils
OPER_DIR = ./operations
BONUS_DIR = ./bonus
BUILD_DIR = build

SRCS = main_swap.c \
       push_swap.c \
       push_swap_sortcondition.c \
       push_swap_sorta.c \
       push_swap_sorta2.c \

OPER =  push_swap_reverse.c \
       push_swap_pab.c \
       push_swap_sab.c \
       push_swap_rotate.c \
       push_swap_printlst.c \
       push_swap_formatinput.c \
       push_swap_checkinput.c \
       push_swap_checksort.c \
       push_swap_findindex.c \
       push_swap_lstmethod.c \
       push_swap_lstmethod2.c \

UTILS =   ft_atoi.c \
       ft_isdigit.c \
       ft_split.c \
       ft_strncmp.c \
       ft_strjoin.c \
       push_swap_utils.c \

SRCS_BONUS = push_swap_checker.c \
       checker_operation.c \
       checker_readinput.c \

OBJS=$(SRCS:%.c=$(BUILD_DIR)/%.o)
OBJS_OPER=$(OPER:%.c=$(BUILD_DIR)/%.o)
OBJS_UTILS=$(UTILS:%.c=$(BUILD_DIR)/%.o)
OBJS_BONUS=$(SRCS_BONUS:%.c=$(BUILD_DIR)/%.o)

NAME = push_swap

DEBUG = debug

BONUS = checker_bonus

PRINTF = ft_printf

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_OPER) $(OBJS_UTILS)
	make -C $(PRINTF)
	$(CC) -g $(CFLAGS) $(OBJS) $(OBJS_OPER) $(OBJS_UTILS) -L ft_printf/ -lftprintf -o $(NAME)

$(OBJS): $(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I . -I $(SRCS_DIR) -c $< -o $@

$(OBJS_OPER): $(BUILD_DIR)/%.o: $(OPER_DIR)/%.c
	@$(CC) $(CFLAGS) -I . -I $(OPER_DIR) -c $< -o $@

$(OBJS_UTILS): $(BUILD_DIR)/%.o: $(UTILS_DIR)/%.c
	@$(CC) $(CFLAGS) -I . -I $(UTILS_DIR) -c $< -o $@

$(DEBUG): $(SRCS)
	make -C $(PRINTF)
	$(CC) -g $(CFLAGS) $(SRCS) -L ft_printf/ -lftprintf -o $(DEBUG)

bonus: $(OBJS_BONUS) $(OBJS_OPER) $(OBJS_UTILS)
	make -C $(PRINTF)
	$(CC) -g $(CFLAGS) $(OBJS_BONUS) $(OBJS_OPER) $(OBJS_UTILS) -L ft_printf/ -lftprintf -o $(BONUS)

$(OBJS_BONUS): $(BUILD_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I . -I $(BONUS_DIR) -c $< -o $@

clean:
	make -C $(PRINTF) clean 
	rm -rf $(BUILD_DIR)

fclean:clean
	make -C $(PRINTF) fclean
	rm -rf $(NAME)
	rm -rf $(BONUS)

re: fclean all

.PHONY:clean fclean re all
