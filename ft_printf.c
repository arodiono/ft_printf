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
	if (TYPE == 'd' || TYPE == 'i' || TYPE == 'D')
		STR = ft_itoa_base(INT = get_int(&*value, ap), 10, &*value);
	else if (TYPE == 'x' || TYPE == 'X')
		STR = ft_uitoa_base(UINT = get_unsigned(&*value, ap), 16, &*value);
	else if (TYPE == 'u' || TYPE == 'U')
		STR = ft_uitoa_base(UINT = get_unsigned(&*value, ap), 10, &*value);
	else if (TYPE == 'o' || TYPE == 'O')
		STR = ft_uitoa_base(UINT = get_unsigned(&*value, ap), 8, &*value);
	else if (TYPE == 's')
		read_str(&*value, ap);
	else if (TYPE == 'c' && LNGTH != 'l')
		read_char(&*value, ap);
	else if ((TYPE == 'c' && LNGTH == 'l') || TYPE == 'C')
		read_wchar(&*value, ap);
	else if (TYPE == 'p')
	{
		STR = ft_uitoa_base(UINT = get_pointer(ap), 16, &*value);
		FLG += HASH;
	}
}

void	fill_struct(const char *format, t_node **value)
{
	char *s;

	search_finish(format, &*value);
	s = (char *)malloc(sizeof(char));
	s[0] = format[FNSH];
	s[1] = '\0';
	STR = s;
	search_type(format, &*value);
	if (TYPE == 'c' || TYPE == 'C')
		STR = "";
	search_flag(format, &*value);
	search_width(format, &*value);
	search_precision(format, &*value);
	search_length(format, &*value);
}

int	read_or_print(const char *format, t_node **value, va_list ap)
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
			r += 1;
		}
		else if (format[0] == '%' && format[1] == '\0')
			break ;
		else if (format[i] == '%')
		{
			STRT = i;
			fill_struct(format, &*value);
			read_argument(&*value, ap);
			// PRINT_STRUCT
			format_value(&*value);
			// PRINT_STRUCT
			r += ft_putstr(STR);
			if ((TYPE == 'c' || TYPE == 'C') && CHR == 0)
			{
				write(1, "\0", 1);
				r += 1;
			}
			i = FNSH + 1;
			bzero_struct(&*value);
		}
		else
		{
			r += 1;
			ft_putchar(format[i++]);
		}
	}
	return (r);
}

void	bzero_struct(t_node **value)
{
	STRT = 0;
	FNSH = 0;
	FLG = 0;
	WDTH = 0;
	PRCSN = -1;
	LNGTH = 0;
	TYPE = 0;
	INT = 0;
	UINT = 0;
	STR = "";
	(*value)->charact = -1;
}

int		ft_printf(const char *format, ...)
{
	int i;
	va_list	ap;
	t_node	*value;

	value = (t_node *)malloc(sizeof(t_node));
	bzero_struct(&value);
	va_start(ap, format);
	i = read_or_print(format, &value, ap);
	va_end(ap);
	free(value);
	return (i);
}
