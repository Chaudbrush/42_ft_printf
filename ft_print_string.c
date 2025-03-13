/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:39:23 by vloureir          #+#    #+#             */
/*   Updated: 2025/03/13 15:55:58 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	mod_putstr(char *str)
{
	int	i;
	int	count;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = -1;
	count = 0;
	while (str[++i])
		count += mod_putchar(str[i]);
	return (count);
}

int	mod_putmem(size_t nb)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (nb >= 16)
		count += mod_putmem(nb / 16);
	count += mod_putchar(hex[nb % 16]);
	return (count);
}

int	check_mem(size_t nb)
{
	if (!nb)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		mod_putstr("0x");
		return (mod_putmem(nb) + 2);
	}
}

int	sort_string(void *data, char c)
{
	if (c == 's')
		return (mod_putstr((char *)data));
	else
		return (check_mem((size_t)data));
}
