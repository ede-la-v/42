# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 17:01:43 by ede-la-v          #+#    #+#              #
#    Updated: 2017/12/22 18:52:51 by ede-la-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	checker
NAME2	=	push_swap
FLAGS	=	-Wall -Werror -Wextra
SRC		=	check.c op_possible.c process_check.c get_next_line.c check_int.c
SRC2	=	algo.c algo1.c algo3.c algo4.c all_r_rotate.c all_swap.c op_possible.c algo_appendix.c algo_appendix2.c algo3_appendix.c all_rotate.c first_op.c push.c algo_recu.c premier_tri.c premier_tri2.c
OBJ		=	$(DIRSRC:.c=.o)
OBJ2	=	$(DIRSRC2:.c=.o)
CHECK	=	check/
PUSH	=	push/
DIRSRC	=	$(addprefix $(CHECK), $(SRC))
DIRSRC2	=	$(addprefix $(PUSH), $(SRC2))

all: LIB $(NAME) 

$(NAME):  $(NAME2) $(OBJ) 
	@gcc $(OBJ) libft/libft.a -o $(NAME) $(FLAGS) 


$(NAME2): $(OBJ2) 
	@gcc $(OBJ2) libft/libft.a -o $(NAME2) $(FLAGS) 

%.o: %.c
	@gcc -c $< -o $@ $(FLAGS)

LIB:
	@make -C libft/

clean:
	@rm -rf $(OBJ) && rm -rf $(OBJ2) && make clean -C libft/

fclean: clean
	@rm -rf $(NAME) && rm -rf $(NAME2) && make fclean -C libft/

re: fclean all
