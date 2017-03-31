/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_agruments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 21:09:42 by arodiono          #+#    #+#             */
/*   Updated: 2017/03/23 21:09:44 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	read_di(t_node **value, va_list ap)
{
	intmax_t	im;

	im = 0;
	if (LNGTH == 0)
		im = va_arg(ap, int);
	else if (LNGTH == 'l')
		im = va_arg(ap, long int);
	else if (LNGTH == 'Z')
		im = va_arg(ap, long long int);
	else if (LNGTH == 'h')
		im = va_arg(ap, int);
	else if (LNGTH == 'H')
		im = va_arg(ap, int);
	else if (LNGTH == 'j')
		im = va_arg(ap, intmax_t);
	else if (LNGTH == 'z')
		im = va_arg(ap, size_t);
	STR = ft_itoa_base((void *)im, 10, &*value);
	if (im > 0 && FLG == '+')
		STR = ft_strjoin("+", STR);
	if (im < 0 && FLG == ' ')
		FLG = 0;
}
void	read_xx(t_node **value, va_list ap)
{
	unsigned long long int um;

	um = 0;
	if (LNGTH == 0)
		um = va_arg(ap, unsigned int);
	else if (LNGTH == 'l')
		um = va_arg(ap, unsigned long int);
	else if (LNGTH == 'Z')
		um = va_arg(ap, unsigned long long int);
	else if (LNGTH == 'h')
		um = va_arg(ap, unsigned int);
	else if (LNGTH == 'H')
		um = va_arg(ap, unsigned int);
	else if (LNGTH == 'j')
		um = va_arg(ap, uintmax_t);
	else if (LNGTH == 'z')
		um = va_arg(ap, size_t);
	if (TYPE == 'x' || TYPE == 'X')
		STR = ft_uitoa_base((void *)um, 16, &*value);
	else if (TYPE == 'o' || TYPE == 'O')
		STR = ft_uitoa_base((void *)um, 8, &*value);
	else if (TYPE == 'u' || TYPE == 'U')
		STR = ft_uitoa_base((void *)um, 10, &*value);
	if (FLG == '#')
		STR = ft_strjoin((TYPE == 'X') ? "0X" : "0x", STR);
}
// void	read_ou(t_node **value, va_list ap)
// {
//
// }
void	read_str(t_node **value, va_list ap)
{
	char *str;
	wchar_t *strw;

	str = "";
	if (LNGTH == 0)
		str = va_arg(ap, char*);
	else if (LNGTH == 'l')
		strw = va_arg(ap, wchar_t*);
	STR = str;
}
void	read_char(t_node **value, va_list ap)
{
	char c;
	char *s;

	c = va_arg(ap, int);
	s = (char *)malloc(sizeof(char));
	s[0] = c;
	STR = s;
}
