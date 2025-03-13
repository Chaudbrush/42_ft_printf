/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:06:10 by vloureir          #+#    #+#             */
/*   Updated: 2025/03/11 15:04:37 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	mod_putchar(char c);
int	mod_putstr(char *str);
int	mod_putnbr(int nb);
int	uns_putnbr(unsigned int nb);
int	mod_puthex(unsigned int nb, char c);
int	check_mem(size_t nb);
int	mod_putmem(size_t nb);

int	ft_printf(const char *format, ...)
{
	int	i;
	int	count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '-')
				i++;
			if (format[i] == '%')
				count += mod_putchar('%');
			else if (format[i] == 'c')
				count += mod_putchar((char)va_arg(ap, int));
			else if (format[i] == 's')
				count += mod_putstr(va_arg(ap, char *));
			else if (format[i] == 'd' || format[i] == 'i')
				count += mod_putnbr(va_arg(ap, int));
			else if (format[i] == 'u')
				count += uns_putnbr((unsigned int)va_arg(ap, int));
			else if (format[i] == 'x')
				count += mod_puthex((unsigned int)va_arg(ap, int), 'x');
			else if (format[i] == 'X')
				count += mod_puthex((unsigned int)va_arg(ap, int), 'X');
			else if (format[i] == 'p')
				count += check_mem(va_arg(ap, size_t));
			else
				count += mod_putchar((char)va_arg(ap, int));
			i++;
		}
		else
		{
			count += mod_putchar(format[i]);
			i++;
		}
	}
	va_end(ap);
	return (count);
}

int	mod_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	mod_putstr(char *str)
{
	int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
		i = 0;
	while (str[i])
	{
		mod_putchar(str[i]);
		i++;
	}
	return (i);
}

int	mod_putnbr(int nb)
{
	int		count;
	long	nb_l;

	nb_l = nb;
	count = 0;
	if (nb_l < 0)
	{
		mod_putchar('-');
		nb_l *= -1;
		count++;
	}
	if (nb_l >= 10)
		count += mod_putnbr(nb_l / 10);
	mod_putchar((nb_l % 10) + '0');
	return (count + 1);
}

int	uns_putnbr(unsigned int nb)
{
	int		count;

	count = 0;
	if (nb >= 10)
		count = mod_putnbr(nb / 10);
	mod_putchar((nb % 10) + '0');
	return (count + 1);
}

int	mod_puthex(unsigned int nb, char c)
{
	int		count;
	char	*hex_low;
	char	*hex_upp;

	hex_low = "0123456789abcdef";
	hex_upp = "0123456789ABCDEF";
	count = 0;
	if (nb >= 16)
		count = mod_puthex(nb / 16, c);
	if (c == 'x')
		mod_putchar(hex_low[nb % 16]);
	else
		mod_putchar(hex_upp[nb % 16]);
	return (count + 1);
}

int	check_mem(size_t nb)
{
	int	count;

	if (nb == 0)
		count = mod_putstr("(nil)");
	else
	{
		count = mod_putstr("0x");
		count += mod_putmem(nb);
	}
	return (count);
}

int	mod_putmem(size_t nb)
{ 
	int		count;
	char	*hex_low;

	hex_low = "0123456789abcdef";
	count = 0;
	if (nb >= 16)
		count = mod_putmem(nb / 16);
	mod_putchar(hex_low[nb % 16]);
	return (count + 1);
}
