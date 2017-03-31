/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 17:05:41 by arodiono          #+#    #+#             */
/*   Updated: 2017/02/16 17:05:43 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	read_argument(t_node **value, va_list ap)
{
	if (TYPE == 'd' || TYPE == 'D' || TYPE == 'i')
		read_di(&*value, ap);
	else if (TYPE == 'x' || TYPE == 'X' || TYPE == 'u' || TYPE == 'U' \
			|| TYPE == 'o' || TYPE == 'O')
		read_xx(&*value, ap);
	// else if (TYPE == 'u' || TYPE == 'o')
	// 	read_unsig(&*value, ap);
	else if (TYPE == 's' || TYPE == 'S')
		read_str(&*value, ap);
	else if (TYPE == 'c' || TYPE == 'c')
		read_char(&*value, ap);
}

void	fill_struct(const char *format, t_node **value)
{
	char *s;

	s = (char *)malloc(sizeof(char));
	search_type(format, &*value);
	search_flag(format, &*value);
	search_width(format, &*value);
	search_precision(format, &*value);
	search_length(format, &*value);
	if (TYPE == '0')
	{
		s[0] = format[FNSH];
		STR = s;
	}
}

int	read_format(const char *format, t_node **value, va_list ap)
{
	int i;
	int r;

	i = 0;
	r = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			ft_putchar('%');
			i += 2;
			r++;
		}
		else if (format[i] == '%')
		{
			STRT = i;
			fill_struct(format, &*value);
			// PRINT_STRUCT
			read_argument(&*value, ap);
			format_string(&*value);
			ft_putstr(STR);
			r += ft_strlen(STR);
			i = FNSH + 1;
			bzero_struct(&*value);
		}
		else
		{
			ft_putchar(format[i]);
			r++;
			i++;
		}
	}
	return (r);
}

void bzero_struct(t_node **value)
{
	STRT = 0;
	FNSH = 0;
	FLG = 0;
	WDTH = 0;
	PRCSN = -1;
	LNGTH = 0;
	TYPE = '0';
	STR = "";
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_node *value;
	int i;

	value = (t_node *)malloc(sizeof(t_node));
	bzero_struct(&value);
	va_start(ap, format);
	i = read_format(format, &value, ap);
	va_end (ap);
	free(value);
	return (i);
}
