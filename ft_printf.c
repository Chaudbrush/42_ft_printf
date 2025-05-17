/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:02:34 by vloureir          #+#    #+#             */
/*   Updated: 2025/05/05 16:01:58 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sort_format(va_list ap, char c)
{
	if (c == 's')
		return (check_str(va_arg(ap, char *)));
	else if (c == 'p')
		return (check_mem(va_arg(ap, size_t)));
	else if (c == 'c')
		return (mod_putchar(va_arg(ap, int)));
	else if (c == 'd' || c == 'i')
		return (mod_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		return (mod_putnbr_u(va_arg(ap, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (mod_puthex(va_arg(ap, unsigned int), c));
	else
		return (mod_putchar(c));
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	ap;

	if (!format || write(1, 0, 0) == -1)
		return (-1);
	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (va_end(ap), -1);
			else
				count += sort_format(ap, format[i]);
			i++;
		}
		else
			count += mod_putchar(format[i++]);
	}
	va_end(ap);
	return (count);
}
