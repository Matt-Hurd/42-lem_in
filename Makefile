# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/28 19:34:56 by mhurd             #+#    #+#              #
#    Updated: 2017/01/02 17:42:48 by mhurd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	lem-in

SRC	=		main.c \
			parse.c \
			solve.c \
			paths.c \
			printer.c \
			error.c \
			validate.c \
			helpers.c \
			bonus.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -O3 -funroll-loops -march=native

LIBFT	= ./libft/libft.a
LIBINC	= -I./libft/includes
LIBLINK	= -L./libft -lft

SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: obj libft $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(LIBINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJ) $(LIBLINK)

clean:
	rm -rf $(OBJDIR)
	make -C ./libft clean

fclean: clean
	rm -rf $(NAME)
	make -C ./libft fclean

re: fclean all
