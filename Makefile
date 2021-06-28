# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 23:18:13 by taejkim           #+#    #+#              #
#    Updated: 2021/06/28 19:38:30 by taejkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_B = checker

CC = gcc
CFLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a

SRCDIR = ./srcs/
OBJDIR = ./objs/

SRC	= main.c \
	push_swap.c \
	make_stack_a.c \
	a_five_stack.c \
	a_three_stack.c \
	a_three_part.c \
	b_three_part.c \
	part.c \
	pivot.c \
	command_push.c \
	command_swap.c \
	command_rotate.c \
	command_rrotate.c \
	utils.c
	
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))


all: $(OBJDIR) $(NAME)

$(OBJ): $(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $@

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@

clean:
	@rm -rf $(OBJDIR)
	@make clean -C libft

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
