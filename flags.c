/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 20:36:59 by arodiono          #+#    #+#             */
/*   Updated: 2017/04/06 20:38:14 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_flag_plus(t_node **value)
{
	if (TYPE == 'd' || TYPE == 'D' || TYPE == 'i')
	{
		if (INT >= 0)
			STR = ft_strjoin("+", STR);
	}
}

void	add_flag_space(t_node **value)
{
	if (TYPE == 'd' || TYPE == 'D' || TYPE == 'i')
		if (STR[0] != '+' && STR[0] != '-')
			STR = ft_strjoin(" ", STR);
}

void	add_flag_hash(t_node **value)
{
	if (TYPE == 'x' || TYPE == 'X')
		STR = ft_strjoin((TYPE == 'X') ? "0X" : "0x", STR);
	else if ((TYPE == 'o' || TYPE == 'O') && STR[0] != '0')
		STR = ft_strjoin("0", STR);
}
