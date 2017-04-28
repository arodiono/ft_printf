/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 00:25:05 by arodiono          #+#    #+#             */
/*   Updated: 2017/04/29 00:25:06 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	search_finish(const char *format, t_node **value)
{
	char	*s;
	int		x;
	int		i;

	s = "sSpdDioOuUxXcChljz-+ #0123456789.*n";
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
