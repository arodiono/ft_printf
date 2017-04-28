/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 17:05:56 by arodiono          #+#    #+#             */
/*   Updated: 2017/02/16 17:06:02 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define STRT	(*value)->start
# define FNSH	(*value)->finish
# define FLG	(*value)->flag
# define WDTH	(*value)->width
# define PRCSN	(*value)->precision
# define LNGTH	(*value)->length
# define TYPE	(*value)->type
# define INT	(*value)->int_value
# define UINT	(*value)->uint_value
# define STR	(*value)->string
# define CHR	(*value)->charact

# define ZERO	1
# define PLUS	2
# define MINUS	4
# define SPACE	8
# define HASH	16

/*
** DELETE FROM THIS !!!!!!!!!
*/
# define PRINT_STRUCT	printf("\nstart\t%d\n", STRT); \
						printf("finish\t%d\n", FNSH); \
						printf("flag\t%c\n", FLG); \
						printf("width\t%d\n", WDTH); \
						printf("precs\t%d\n", PRCSN); \
						printf("lenght\t%c\n", LNGTH); \
						printf("type\t%c\n", TYPE); \
						printf("int_val\t%lli\n", INT); \
						printf("uint_val\t%lu\n", UINT); \
						printf("string\t%s\n", STR); \
						printf("charact\t%c\n", CHR); \
/*
** DELETE TO THIS !!!!!!!!!
*/

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <wchar.h>

typedef struct	s_node
{
	int			start;
	int			finish;
	char		flag;
	int			width;
	int			precision;
	char		length;
	char		type;
	long long		int_value;
	size_t		uint_value;
	char		*string;
	char		charact;
	size_t		n;

}				t_node;

int		ft_putchar(char c);
int		ft_putstr(char const *s);
int		ft_printf(const char *format, ...);
int		read_or_print(const char *format, t_node **value, va_list ap);
void	fill_struct(const char *format, t_node **value, va_list ap);
void	read_argument(t_node **value, va_list ap, int r);
void	bzero_struct(t_node **value);
void	search_finish(const char *format, t_node **value);
void	search_type(const char *format, t_node **value);
void	search_length(const char *format, t_node **value);
void	search_flag(const char *format, t_node **value);
void	search_width(const char *format, t_node **value, va_list ap);
void	search_precision(const char *format, t_node **value, va_list ap);
intmax_t	get_int(t_node **value, va_list ap);
uintmax_t	get_unsigned(t_node **value, va_list ap);
void	read_str(t_node **value, va_list ap);
void	read_char(t_node **value, va_list ap);
void	format_value(t_node **value);
void	add_prcsn(t_node **value);
void	cut_prcsn(t_node **value);
void	add_width(t_node **value);
void	add_flag_plus(t_node **value);
void	add_flag_space(t_node **value);
void	add_flag_hash(t_node **value);
char	*ft_itoa_base(ssize_t val, int base, t_node **value);
char	*ft_uitoa_base(size_t val, int base, t_node **value);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
void	get_n(va_list ap, int r);
void	format_decimal(t_node **value);
void	format_hexadecimal(t_node **value);
void	format_unsigned(t_node **value);
void	format_octal(t_node **value);
void	format_string(t_node **value);
void	format_char(t_node **value);
void	read_wint(t_node **value, va_list ap);
void	read_wchar(t_node **value, va_list ap);
void	format_pointer(t_node **value);

unsigned long	get_pointer(va_list ap);

#endif
