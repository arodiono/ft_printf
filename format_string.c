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

void	add_flags(t_node **value)
{
	int i;

	i = 0;
	if (FLG == ' ')
		STR = ft_strjoin(" ", STR);
}

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
	free(s);
}

void	add_width(t_node **value)
{
	char *s;
	int i;
	char c;

	i = 0;
	c = ' ';
	if (FLG == '0'  && PRCSN < 0 && (TYPE == 'd' || TYPE == 'i' || TYPE == 'x' \
	|| TYPE == 'X' || TYPE == 'u' || TYPE == 'U'|| TYPE == 'o' || TYPE == 'U'))
		c = '0';
	s = (char *)malloc(sizeof(char) * (WDTH + ft_strlen(STR)) + 1);
	if (WDTH > ft_strlen(STR))
	{
		while(i < (WDTH - ft_strlen(STR)))
			s[i++] = c;
		s[i] = '\0';
		if (FLG == '-')
			STR = ft_strjoin(STR, s);
		else
			STR = ft_strjoin(s, STR);
	}
}

void	format_string(t_node **value)
{
	add_flags(&*value);
	if (TYPE == 's' || TYPE == 'S')
	{
		if ((PRCSN > 0) && (PRCSN < ft_strlen(STR)))
			cut_prcsn(&*value);
		else if (PRCSN > ft_strlen(STR))
			PRCSN = ft_strlen(STR);
		else if (PRCSN == 0)
			STR = "";
	}
	else
		add_prcsn(&*value);
	add_width(&*value);
}
