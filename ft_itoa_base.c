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

char	*ft_itoa_base(void *v, int base, t_node **value)
{
	int i;
	char *r;
	char *num;
	long long int tmp;
	long long int val;

	val = (long long int)v;
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

char	*ft_uitoa_base(void *v, int base, t_node **value)
{
	int i;
	char *r;
	char *num;
	unsigned long long int tmp;
	unsigned long long int val;

	val = (unsigned long long int)v;
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
