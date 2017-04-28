/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_and_unsigned.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 00:55:33 by arodiono          #+#    #+#             */
/*   Updated: 2017/04/29 00:55:34 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	get_int(t_node **value, va_list ap)
{
	if (LNGTH == 'l')
		return ((long int)va_arg(ap, long int));
	else if (TYPE == 'D')
		return ((long long int)va_arg(ap, long long int));
	else if (LNGTH == 'Z')
		return (va_arg(ap, long long int));
	else if (LNGTH == 'h')
		return ((short int)va_arg(ap, int));
	else if (LNGTH == 'H')
		return ((signed char)va_arg(ap, int));
	else if (LNGTH == 'j')
		return (va_arg(ap, intmax_t));
	else if (LNGTH == 'z')
		return ((intmax_t)va_arg(ap, size_t));
	else
		return ((intmax_t)va_arg(ap, int));
}

uintmax_t	get_unsigned(t_node **value, va_list ap)
{
	if (LNGTH == 0 && TYPE != 'U' && TYPE != 'O')
		return (va_arg(ap, unsigned int));
	else if (LNGTH == 'l')
		return (va_arg(ap, unsigned long int));
	else if (LNGTH == 'Z')
		return (va_arg(ap, unsigned long long int));
	else if (LNGTH == 'h' && (TYPE == 'o' || TYPE == 'u' \
		|| TYPE == 'x' || TYPE == 'X'))
		return ((unsigned short)va_arg(ap, unsigned int));
	else if (LNGTH == 'h')
		return (va_arg(ap, unsigned long int));
	else if (LNGTH == 'H' && TYPE != 'U' && TYPE != 'O')
		return ((unsigned char)va_arg(ap, unsigned int));
	else if (LNGTH == 'H' && TYPE == 'O')
		return ((unsigned int)va_arg(ap, unsigned int));
	else if (LNGTH == 'j')
		return (va_arg(ap, uintmax_t));
	else if (LNGTH == 'z')
		return (va_arg(ap, size_t));
	else
		return (va_arg(ap, unsigned long int));
}

uintmax_t	get_pointer(va_list ap)
{
	return (va_arg(ap, unsigned long));
}

void		get_n(va_list ap, int r)
{
	int *n;

	n = (va_arg(ap, int*));
	*n = r;
}
