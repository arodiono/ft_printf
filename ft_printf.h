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
# define STR	(*value)->string

/*
** DELETE FROM THIS !!!!!!!!!
*/
# define PRINT_STRUCT	printf("\nstart\t%d\n", STRT); \
						printf("finish\t%d\n", FNSH); \
						printf("flag\t%c\n", FLG); \
						printf("width\t%d\n", WDTH); \
						printf("precs\t%d\n", PRCSN); \
						printf("lenght\t%d\n", LNGTH); \
						printf("type\t%c\n", TYPE); \
						printf("string\t%s\n", STR); \
/*
** DELETE TO THIS !!!!!!!!!
*/

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_node
{
	int			start;
	int			finish;
	char		flag;
	int			width;
	int			precision;
	char		length;
	char		type;
	char		*string;
}				t_node;

void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putnbr(int n);

int		ft_printf(const char *format, ...);
int		read_format(const char *format, t_node **value, va_list ap);
void	fill_struct(const char *format, t_node **value);
void	read_argument(t_node **value, va_list ap);
void	bzero_struct(t_node **value);

void	search_type(const char *format, t_node **value);
void	search_length(const char *format, t_node **value);
void	search_flag(const char *format, t_node **value);
void	search_width(const char *format, t_node **value);
void	search_precision(const char *format, t_node **value);

void	read_di(t_node **value, va_list ap);
void	read_xx(t_node **value, va_list ap);
void	read_ou(t_node **value, va_list ap);
void	read_str(t_node **value, va_list ap);
void	read_char(t_node **value, va_list ap);

void	format_string(t_node **value);
void	add_flags(t_node **value);
void	add_prcsn(t_node **value);
void	cut_prcsn(t_node **value);
void	add_width(t_node **value);


char	*ft_itoa_base(void *v, int base, t_node **value);
char	*ft_uitoa_base(void *v, int base, t_node **value);

char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);


#endif
