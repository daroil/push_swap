# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 13:47:58 by dhendzel          #+#    #+#              #
#    Updated: 2023/01/18 14:01:18 by dhendzel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f
LIBFT	:= ./libft
MAND_SRCS = main \
			

BONUS_SRCS = main \
			

MAND_OBJS = $(MAND_FIL:.c=.o)
BONUS_OBJS = $(BONUS_FIL:.c=.o)
# $(addprefix mand/, $(MAND_SRCS))
MAND_FIL = $(addsuffix .c, $(MAND_SRCS)) \
#  $(addprefix bonus/,
BONUS_FIL = $(addsuffix _bonus.c, $(MAND_SRCS)) \


all : libft $(NAME)

libft:
	@$(MAKE) -C $(LIBFT)
	
$(MAND_OBJS): %.o : %.c
	gcc $(CFLAGS) -c -o $@ $<

$(NAME) : $(MAND_OBJS)
	gcc $(CFLAGS)  $(LIBFT)/libft.a $^ -o $@

clean :
	$(RM) $(MAND_OBJS) $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT) clean

fclean : clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean

bonus: libft bonuss 

bonuss: $(BONUS_OBJS)
	gcc $(CFLAGS) $(LIBFT)/libft.a $^ -o $(NAME)

re: fclean all

.PHONY: all clean fclean re libft bonus bonuss