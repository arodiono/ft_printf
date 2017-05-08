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

void	search_type(const char *format, t_node **value)
{
	int		i;
	int		r;
	char	*types;

	types = "sSpdDioOuUxXcCn";
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
	while (r++ <= FNSH)
	{
		i = -1;
		while (length[++i] != '\0')
		{
			if (format[r] == length[i] && format[r + 1] == length[i])
			{
				length[i] == 'h' ? LNGTH = 'H' : LNGTH;
				length[i] == 'l' ? LNGTH = 'Z' : LNGTH;
				return ;
			}
			else if (length[i] == format[r])
			{
				LNGTH = format[r];
				return ;
			}
		}
	}
}

void	search_precision(const char *format, t_node **value, va_list ap)
{
	int		r;

	r = STRT;
	while (r++ <= FNSH)
	{
		if (format[r] == '.')
		{
			PRCSN = 0;
			if (format[++r] == '*')
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
				PRCSN = PRCSN * 10 + format[r++] - '0';
			if (format[r] > '0' && format[r] < '9')
				PRCSN = 0;
			return ;
		}
	}
}

void	search_width(const char *format, t_node **value, va_list ap)
{
	int	r;

	r = STRT;
	while (r <= FNSH)
	{
		if (((format[r] > '0' && format[r] <= '9') || format[r] == '*') \
			&& format[r - 1] != '.')
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
