/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:09:03 by vloureir          #+#    #+#             */
/*   Updated: 2025/05/05 16:57:44 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	mod_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	mod_putnbr(int nb)
{
	int		count;
	long	nb_l;

	nb_l = nb;
	count = 0;
	if (nb_l < 0)
	{
		count += mod_putchar('-');
		nb_l = -nb_l;
	}
	if (nb_l > 9)
		count += mod_putnbr(nb_l / 10);
	count += mod_putchar((nb_l % 10) + '0');
	return (count);
}

int	mod_putnbr_u(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
		count += mod_putnbr_u(nb / 10);
	count += mod_putchar((nb % 10) + '0');
	return (count);
}

int	mod_puthex(unsigned int nb, char c)
{
	int			count;
	const char	*hex_low = "0123456789abcdef";
	const char	*hex_upp = "0123456789ABCDEF";

	count = 0;
	if (nb > 15)
		count += mod_puthex(nb / 16, c);
	if (c == 'x')
		count += mod_putchar(hex_low[nb % 16]);
	else if (c == 'X')
		count += mod_putchar(hex_upp[nb % 16]);
	return (count);
}
