/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:23:20 by vloureir          #+#    #+#             */
/*   Updated: 2025/03/13 16:36:04 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_int(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == 'c')
		return (1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = -1;
	count = 0;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			if (is_int(format[i]))
				count += sort_int(va_arg(ap, int), format[i]);
			else if (format[i] == 's' || format[i] == 'p')
				count += sort_string(va_arg(ap, void *), format[i]);
			else
				count += mod_putchar(format[i]);
		}
		else
			count += mod_putchar(format[i]);
	}
	va_end(ap);
	return (count);
}
