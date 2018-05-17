#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/17 20:27:02 by vgryshch          #+#    #+#              #
#    Updated: 2018/01/30 15:29:58 by vgryshch         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC = main.c checker.c loader.c iterator.c pool.c

LIB = ./libft/libft.a

OBJECT = $(SRC:.c=.o)

OPTIONS = -c -I

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJECT)
	make -C ./libft/ all
	gcc -o $(NAME) $(FLAGS) $(SRC) $(LIB)

%.o: %.c
	@gcc $(FLAGS) -c -o $@ $<

clean:
	make -C ./libft/ clean
	rm -f $(OBJECT)
fclean: clean
	make -C ./libft/ fclean
	rm -f $(NAME)
re: fclean all
