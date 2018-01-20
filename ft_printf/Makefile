# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/26 17:41:51 by ede-la-v          #+#    #+#              #
#    Updated: 2017/12/13 19:53:33 by ede-la-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
FLAGS	=	-Wall -Wextra -Werror
SRC		=	add_lst.c fill_flag.c fill_flag_width_etc.c fill_size_conv.c	fill_variables.c ft_printf.c new_variable.c search.c display.c ft_itoa_gen.c ft_itoa_gen_u.c ft_itoa_gen_bx.c ft_itoa_gen_u_int.c ft_itoa_gen_bx_int.c action_flag.c action_hash.c size_ll_l.c size_hard.c size_other.c size_j_z.c size_hh_h.c putwchar.c width.c

SRCS	= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_isupper.c ft_islower.c ft_swap.c ft_is_negative.c ft_strpos.c ft_strpos2.c

OBJ		=	$(SRC:.c=.o)
OBJ2	=	$(NEWLIB:.c=.o)
LIBFT	=	libft/
NEWLIB	=	$(addprefix $(LIBFT), $(SRCS))

all: $(NAME)

$(NAME): $(OBJ) $(OBJ2) $(LIBFT)
	@ar rc $(NAME) $(OBJ) $(OBJ2)
	@ranlib $(NAME)

%.o: %.c
	@gcc -c $< -o $@ $(FLAGS)

clean:
	@rm -rf $(OBJ) $(OBJ2) 

fclean: clean
	@rm -rf $(NAME)

re: fclean all
