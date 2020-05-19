# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/09 18:07:37 by whumfrey          #+#    #+#              #
#    Updated: 2018/12/10 18:32:11 by whumfrey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -Wall -Wextra -Werror
HEAD = -c libft.h 
SRCS = *.c
OBJ = *.o

all: $(NAME) 

$(NAME):
	gcc $(FLAG) $(HEAD) $(SRCS)
	ar rc $(NAME) $(OBJ)
clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all

