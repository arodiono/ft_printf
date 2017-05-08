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
