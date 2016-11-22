/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:40:55 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:40:59 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# include <stdlib.h>
# define SHORT_TO_INT_NEGATIVE_MASK	0xffff0000
# define SHORT_VALUE_MASK			0x0000ffff
# define SHORT_SIGN_MASK				0x00008000
# define CHAR_TO_INT_NEGATIVE_MASK	0xffffff00
# define CHAR_VALUE_MASK				0x000000ff
# define CHAR_SIGN_MASK				0x00000080

typedef struct	s_iterator
{
	va_list		*begin;
	va_list		*current;
}				t_iterator;

typedef enum	e_modifier
{
	kNone = 0,
	kL,
	kH,
	kJ,
	kZ,
	kLL,
	kHH
}				t_modifier;

typedef struct	s_format
{
	char		*format;
	int			precision;
	int			min_size;
	t_modifier	modifier;
	int			sharp;
	int			zero;
	int			minus;
	int			plus;
	int			dollar;
	int			space;
}				t_format;

typedef struct	s_to_print
{
	char		*print;
	t_format	*format;
	int			len;
}				t_to_print;

typedef struct	s_tools
{
	char		*flags;
	void		(*tab_ft[16])(va_list*, t_to_print*);
}				t_tools;

typedef enum	e_error
{
	kSyntax = 0,
	kMalloc,
	kModifier,
	kVar,
	kNull
}				t_error;

int				ft_printf(char *format, ...);
void			ft_d(va_list *ap, t_to_print *print);
void			ft_ld(va_list *ap, t_to_print *print);
void			ft_p(va_list *ap, t_to_print *print);
void			ft_u(va_list *ap, t_to_print *print);
void			ft_lu(va_list *ap, t_to_print *print);
void			ft_c(va_list *ap, t_to_print *print);
void			ft_lc(va_list *ap, t_to_print *print);
void			ft_s(va_list *ap, t_to_print *print);
void			ft_ls(va_list *ap, t_to_print *print);
void			ft_o(va_list *ap, t_to_print *print);
void			ft_lo(va_list *ap, t_to_print *print);
void			ft_p(va_list *ap, t_to_print *print);
void			ft_x(va_list *ap, t_to_print *print);
void			ft_lx(va_list *ap, t_to_print *print);
void			ft_b(va_list *ap, t_to_print *print);
void			ft_prcnt(va_list *ap, t_to_print *print);
void			ft_error(t_error error, const char *fname, const int line);
void			ft_dio(t_to_print *data);
void			ft_dix(t_to_print *data);
void			ft_dilx(t_to_print *data);
void			ft_din(t_to_print *data);
void			ft_dip(t_to_print *data);
int				ft_check_sharp(char *format);
void			ft_check_format_error(char *format);
int				ft_check_dollar(char *format);
void			ft_authorized_char(char *format);
int				ft_check_minus(char *format);
int				ft_check_plus(char *format);
void			ft_check_letter(char *format, int nbc);
int				ft_check_points(char *format);
int				ft_check_zero(t_format *format);
void			ft_fill_format(t_format *format);
int				ft_findflag(const char *s, char c);
int				ft_count_letter(char *format);
int				ft_check_space(char *format);
void			ft_check_format_error(char *format);
int				ft_is_valid_alpha(int c);
t_list			*ft_parse(char *format, t_iterator *it);
void			ft_space(t_to_print *data);
void			ft_plus(t_to_print *data);
void			ft_zero(t_to_print *data, size_t size);
void			ft_min_size(t_to_print *data, size_t size);
void			ft_sharp(t_to_print *data, int fn);
void			ft_precision(t_to_print *data, int size);
void			ft_init_format(t_format **format);
t_tools			*ft_init_tools(void);
t_iterator		*new_arg_iterator(va_list *begin);
int				ft_pourcent(char *format, t_list **lst);
int				ft_basicstring(char *format, t_list **lst);
int				ft_wchar_to_char(wchar_t chr, char *str, int *i);
int				ft_wcslen(wchar_t *ws);
void			trim_zero(char **str);
#endif
