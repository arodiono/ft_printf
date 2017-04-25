/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 17:22:25 by arodiono          #+#    #+#             */
/*   Updated: 2017/03/25 17:22:26 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Function that add a chars to string if the precision is bigger
** than the length of the string
*/

void	add_prcsn(t_node **value)
{
	int i;
	char *s;
	char c;
	i = 0;
	c = '0';
	s = (char *)malloc(sizeof(char) * (PRCSN + ft_strlen(STR)) + 1);
	if (PRCSN == 0 && INT == 0 && UINT == 0 && TYPE != 0)
		STR = "";
	if (TYPE != 'c' && TYPE != 'C')
		while (i < (PRCSN - ft_strlen(STR)))
			s[i++] = c;
	s[i] = '\0';
	STR = ft_strjoin(s, STR);
}

/*
** Function that cuts a string if the precision is less
** than the length of the string
*/

void	cut_prcsn(t_node **value)
{
	int i;
	char *s;

	i = 0;
	s = (char *)malloc(sizeof(char) * PRCSN + 1);
	while (i < PRCSN)
	{
		s[i] = STR[i];
		i++;
	}
	s[i] = '\0';
	STR = s;
}

void	add_width(t_node **value)
{
	char *s;
	int i;
	int f;
	char c;

	i = 0;
	f = WDTH - ft_strlen(STR);
	if (((FLG & PLUS) == PLUS && (FLG & ZERO) == ZERO) || INT < 0 || CHR == 0 || ((FLG & SPACE) == SPACE && WDTH > 0 && INT == 0))
		f -= 1;
	if ((FLG & ZERO) == ZERO && (FLG & HASH) == HASH && (TYPE == 'x' || TYPE == 'X' || TYPE == 'p') && WDTH > 0)
		f -= 2;
	c = ' ';
	if (((FLG & ZERO) == ZERO && (FLG & MINUS) != MINUS) && PRCSN <= 0)
		c = '0';
	s = (char *)malloc(sizeof(char) * (WDTH + ft_strlen(STR)) + 1);
	if (WDTH > ft_strlen(STR))
	{
		while(i < f)
			s[i++] = c;
		s[i] = '\0';
		STR = (FLG & MINUS) == MINUS ? ft_strjoin(STR, s) : ft_strjoin(s, STR);
	}
}

void	format_value(t_node **value)
{
	if (TYPE == 'd' || TYPE == 'i' || TYPE == 'D')
		format_decimal(&*value);
	else if (TYPE == 'x' || TYPE == 'X')
		format_hexadecimal(&*value);
	else if (TYPE == 'u' || TYPE == 'U')
		format_unsigned(&*value);
	else if (TYPE == 'o' || TYPE == 'O')
		format_octal(&*value);
	else if (TYPE == 's')
		format_string(&*value);
	else if (TYPE == 'c')
		format_char(&*value);
	else if (TYPE == 'p')
		format_pointer(&*value);
	else
	{
		add_prcsn(&*value);
		add_width(&*value);
	}
}

void	format_decimal(t_node **value)
{
	if ((FLG & ZERO) == ZERO)
	{
		add_prcsn(&*value);
		add_width(&*value);
		if ((FLG & PLUS) == PLUS && INT >= 0)
			add_flag_plus(&*value);
		if (INT < 0  && INT >= -9223372036854775807)
			STR = ft_strjoin("-", STR);
		if (INT < 0)
			INT *= -1;
		if ((FLG & SPACE) == SPACE && INT >= 0 && (FLG & PLUS) == 0)
			add_flag_space(&*value);
	}
	else
	{
		add_prcsn(&*value);
		if ((FLG & PLUS) == PLUS && INT >= 0)
			add_flag_plus(&*value);
		if (INT < 0 && INT >= -9223372036854775807)
			STR = ft_strjoin("-", STR);
		if (INT < 0)
			INT *= -1;
		if ((FLG & SPACE) == SPACE && INT >= 0 && (FLG & PLUS) == 0)
			add_flag_space(&*value);
		add_width(&*value);
	}
}

void	format_hexadecimal(t_node **value)
{
	add_prcsn(&*value);
	if ((FLG & ZERO) == ZERO)
	{
		add_width(&*value);
		if ((FLG & HASH) == HASH && UINT > 0)
			add_flag_hash(&*value);
	}
	else
	{
		if ((FLG & HASH) == HASH && UINT > 0)
			add_flag_hash(&*value);
		add_width(&*value);
	}
}

void	format_unsigned(t_node **value)
{
	add_prcsn(&*value);
	add_width(&*value);
}

void	format_octal(t_node **value)
{
	add_prcsn(&*value);
	if ((FLG & ZERO) == ZERO)
	{
		add_width(&*value);
		if ((FLG & HASH) == HASH)
			add_flag_hash(&*value);
	}
	else
	{
		if ((FLG & HASH) == HASH)
			add_flag_hash(&*value);
		add_width(&*value);
	}
}

void	format_string(t_node **value)
{
	if (STR == NULL)
		STR = "(null)";
	if ((PRCSN > 0) && (PRCSN < ft_strlen(STR)))
		cut_prcsn(&*value);
	else if (PRCSN > ft_strlen(STR))
		PRCSN = ft_strlen(STR);
	else if (PRCSN == 0)
		STR = "";
	add_width(&*value);
}

void	format_char(t_node **value)
{
	add_width(&*value);
}

void	format_pointer(t_node **value)
{
	add_prcsn(&*value);
	(FLG & ZERO) == ZERO ? add_width(&*value) : (STR = ft_strjoin("0x", STR));
	(FLG & ZERO) == ZERO ? (STR = ft_strjoin("0x", STR)) : add_width(&*value);
}
