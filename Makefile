# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/18 02:56:16 by kyang             #+#    #+#              #
#    Updated: 2016/12/11 15:39:43 by kyang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Werror -Wextra

SOURCE = ft_strnew.c utility.c maps.c solver.c fillit.c check_lshape.c\
		 check_t_zshape.c check_tetri.c main.c create_tetri_map.c\
		 tetri_map_util.c check_str.c ft_memset.c ft_putchar.c ft_putstr.c\
		 ft_bzero.c ft_putendl.c ft_strcat.c ft_strdel.c ft_strlen.c ft_strncat.c\

OBJ = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SOURCE) $(INCLU)
	gcc $(FLAGS) -o $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
