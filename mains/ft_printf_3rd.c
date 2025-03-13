/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:36:18 by vloureir          #+#    #+#             */
/*   Updated: 2025/03/13 13:16:02 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//	*** EVERYTHING BELOW GOES TO A DIFFERENT FILE ***
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
		count = mod_putchar('-');
		nb_l = -nb_l;
	}
	if (nb_l >= 9)
		count += mod_putnbr(nb_l / 10);
	count += mod_putchar((nb_l % 10) + '0');
	return (count);
}

int	mod_putnbr_u(unsigned int nb)
{
	int		count;

	count = 0;
	if (nb >= 9)
		count += mod_putnbr_u(nb / 10);
	count += mod_putchar((nb % 10) + '0');
	return (count);
}

int	mod_puthex(unsigned int nb, char c)
{
	int		count;
	char	*hex_low;
	char	*hex_upp;

	count = 0;
	hex_low = "0123456789abcdef";
	hex_upp = "0123456789ABCDEF";
	if (nb >= 16)
		count += mod_puthex(nb / 16, c);
	if (c == 'x')
		count += mod_putchar(hex_low[nb % 16]);
	else
		count += mod_putchar(hex_upp[nb % 16]);
	return (count);
}

int	ft_print_int(int nb, char c)
{
	if (c == 'd')
		return (mod_putnbr(nb));
	else if (c == 'i')
		return (mod_putnbr(nb));
	else if (c == 'u')
		return (mod_putnbr_u(nb));
	else if (c == 'x')
		return (mod_puthex(nb, c));
	else if (c == 'X')
		return (mod_puthex(nb, c));
	else
		return (mod_putchar(nb));
}
//	*** EVERYTHING ABOVE GOES TO A DIFFERENT FILE ***

//	*** EVERYTHING BELOW GOES TO A DIFFERENT FILE ***
int	mod_putstr(char *str)
{
	int	i;
	int	count;

	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	count = 0;
	i = -1;
	while (str[++i])
		count += mod_putchar(str[i]);
	return (count);
}

int	ft_putmem(size_t nb)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (nb >= 15)
		count += ft_putmem(nb / 16);
	count += mod_putchar(hex[nb % 16]);
	return (count);
}

int	ft_check_mem(size_t nb)
{
	if (!nb)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		return (ft_putmem(nb) + 2);
	}
}

int	test(void *data, char c)
{
	if (c == 's')
		return (mod_putstr((char *)data));
	else
		return (ft_check_mem((size_t)data));
}
//	*** EVERYTHING ABOVE GOES TO A DIFFERENT FILE ***

int	is_int(char c)
{
	if (c == 'c' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

int	ft_printf(const char *restrict format, ...)
{
	int		count;
	int		i;
	va_list	ap;

	va_start(ap, format);
	count = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			if (is_int(format[i]))
				count += ft_print_int(va_arg(ap, int), format[i]);
			else if (format[i] == 's' || format[i] == 'p')
				count += test(va_arg(ap, void *), format[i]);
			else
				count += mod_putchar(format[i]);
		}
		else
			count += mod_putchar(format[i]);
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	int	ft;
	int	og_og;

	og_og = 0;
	ft = ft_printf("d: %d, i: %i, u: %u, x: %x, X: %X, c: %c\n", 42, -42, -1, -1, 255, 'p');
	og_og = printf("d: %d, i: %i, u: %u, x: %x, X: %X, c: %c\n", 42, -42, -1, -1, 255, 'p');
	printf("ft: %d, og: %d\n", ft, og_og);
	ft = ft_printf("s: %s, p: %p, %p\n", "hello", &ft, &og_og);
	og_og = printf("s: %s, p: %p, %p\n", "hello", &ft, &og_og);
	printf("ft: %d, og: %d\n", ft, og_og);
}
/*
int	main(void)
{
	printf("%%d:\n");
	printf("\ncount: %d\n", mod_putnbr(2147483647));
	printf("\ncount: %d\n", mod_putnbr(-2147483648));
	printf("\ncount: %d\n\n", mod_putnbr(0));

	printf("%%u\n");
	printf("\ncount: %d\n", mod_putnbr_u(2147483647));
	printf("\ncount: %d\n", mod_putnbr_u(-1));
	printf("\ncount: %d\n\n", mod_putnbr_u(0));

	printf("%%x\n");
	printf("\ncount: %d\n", mod_puthex(255));
	printf("\ncount: %d\n", mod_puthex(-1));
	printf("\ncount: %d\n\n", mod_puthex(0));
}*/
