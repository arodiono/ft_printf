/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_numbs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 17:47:17 by arodiono          #+#    #+#             */
/*   Updated: 2017/05/08 17:47:18 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_pointer(t_node **value)
{
	add_prcsn(&*value);
	(FLG & ZERO) == ZERO ? add_width(&*value) : (STR = ft_strjoin("0x", STR));
	(FLG & ZERO) == ZERO ? (STR = ft_strjoin("0x", STR)) : add_width(&*value);
}

void	format_decimal(t_node **value)
{
	add_prcsn(&*value);
	(FLG & ZERO) == ZERO ? add_width(&*value) : ZERO;
	if ((FLG & PLUS) == PLUS && INT >= 0)
		add_flag_plus(&*value);
	if (INT < 0 && INT >= -9223372036854775807)
		STR = ft_strjoin("-", STR);
	if (INT < 0)
		INT *= -1;
	if ((FLG & SPACE) == SPACE && INT >= 0 && (FLG & PLUS) == 0)
		add_flag_space(&*value);
	(FLG & ZERO) != ZERO ? add_width(&*value) : ZERO;
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
