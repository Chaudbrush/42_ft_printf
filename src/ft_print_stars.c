/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:18:50 by vloureir          #+#    #+#             */
/*   Updated: 2025/06/13 11:32:14 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	mod_putstr(char *str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
		count += mod_putchar(str[i]);
	return (count);
}

int	check_str(char *str)
{
	if (!str)
		return (mod_putstr("(null)"));
	else
		return (mod_putstr(str));
}

int	mod_putmem(size_t nb)
{
	int			count;
	const char	*hex = "0123456789abcdef";

	count = 0;
	if (nb > 15)
		count += mod_putmem(nb / 16);
	count += mod_putchar(hex[nb % 16]);
	return (count);
}

int	check_mem(size_t nb)
{
	if (!nb)
		return (mod_putstr("(nil)"));
	else
		return (mod_putstr("0x") + mod_putmem(nb));
}
