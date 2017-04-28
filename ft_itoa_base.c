/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 20:56:33 by arodiono          #+#    #+#             */
/*   Updated: 2017/03/24 20:56:35 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(intmax_t val, int base, t_node **value)
{
	int				i;
	char			*r;
	char			*num;
	long long int	tmp;

	val = (val < 0) ? val *= -1 : val;
	i = (val < 0 && base == 10) ? 2 : 1;
	num = (TYPE == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
	tmp = val;
	while (tmp /= base)
		i++;
	r = (char *)malloc(sizeof(char) * i + 1);
	if (val == 0)
		r[0] = '0';
	if (val < 0 && base == 10)
		r[0] = '-';
	r[i] = '\0';
	while (val)
	{
		r[--i] = num[(val < 0) ? -(val % base) : (val % base)];
		val /= base;
	}
	return (r);
}

char	*ft_uitoa_base(uintmax_t val, int base, t_node **value)
{
	int						i;
	char					*r;
	char					*num;
	unsigned long long int	tmp;

	i = 1;
	num = (TYPE == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
	tmp = val;
	while (tmp /= base)
		i++;
	r = (char *)malloc(sizeof(char) * i + 1);
	if (val == 0)
		r[0] = '0';
	r[i] = '\0';
	while (val)
	{
		r[--i] = num[val % base];
		val /= base;
	}
	return (r);
}
