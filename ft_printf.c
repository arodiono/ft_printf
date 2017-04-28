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

void	read_argument(t_node **value, va_list ap, int r)
{
	if (TYPE == 'd' || TYPE == 'i' || TYPE == 'D')
		STR = ft_itoa_base(INT = get_int(&*value, ap), 10, &*value);
	else if (TYPE == 'x' || TYPE == 'X')
		STR = ft_uitoa_base(UINT = get_unsigned(&*value, ap), 16, &*value);
	else if (TYPE == 'u' || TYPE == 'U')
		STR = ft_uitoa_base(UINT = get_unsigned(&*value, ap), 10, &*value);
	else if (TYPE == 'o' || TYPE == 'O')
		STR = ft_uitoa_base(UINT = get_unsigned(&*value, ap), 8, &*value);
	else if (TYPE == 's' && LNGTH != 'l')
		get_string(&*value, ap);
	else if ((TYPE == 's' && LNGTH == 'l') || TYPE == 'S')
		get_wchar_string(&*value, ap);
	else if (TYPE == 'c' && LNGTH != 'l')
		get_char(&*value, ap);
	else if ((TYPE == 'c' && LNGTH == 'l') || TYPE == 'C')
		get_wchar(&*value, ap);
	else if (TYPE == 'p')
	{
		STR = ft_uitoa_base(UINT = get_pointer(ap), 16, &*value);
		FLG += HASH;
	}
	else if (TYPE == 'n')
		get_n(ap, r);
}

void	fill_struct(const char *format, t_node **value, va_list ap)
{
	search_finish(format, &*value);
	STR = (char *)malloc(sizeof(char));
	STR[0] = format[FNSH];
	STR[1] = '\0';
	search_type(format, &*value);
	if (TYPE == 'c' || TYPE == 'C')
		STR = "";
	search_flag(format, &*value);
	search_width(format, &*value, ap);
	search_precision(format, &*value, ap);
	search_length(format, &*value);
}

int		read_form(const char *format, t_node **value, va_list ap, int r)
{
	fill_struct(format, &*value, ap);
	read_argument(&*value, ap, r);
	format_value(&*value);
	if (TYPE != 'n')
		r = ft_putstr(STR);
	if ((TYPE == 'c' || TYPE == 'C') && CHR == 0)
		r += ft_putchar('\0');
	return (r);
}

int		read_or_print(const char *format, t_node **value, va_list ap)
{
	int i;
	int r;

	i = 0;
	r = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			r += ft_putchar('%');
			i += 2;
		}
		else if (format[0] == '%' && format[1] == '\0')
			break ;
		else if (format[i] == '%')
		{
			STRT = i;
			r += read_form(format, &*value, ap, r);
			i = FNSH + 1;
			bzero_struct(&*value);
		}
		else
			r += ft_putchar(format[i++]);
	}
	return (r);
}

int		ft_printf(const char *format, ...)
{
	int		i;
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
