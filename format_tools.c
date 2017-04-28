/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 01:05:38 by arodiono          #+#    #+#             */
/*   Updated: 2017/04/29 01:05:40 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_prcsn(t_node **value)
{
	int		i;
	char	*s;
	char	c;

	i = 0;
	c = '0';
	s = (char *)malloc(sizeof(char) * (PRCSN + ft_strlen(STR)) + 1);
	if (PRCSN == 0 && INT == 0 && UINT == 0 && TYPE != 0)
		STR = "";
	if (TYPE != 'c' && TYPE != 'C' && STR[0] != '%')
		while (i < (PRCSN - ft_strlen(STR)))
			s[i++] = c;
	s[i] = '\0';
	STR = ft_strjoin(s, STR);
}

void	cut_prcsn(t_node **value)
{
	int		i;
	char	*s;

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
	char	*s;
	int		i;
	int		f;
	char	c;

	i = 0;
	f = WDTH - ft_strlen(STR);
	if (((FLG & PLUS) == PLUS && (FLG & ZERO) == ZERO) || INT < 0 || CHR == 0 \
		|| ((FLG & SPACE) == SPACE && WDTH > 0 && INT == 0))
		f -= 1;
	if ((FLG & ZERO) == ZERO && (FLG & HASH) == HASH && (TYPE == 'x' || \
		TYPE == 'X' || TYPE == 'p') && WDTH > 0)
		f -= 2;
	c = ' ';
	if (((FLG & ZERO) == ZERO && (FLG & MINUS) != MINUS) && PRCSN <= 0)
		c = '0';
	s = (char *)malloc(sizeof(char) * (WDTH + ft_strlen(STR)) + 1);
	if (WDTH > ft_strlen(STR))
	{
		while (i < f)
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
	else if (TYPE == 's' || TYPE == 'S')
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
