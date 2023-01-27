# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 13:47:58 by dhendzel          #+#    #+#              #
#    Updated: 2023/01/27 18:19:08 by dhendzel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f
# LIBFT	:= ./libft
MAND_SRCS = main \
			atoi \
			ft_split \
			ft_strdup \
			ft_strlen \
			ft_putstr_fd \
			operations			

BONUS_SRCS = main \
			

MAND_OBJS = $(MAND_FIL:.c=.o)
BONUS_OBJS = $(BONUS_FIL:.c=.o)
# $(addprefix mand/, $(MAND_SRCS))
MAND_FIL = $(addsuffix .c, $(MAND_SRCS)) \
#  $(addprefix bonus/,
BONUS_FIL = $(addsuffix _bonus.c, $(MAND_SRCS)) \


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

bonus: libft bonuss 

bonuss: $(BONUS_OBJS)
	gcc $(CFLAGS) $^ -o $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus bonuss