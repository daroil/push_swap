# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 13:47:58 by dhendzel          #+#    #+#              #
#    Updated: 2023/01/28 04:51:04 by dhendzel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = push_swap
BONUS_NAME = checker
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f
# LIBFT	:= ./libft
MAND_SRCS = main \
			atoi \
			ft_split \
			ft_strdup \
			ft_strlen \
			ft_putstr_fd \
			push \
			rev_rotate \
			rotate \
			lst_functions \
			find_min_max \
			swap \
			step_count \
			helpers \
			checks \
			initial_sort \
			extensive_sort \
			rotate_push \
			rev_rotate_push

BONUS_SRCS = main \
			ft_split \
			ft_strdup \
			ft_strlen \
			helpers \
			push \
			rev_rotate \
			rotate \
			swap \
			ft_putstr_fd \
			checks \
			lst_functions \
			atoi \
			get_next_line \
			get_next_line_utils

MAND_OBJS = $(MAND_FIL:.c=.o)
BONUS_OBJS = $(BONUS_FIL:.c=.o)
MAND_FIL = $(addsuffix .c, $(MAND_SRCS)) \

BONUS_FIL = $(addsuffix .c, $(addprefix bonus/, $(BONUS_SRCS))) \


all : $(NAME)

# libft:
# 	@$(MAKE) -C $(LIBFT)
	
$(MAND_OBJS): %.o : %.c
	gcc $(CFLAGS) -c -o $@ $<

$(NAME) : $(MAND_OBJS)
	gcc $(CFLAGS) $^ -o $@

clean :
	$(RM) $(MAND_OBJS) $(BONUS_OBJS)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)

bonus: $(BONUS_OBJS)
	gcc $(CFLAGS) $^ -o $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus