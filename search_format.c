/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:54:15 by arodiono          #+#    #+#             */
/*   Updated: 2017/03/23 14:54:17 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	search_finish(const char *format, t_node **value)
{
	char *s;
	int x;
	int i;

	s = "sSpdDioOuUxXcChljz-+ #0123456789.*";
	x = STRT + 1;
	i = 0;
	while (format[x] != '\0')
	{
		while (s[i] != '\0')
		{
			if (format[x] != s[i])
				i++;
			else if (format[x] == s[i])
			{
				x++;
				i = 0;
			}
		}
		if (s[i] == '\0')
		{
			FNSH = x;
			return ;
		}
	}
}

void	search_type(const char *format, t_node **value)
{
	int		i;
	int		r;
	char	*types;

	types = "sSpdDioOuUxXcC";
	r = STRT;
	while (r < FNSH)
	{
		i = 0;
		while (types[i] != '\0')
		{
			if (types[i] == format[r])
			{
				TYPE = format[r];
				FNSH = r;
				return ;
			}
			i++;
		}
		r++;
	}
}

void	search_length(const char *format, t_node **value)
{
	int		i;
	int		r;
	char	*length;

	length = "hljz";
	r = STRT;
	while (r <= FNSH)
	{
		i = 0;
		while (length[i] != '\0')
		{
			if (format[r] == length[i] && format[r + 1] == length[i])
			{
				if (length[i] == 'h')
					LNGTH = 'H';
				else if (length[i] == 'l')
					LNGTH = 'Z';
				return ;
			}
			else if (length[i] == format[r])
			{
				LNGTH = format[r];
				return ;
			}
			i++;
		}
		r++;
	}
}

void	search_precision(const char *format, t_node **value, va_list ap)
{
	int		r;

	r = STRT;
	while (r <= FNSH)
	{
		if (format[r] == '.')
		{
			r++;
			PRCSN = 0;
			if (format[r] == '*')
			{
				if ((PRCSN = va_arg(ap, int)) < 0)
				{
					PRCSN = -1;
					if ((FLG & MINUS) != MINUS)
						FLG += MINUS;
				}
				return ;
			}
			while (format[r] >= '0' && format[r] <= '9')
			{
				PRCSN = PRCSN * 10 + format[r] - '0';
				r++;
			}
			if (format[r] > '0' && format[r] < '9')
				PRCSN = 0;
			return ;
		}
		r++;
	}
}

void	search_width(const char *format, t_node **value, va_list ap)
{
	int	r;

	r = STRT;
	while (r <= FNSH)
	{
		if (((format[r] > '0' && format[r] <= '9') || format[r] == '*') && format[r - 1] != '.')
		{
			WDTH = 0;
			while (format[r] >= '0' && format[r] <= '9')
			{
				WDTH = WDTH * 10 + format[r] - '0';
				r++;
			}
			if (format[r] == '*' && format[r - 1] != '.')
			{
				if ((WDTH = va_arg(ap, int)) < 0 && (FLG & MINUS) != MINUS)
					FLG += MINUS;
				WDTH < 0 ? WDTH *= -1 : WDTH;
				return ;
			}
			return ;
		}
		r++;
	}
}

void	print_bits(unsigned char octet)
{
	unsigned char	i;
	int 			n;

	n = 8;
	i = 128;
	while (n--)
	{
		if (octet >= i)
		{
			write(1, "1", 1);
			octet -= i;
		}
		else
			write(1, "0", 1);
		i /= 2;
	}
}

void	set_bits(t_node **value, char c)
{
	if (c == '0' && ((FLG & ZERO) != ZERO))
		FLG += ZERO;
	else if (c == '+' && ((FLG & PLUS) != PLUS))
		FLG += PLUS;
	else if (c == '-' && ((FLG & MINUS) != MINUS))
		FLG += MINUS;
	else if (c == '#' && ((FLG & HASH) != HASH))
		FLG += HASH;
	else if (c == ' ' && ((FLG & SPACE) != SPACE))
		FLG += SPACE;
}

void	search_flag(const char *frm, t_node **value)
{
	int		i;
	int		r;
	char	*flags;

	flags = "-+ #0";
	r = STRT;
	while (r < FNSH)
	{
		i = 0;
		while (flags[i] != '\0')
		{
			if (flags[i] == frm[r] && frm[r - 1] != '.')
			{
				if ((frm[r - 1] >= 48 && frm[r - 1] <= 57) && frm[r] == '0')
					FLG = FLG;
				else
					set_bits(&*value, flags[i]);
			}
			i++;
		}
		r++;
	}
}
