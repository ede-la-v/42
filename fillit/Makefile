# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 15:15:20 by alcaroff          #+#    #+#              #
#    Updated: 2017/11/24 14:38:12 by alcaroff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit
FLAGS	=	-Wall -Werror -Wextra
SRC		=	main.c check_tetriminos.c create_tetriminos.c resolve.c functions.c
OBJ		=	$(SRC:.c=.o)
LIBFT	=	libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@gcc $(OBJ) $(LIBFT) -o $(NAME) $(FLAGS) 

%.o: %.c
	@gcc -c $< -o $@ $(FLAGS)

$(LIBFT):
	@cd libft && $(MAKE)

clean:
	@rm -rf $(OBJ) && cd libft && $(MAKE) clean

fclean: clean
	@rm -rf $(NAME) && cd libft && $(MAKE) fclean


re: fclean all
