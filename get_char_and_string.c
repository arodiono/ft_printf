/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char_and_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 00:54:17 by arodiono          #+#    #+#             */
/*   Updated: 2017/04/29 00:54:19 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_string(t_node **value, va_list ap)
{
	char *str;

	str = "";
	if (LNGTH == 0)
		str = va_arg(ap, char*);
	if (str == NULL)
		STR = NULL;
	else
		STR = str;
}

void	get_char(t_node **value, va_list ap)
{
	char c;

	c = va_arg(ap, int);
	if (c == '\0')
		CHR = c;
	else
	{
		STR = (char *)malloc(sizeof(char) + 1);
		STR[0] = c;
	}
}

void	get_wchar(t_node **value, va_list ap)
{
	wint_t val;

	val = va_arg(ap, wint_t);
	if (val == 0)
		CHR = 0;
	else
		process_wchar(val, &*value);
}

void	get_wchar_string(t_node **value, va_list ap)
{
	wchar_t	*str;
	char	*res;
	wint_t	c;

	res = "";
	str = va_arg(ap, wchar_t*);
	if (str == NULL)
		res = NULL;
	else
		while (*str)
		{
			c = (wint_t)*str;
			process_wchar(c, &*value);
			res = ft_strjoin(res, STR);
			str++;
		}
	STR = res;
}
