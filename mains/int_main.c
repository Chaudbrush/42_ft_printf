/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:45:09 by vloureir          #+#    #+#             */
/*   Updated: 2025/03/11 12:45:10 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>

int	ft_printf(const char *format, ...);

int main(void)
{
    int ft;
    int og_og;

    printf("\n\nTESTING d\n\n");
    ft = ft_printf("ft_d: %d %d %d %d %d %d %d %d %d %d %d %d\n", 0, 1, 9, 10, 11, 15, 16, 17, 42, 99, 100, 101);
    og_og = printf("og_d: %d %d %d %d %d %d %d %d %d %d %d %d\n", 0, 1, 9, 10, 11, 15, 16, 17, 42, 99, 100, 101);

    ft += ft_printf("ft_d: %d %d %d %d %d %d %d %d %d %d %d\n", -1, -9, -10, -11, -14, -15, -16, -42, -99, -100, -101);
    og_og += printf("og_d: %d %d %d %d %d %d %d %d %d %d %d\n", -1, -9, -10, -11, -14, -15, -16, -42, -99, -100, -101);

    ft += ft_printf("ft_INT: %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
    og_og += printf("og_INT: %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, UINT_MAX, ULONG_MAX, 9223372036854775807LL);

    ft += ft_printf("ft_all: %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    og_og += printf("og_all: %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("ft: %d, og: %d\n", ft, og_og);

    printf("\n\nTESTING i\n\n");
    ft += ft_printf("ft_d: %i %i %i %i %i %i %i %i %i %i %i %i\n", 0, 1, 9, 10, 11, 15, 16, 17, 42, 99, 100, 101);
    og_og += printf("og_d: %i %i %i %i %i %i %i %i %i %i %i %i\n", 0, 1, 9, 10, 11, 15, 16, 17, 42, 99, 100, 101);

    ft += ft_printf("ft_d: %i %i %i %i %i %i %i %i %i %i %i\n", -1, -9, -10, -11, -14, -15, -16, -42, -99, -100, -101);
    og_og += printf("og_d: %i %i %i %i %i %i %i %i %i %i %i\n", -1, -9, -10, -11, -14, -15, -16, -42, -99, -100, -101);

    ft += ft_printf("ft_INT: %i %i %i %i %i %i %i\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
    og_og += printf("og_INT: %i %i %i %i %i %i %i\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, UINT_MAX, ULONG_MAX, 9223372036854775807LL);

    ft += ft_printf("ft_all: %i %i %i %i %i %i %i\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    og_og += printf("og_all: %i %i %i %i %i %i %i\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("ft: %d, og: %d\n", ft, og_og);

    printf("\n\nTESTING u\n\n");
    ft += ft_printf("ft_d: %u %u %u %u %u %u %u %u %u %u %u %u\n", 0, 1, 9, 10, 11, 15, 16, 17, 42, 99, 100, 101);
    og_og += printf("og_d: %u %u %u %u %u %u %u %u %u %u %u %u\n", 0, 1, 9, 10, 11, 15, 16, 17, 42, 99, 100, 101);

    ft += ft_printf("ft_d: %u %u %u %u %u %u %u %u %u %u %u\n", -1, -9, -10, -11, -14, -15, -16, -42, -99, -100, -101);
    og_og += printf("og_d: %u %u %u %u %u %u %u %u %u %u %u\n", -1, -9, -10, -11, -14, -15, -16, -42, -99, -100, -101);

    ft += ft_printf("ft_INT: %u %u %u %u %u %u %u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
    og_og += printf("og_INT: %u %u %u %u %u %u %u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, UINT_MAX, ULONG_MAX, 9223372036854775807LL);

    ft += ft_printf("ft_all: %u %u %u %u %u %u %u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    og_og += printf("og_all: %u %u %u %u %u %u %u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("ft: %d, og: %d\n", ft, og_og);
}
