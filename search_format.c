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

	types = "sSpdDioOuUxXcC";
	r = STRT;
	while (format[r] != '\0')
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
	while (format[r] != '\0')
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
				FNSH = r;
				return ;
			}
			else if (length[i] == format[r])
			{
				LNGTH = format[r];
				FNSH = r;
				return ;
			}
			i++;
		}
		r++;
	}
}

void	search_precision(const char *format, t_node **value)
{
	int		r;

	r = STRT;
	while (format[r] != '\0')
	{
		if (format[r] == '.')
		{
			r++;
			PRCSN = 0;
			while (format[r] >= '0' && format[r] <= '9')
			{
				PRCSN = PRCSN * 10 + format[r] - '0';
				r++;
			}
			FNSH = r;
			return ;
		}
		r++;
	}
}

void	search_width(const char *format, t_node **value)
{
	int		r;

	r = STRT;
	while (format[r] != '\0')
	{
		if (format[r] >= '0' && format[r] <= '9' && format[r - 1] != '.')
		{
			WDTH = 0;
			while (format[r] >= '0' && format[r] <= '9')
			{
				WDTH = WDTH * 10 + format[r] - '0';
				r++;
			}
			FNSH = r;
			return ;
		}
		r++;
	}
}

void	search_flag(const char *format, t_node **value)
{
	int		i;
	int		r;
	char	*flags;

	flags = "-+ #0";
	r = STRT;
	while (format[r] != '\0')
	{
		i = 0;
		while (flags[i] != '\0')
		{
			if (flags[i] == format[r] && format[r - 1] != '.')
			{
				FLG = format[r];
				FNSH = r;
				return ;
			}
			i++;
		}
		r++;
	}
}
