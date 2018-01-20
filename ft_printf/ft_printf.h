/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:03:00 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/14 15:26:44 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct	s_variable
{
	char				flag[6];
	long				width;
	long				precision;
	char				size[3];
	char				conv;
	int					error;
	struct s_variable	*next;
}				t_variable;

typedef struct	s_double
{
	char	*char_n;
	wchar_t	*char_w;
}				t_double;

int				ft_printf(const char *format, ...);
void			fill_variables(char *format, t_variable **lst);
int				fill_flag(char *format, t_variable *variable, int *i);
void			fill_width(char *format, t_variable *variable, int *i);
void			fill_precision(char *format, t_variable *variable, int *i);
void			fill_size(char *format, t_variable *variable, int *i);
int				fill_conv(char *format, t_variable *variable, int *i);
void			add_lst(t_variable **variable, t_variable *new);
void			free_lst(t_variable **lst);
t_variable		*new_variable(void);
t_double		search(va_list args, t_variable **lst);
int				display(va_list args, t_variable **lst);
void			precision(t_variable **lst, char **str, intmax_t var_int);
void			plus(t_variable **lst, char **str, intmax_t var_int);
void			width(t_variable **lst, char **str, intmax_t var_int);
void			hash(t_variable **lst, char **str, intmax_t var_int);
char			*signed_char(va_list args, t_variable **lst);
char			*unsigned_char(va_list args, t_variable **lst);
char			*fshort(va_list args, t_variable **lst);
char			*unsigned_short(va_list args, t_variable **lst);
char			*flong(va_list args, t_variable **lst);
char			*unsigned_long(va_list args, t_variable **lst);
char			*long_long(va_list args, t_variable **lst);
char			*unsigned_long_long(va_list args, t_variable **lst);
char			*fintmax_t(va_list args, t_variable **lst);
char			*fuintmax_t(va_list args, t_variable **lst);
char			*fsize_t(va_list args, t_variable **lst);
char			*fint(va_list args, t_variable **lst);
wchar_t			*fwint_t(va_list args, t_variable **lst);
char			*char_s(va_list args, t_variable **lst);
wchar_t			*wchar_t_s(va_list args, t_variable **lst);
char			*void_s(va_list args, t_variable **lst);
char			*long_int(va_list args, t_variable **lst);
char			*ft_itoa_gen(intmax_t n);
char			*ft_itoa_gen_u_int(unsigned int n, int base);
char			*ft_itoa_gen_u(uintmax_t n, int base);
char			*ft_itoa_gen_bx_int(unsigned int n, int base);
char			*ft_itoa_gen_bx(uintmax_t n, int base);
void			exceptions(t_variable **lst, char **str);
int				is_dioux(char c);
int				putwchar(t_double dchar, t_variable **lst);
int				ft_putwstr(wchar_t *str, int max);
int				ft_putwchar(int bit[5], wchar_t arg, int max);
char			*gen_null(void);

#endif
