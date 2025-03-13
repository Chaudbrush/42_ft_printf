/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_first.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:00:41 by vloureir          #+#    #+#             */
/*   Updated: 2025/03/09 20:46:12 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int	mod_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	mod_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		mod_putchar(str[i]);
		i++;
	}
	return (i);
}

int	mod_putmemory(size_t nb)
{
	int		count;
	char	*hex_low;

	hex_low = "0123456789abcdef";
	count = 0;
	if (nb >= 16)
		count = mod_putmemory(nb / 16);
	mod_putchar(hex_low[nb % 16]);
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
	if (c == 'a')
		mod_putchar(hex_low[nb % 16]);
	else if (c == 'A')
		mod_putchar(hex_upp[nb % 16]);
	return (count + 1);
}

int	uns_putnbr(unsigned int nb)
{
	int		count;

	count = 0;
	if (nb >= 10)
		count = uns_putnbr(nb / 10);
	mod_putchar((nb % 10) + '0');
	return (count + 1);
}

int	mod_putnbr(int nb)
{
	int		count;
	long	nb_l;

	count = 0;
	nb_l = nb;
	if (nb_l < 0)
	{
		mod_putchar('-');
		nb_l *= -1;
		count++;
	}
	if (nb_l >= 10)
		count = mod_putnbr(nb_l / 10);
	mod_putchar((nb_l % 10) + '0');
	return (count + 1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				count += mod_putchar((char)va_arg(ap, int));
			else if (format[i] == 's')
				count += mod_putstr(va_arg(ap, char *));
			else if (format[i] == 'd')
				count += mod_putnbr(va_arg(ap, int));
			else if (format[i] == 'u')
				count += uns_putnbr(va_arg(ap, unsigned int));
			else if (format[i] == 'x')
				count += mod_puthex(va_arg(ap, unsigned int), 'a');
			else if (format[i] == 'X')
				count += mod_puthex(va_arg(ap, unsigned int), 'A');
			else if (format[i] == 'p')
			{
				count += 2;
				write(1, "0x", 2);
				count += mod_putmemory(va_arg(ap, size_t));
			}
			else if (format[i] == 'i')
				count += mod_putnbr(va_arg(ap, int));
			else if (format[i] == '%')
				count += mod_putchar('%');
			else
				count += mod_putchar(format[i]);
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

int	main(void)
{
	int	ft;
	int	og_og;

	ft = ft_printf("ft_printf: hell%c %d %x %X %% %p\n", 'o', -1, 127, -1, &ft);
	og_og = printf("og_printf: hell%c %d %x %#X %% %p\n", 'o', -1, 127, -1, &ft);
	printf("ft: %d, og: %d\n", ft, og_og);
	ft = ft_printf("%i, %i, %i, %i, %i\n", -1, 052, 0x2a, 0xfffffffe, 0b101010);
	og_og = printf("%i, %i, %i, %i, %i\n", -1, 052, 0x2a, 0xfffffffe, 0b101010);
	printf("ft: %d, og: %d\n", ft, og_og);
	ft = ft_printf("%d, %d, %d, %d, %d\n", -1, 052, 0x2a, 0xfffffffe, 0b101010);
	og_og = printf("%d, %d, %d, %d, %d\n", -1, 052, 0x2a, 0xfffffffe, 0b101010);
	printf("ft: %d, og: %d\n", ft, og_og);

// BONUS TESTS

	printf("\n--------------------\n\n");
//	ft = ft_printf("ft_printf: hell%c %d %x %X %% %p\n", 'o', -1, 127, -1, &ft);
	og_og = printf("og_printf: hell%016d %.0d %+d %#X %% %p\n", 4255, 250, 42, -1, &ft);
	printf("ft: %d, og: %d\n", ft, og_og);
}
/*
if (== 0)
	if (== x)
		hex
	else if (== b)
		bit
	else if (!= 0)
		octal
	else
		print 0;
else
	decimal
*/
