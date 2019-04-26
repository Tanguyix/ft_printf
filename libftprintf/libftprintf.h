/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 02:53:23 by tboissel          #+#    #+#             */
/*   Updated: 2018/09/04 10:03:58 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <wchar.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFFER 1024

# define OCTAL 8
# define DECIMAL 10
# define HEXA 16
# define HEXA_MAJ 32
# define BINAIRE 2

typedef struct	s_conv
{
	int			conversion;
	char		hash;
	char		zero;
	char		plus;
	char		minus;
	char		space;
	int			champ;
	int			precision;
	char		lenght;
	char		pointeur;
	char		dot;
	intmax_t	nb;
	wchar_t		ch;
	wchar_t		*wstr;
	char		*str;
	uintmax_t	unb;
	int			*address;
	int			j_tot;
	int			j;
	int			actual_buf;
	char		malloc_error;
}				t_conv;

/*
** printf
*/
int				ft_printf(const char *str, ...);
int				ft_inner_printf(const char *s, va_list a, char *b, t_conv *c);
void			ft_reset_buffer(char *buf, t_conv *conv);
void			ft_reinitialize_struct(t_conv *conv);
int				ft_malloc_error(t_conv *conv);

/*
** parse
*/
int				ft_set_conv(char *str, t_conv *conv);
void			ft_store_lenght(char c, t_conv *conv);
char			ft_get_lenght(char *str);
int				ft_get_conversion(char *str, t_conv *conv, va_list ap);
int				ft_is_conversion(char c);
int				ft_parse(char *str, t_conv *conv, va_list ap);
int				ft_is_unknown(char c);
void			ft_champ_star(t_conv *conv, char *str, int i, va_list ap);
int				ft_dot(t_conv *conv, char *str, va_list ap);
void			ft_check_str(t_conv *conv, char *str, int i, va_list ap);

/*
** get_arg
*/
void			ft_get_arg(t_conv *conv, va_list ap);
void			ft_get_arg_di(t_conv *c, va_list ap);
void			ft_get_arg_uxo(t_conv *c, va_list ap);
void			ft_get_arg_s(t_conv *c, va_list ap);

/*
** which_conversion
*/
int				ft_which_conversion(t_conv *conv, char *buf);
int				ft_which_conversion_2(t_conv *conv, char *buf);

/*
** libft
*/

int				ft_size_base(uintmax_t va, int base);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *s, int fd);
int				ft_atoi(const char *s);
int				ft_isdigit(int c);
char			*ft_itoa(intmax_t n);
char			*ft_strcpy(char *dest, const char *src);
size_t			ft_strlen(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *s, int c, size_t n);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *s);
int				ft_get_size_nb(intmax_t nb);
char			*ft_itoa_base(uintmax_t unb, char *str, int base);

/*
** conv C
*/
int				ft_char_unicode(t_conv *conv, char *buf);
int				ft_nb_bytes_char(unsigned int va);
void			ft_fill_buff_c(char *buf, t_conv *conv, int nb_bytes);

/*
** conv bases : u, U, x, X, o, O, bonus b
*/
int				ft_base(t_conv *conv, char *buf, int base);
char			*ft_init_str(int base);
void			ft_base_fill(t_conv *conv, char *str_p, char *buf, int size);
int				ft_str_preci_ox(t_conv *conv, int base, char *str_preci);
void			ft_hash_xo(t_conv *conv, char *buf, int base);
char			*ft_malloc_str_p(t_conv *c, int *size);
char			*ft_create_str_preci(t_conv *c, int *size, int base, char *ito);
void			ft_b_fill_champ(t_conv *conv, char *buf, int size);

/*
** conv p
*/
int				ft_p(t_conv *conv, char *buf);

/*
** conv c
*/
int				ft_c(t_conv *conv, char *buf);
void			ft_champ_precision_c(t_conv *conv, char *buf);

/*
** conv d
*/
int				ft_d(t_conv *conv, char *buf);
char			*ft_precision_d(t_conv *conv, int *size, char *cp_itoaed);
char			*ft_general_d(t_conv *conv, int *size, char *cp_itoaed);
char			*ft_zero_champ(t_conv *conv, int size, char *cp_itoaed);
void			ft_fill_buf_d(t_conv *conv, char *str_pre, char *buf, int size);
int				ft_plus_dot_zero(t_conv *conv, char *buf);
char			*ft_set_precision(t_conv *conv, int *size, char *cp_itoaed);

/*
** conv s
*/
int				ft_s(t_conv *conv, char *buf);
void			ft_s2(t_conv *conv, int s_s_p, char *buf, char *str_precise);
int				ft_size_string(t_conv *conv);
void			ft_s_fill(t_conv *conv, char *buf, char *str_pre);
int				ft_s_null(t_conv *conv, char *buf, char *str_precise);
/*
** conv S
*/
int				ft_str_unicode(t_conv *conv, char *buf);
int				ft_actual_printed_bits(t_conv *conv);
int				ft_masks_unicode_str(t_conv *conv, char *buf, int nb_b, int i);
int				ft_precision_str_uni(t_conv *conv, char *buf, int nb_b);
void			ft_minus_champ_uni(t_conv *conv, char *buf, int i);
int				ft_weird_cases(t_conv *conv, char *buf);
void			ft_spaces(t_conv *conv, char *buf, int spaces);
void			ft_init(t_conv *conv, int *spaces);

/*
** conv bonus : n, B
*/
int				ft_n(t_conv *conv);
int				ft_bool(t_conv *conv, char *buf);

#endif
