# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 18:52:36 by dhendzel          #+#    #+#              #
#    Updated: 2023/01/25 19:23:49 by dhendzel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_B = Bonus/checker

SRCS =  initial_actions.c \
sorting.c \
check.c \
fs_for_sorting_2.c \
fs_for_sorting.c \
fs_str.c \
ft_atoi.c \
ft_split.c \
itoa.c \
list_fuctions.c \
list_fuctions_2.c \
list_fuctions_3.c \
main.c \
operations.c \
rotate_b.c \
operations_push.c \
operations_swap.c \
step_count_b.c

SRCS_B = Bonus/check.c \
Bonus/fs_str.c \
Bonus/ft_atoi.c \
Bonus/ft_split.c \
Bonus/ft_strncmp.c \
Bonus/get_next_line.c \
Bonus/get_next_line_utils.c \
Bonus/itoa.c \
Bonus/list_fuctions.c \
Bonus/list_fuctions_2.c \
Bonus/list_fuctions_3.c \
Bonus/main.c


OBJ	= $(SRCS:.c=.o)
OBJ_B = $(SRCS_B:.c=.o)
 
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRCS) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -c $^ -o $@

bonus : $(SRCS_B) $(OBJ_B)
	$(CC) $(CFLAGS) $(OBJ_B) -o $(NAME_B)
	@mv $(NAME_B) .

clean :
	@rm -f $(OBJ) $(OBJ_B) bonus_exec
	
fclean : clean
	@rm -f $(NAME) checker
		
re : fclean all

.PHONY : all clean fclean re bonus