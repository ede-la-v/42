#'**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 17:01:43 by ede-la-v          #+#    #+#              #
#    Updated: 2017/12/27 15:51:56 by ede-la-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ede-la-v.filler
FLAGS	=	-Wall -Werror -Wextra
SRC		=	main.c handle_output.c answer.c get_next_line.c fn_add.c answer_check.c score.c if_player.c fn_free.c 
OBJ		=	$(DIRSRC:.c=.o)
CHECK	=	source/
DIRSRC	=	$(addprefix $(CHECK), $(SRC))

all: LIB $(NAME) 

$(NAME):  $(OBJ) 
	@gcc $(OBJ) libft/libft.a -o $(NAME) $(FLAGS) 

%.o: %.c
	@gcc -c $< -o $@ $(FLAGS)

LIB:
	@make -C libft/

clean:
	@rm -rf $(OBJ) && make clean -C libft/

fclean: clean
	@rm -rf $(NAME) && make fclean -C libft/

re: fclean all
