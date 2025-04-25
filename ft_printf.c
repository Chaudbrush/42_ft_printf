/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:02:34 by vloureir          #+#    #+#             */
/*   Updated: 2025/04/25 09:39:44 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_int(char c)
{
	if (c == 'c' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	ap;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (is_int(format[++i]))
				count += sort_int(va_arg(ap, int), format[i++]);
			else if (format[i] == 's' || format[i] == 'p')
				count += sort_stars(va_arg(ap, void *), format[i++]);
			else
				count += mod_putchar(format[i++]);
		}
		else
			count += mod_putchar(format[i++]);
	}
	va_end(ap);
	return (count);
}
