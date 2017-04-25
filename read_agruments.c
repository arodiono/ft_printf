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

intmax_t	get_int(t_node **value, va_list ap)
{
	if (LNGTH == 'l')
		return((long int)va_arg(ap, long int));
	else if (TYPE == 'D')
		return((long long int)va_arg(ap, long long int));
	else if (LNGTH == 'Z')
		return(va_arg(ap, long long int));
	else if (LNGTH == 'h')
		return((short int)va_arg(ap, int));
	else if (LNGTH == 'H')
		return((signed char)va_arg(ap, int));
	else if (LNGTH == 'j')
		return(va_arg(ap, intmax_t));
	else if (LNGTH == 'z')
		return((intmax_t)va_arg(ap, size_t));
	else
		return((intmax_t)va_arg(ap, int));
}
uintmax_t	get_unsigned(t_node **value, va_list ap)
{
	if (LNGTH == 0 && TYPE != 'U' && TYPE != 'O')
		return(va_arg(ap, unsigned int));
	else if (LNGTH == 'l')
		return(va_arg(ap, unsigned long int));
	else if (LNGTH == 'Z')
		return(va_arg(ap, unsigned long long int));
	else if (LNGTH == 'h' && (TYPE == 'o' || TYPE == 'u' || TYPE == 'x' || TYPE == 'X'))
		return((unsigned short)va_arg(ap, unsigned int));
	// else if (LNGTH == 'h' && TYPE != 'U')
	// 	return(va_arg(ap, unsigned int));
	else if (LNGTH == 'h')
		return(va_arg(ap, unsigned long int));
	else if (LNGTH == 'H' && TYPE != 'U' && TYPE != 'O')
		return((unsigned char)va_arg(ap, unsigned int));
	else if (LNGTH == 'H' && TYPE == 'O')
		return((unsigned int)va_arg(ap, unsigned int));
	else if (LNGTH == 'j')
		return(va_arg(ap, uintmax_t));
	else if (LNGTH == 'z')
		return(va_arg(ap, size_t));
	else
		return(va_arg(ap, unsigned long int));
}

unsigned long	get_pointer(va_list ap)
{
	return(va_arg(ap, unsigned long));
}

void	read_str(t_node **value, va_list ap)
{
	char *str;
	wchar_t *s;

	str = "";
	if (TYPE == 'S' || LNGTH == 'l')
	{
		s = va_arg(ap, wchar_t*);
	}
	else
	{
		if (LNGTH == 0)
			str = va_arg(ap, char*);
		if (str == NULL)
			STR = NULL;
		else
			STR = str;
	}
}
void	read_char(t_node **value, va_list ap)
{
	char c;
	char *s;

	c = va_arg(ap, int);
	if (c == '\0')
		CHR = c;
	else
	{
		s = (char *)malloc(sizeof(char) + 1);
		s[0] = c;
		STR = s;
	}
}

int check_size(unsigned int v)
{
	int i  = 0;
	while (v > 0)
	{
		i++;
		v /=2;
	}
	return i;
}

void	two_wchar(t_node **value, unsigned int v)
{
	char			*s;
	unsigned int	mask;

	mask = 49280;
	s = (char *)malloc(sizeof(char) + 2);
	s[0] = (mask >> 8) | (((v >> 6) << 27) >> 27);
	s[1] = ((mask << 24) >> 24) | ((v << 26) >> 26);
	STR = s;
}

void	three_wchar(t_node **value, unsigned int v)
{
	char			*s;
	unsigned int	mask;

	mask = 14712960;
	s = (char *)malloc(sizeof(char) + 3);
	s[0] = (mask >> 16) | (((v >> 12) << 28) >> 28);
	s[1] = ((mask << 16) >> 24) | (((v >> 6) << 26) >> 26);
	s[2] = ((mask << 24) >> 24) | ((v << 26) >> 26);
	STR = s;
}

void	four_wchar(t_node **value, unsigned int v)
{
	char			*s;
	unsigned int	mask;

	mask = 4034953344;
	s = (char *)malloc(sizeof(char) + 4);
	s[0] = (mask >> 24) | (((v >> 18) << 29) >> 29);
	s[1] = ((mask << 8) >> 24) | (((v >> 12) << 26) >> 26);
	s[2] = ((mask << 16) >> 24) | (((v >> 6) << 26) >> 26);
	s[3] = ((mask << 24) >> 24) | ((v << 26) >> 26);
	STR = s;
}

void	read_wchar(t_node **value, va_list ap)
{
	char *s;
	wchar_t val;
	unsigned char octet;
	unsigned int v;
	int size;

	val = va_arg(ap, wchar_t);
	if (val == 0)
		CHR = 0;
	else
	{
		v = val;
		size = check_size((unsigned int)val);
		if (size <= 7)
		{
			octet = val;
			s = (char *)malloc(sizeof(char) + 1);
			s[0] = octet;
			STR = s;
		}
		else  if (size <= 11)
			two_wchar(&*value, v);
		else  if (size <= 16)
			three_wchar(&*value, v);
		else
			four_wchar(&*value, v);
	}
}
