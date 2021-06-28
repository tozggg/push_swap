# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 23:18:13 by taejkim           #+#    #+#              #
#    Updated: 2021/06/28 17:53:02 by taejkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra
RM			=	rm -rf

SRCDIR	=	./srcs
OBJDIR	=	./objs

SRC		=	$(SRCDIR)main.c \
	$(SRCDIR)push_swap.c \
	$(SRCDIR)make_stack_a.c \
	$(SRCDIR)a_five_stack.c \
	$(SRCDIR)a_three_stack.c \
	$(SRCDIR)a_three_part.c \
	$(SRCDIR)b_three_part.c \
	$(SRCDIR)part.c \
	$(SRCDIR)pivot.c \
	$(SRCDIR)command_push.c \
	$(SRCDIR)command_swap.c \
	$(SRCDIR)command_rotate.c \
	$(SRCDIR)command_rrotate.c \
	$(SRCDIR)utils.c
OBJ		=	$(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))


$(LIBFT):
	@make -C ../libft all

$(NAME): $(OBJ) $(LIBFT)
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $^ -o $@

all: $(NAME)

clean:
	@make -C ../libft clean
	@$(RM) $(OBJDIR)

fclean: clean
	@make -C ../libft fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
