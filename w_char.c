/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_char.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 00:50:07 by arodiono          #+#    #+#             */
/*   Updated: 2017/04/29 00:50:09 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_size(unsigned int v)
{
	int i;

	i = 0;
	while (v > 0)
	{
		i++;
		v /= 2;
	}
	return (i);
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

void	process_wchar(wint_t val, t_node **value)
{
	char			*s;
	unsigned char	octet;
	unsigned int	v;
	int				size;

	v = val;
	size = check_size((unsigned int)val);
	if (size <= 7)
	{
		octet = val;
		s = (char *)malloc(sizeof(char) + 1);
		s[0] = octet;
		STR = s;
	}
	else if (size <= 11)
		two_wchar(&*value, v);
	else if (size <= 16)
		three_wchar(&*value, v);
	else
		four_wchar(&*value, v);
}
