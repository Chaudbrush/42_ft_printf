/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:44:55 by vloureir          #+#    #+#             */
/*   Updated: 2025/03/11 12:44:57 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>

int	ft_printf(const char *format, ...);

int main(void)
{
    int ft;
    int og_og;

    printf("\n\nTESTING x\n\n");
    ft = ft_printf("ft_d: %x %x %x %x %x %x %x %x %x %x %x %x\n", 0, 1, 9, 10, 11, 15, 16, 17, 42, 99, 100, 101);
    og_og = printf("og_d: %x %x %x %x %x %x %x %x %x %x %x %x\n", 0, 1, 9, 10, 11, 15, 16, 17, 42, 99, 100, 101);

    ft += ft_printf("ft_d: %x %x %x %x %x %x %x %x %x %x %x\n", -1, -9, -10, -11, -14, -15, -16, -42, -99, -100, -101);
    og_og += printf("og_d: %x %x %x %x %x %x %x %x %x %x %x\n", -1, -9, -10, -11, -14, -15, -16, -42, -99, -100, -101);

    ft += ft_printf("ft_INT: %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
    og_og += printf("og_INT: %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, UINT_MAX, ULONG_MAX, 9223372036854775807LL);

    ft += ft_printf("ft_all: %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    og_og += printf("og_all: %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("ft: %d, og: %d\n", ft, og_og);

    printf("\n\nTESTING X\n\n");
    ft = ft_printf("ft_d: %X %X %X %X %X %X %X %X %X %X %X %X\n", 0, 1, 9, 10, 11, 15, 16, 17, 42, 99, 100, 101);
    og_og = printf("og_d: %X %X %X %X %X %X %X %X %X %X %X %X\n", 0, 1, 9, 10, 11, 15, 16, 17, 42, 99, 100, 101);

    ft += ft_printf("ft_d: %X %X %X %X %X %X %X %X %X %X %X\n", -1, -9, -10, -11, -14, -15, -16, -42, -99, -100, -101);
    og_og += printf("og_d: %X %X %X %X %X %X %X %X %X %X %X\n", -1, -9, -10, -11, -14, -15, -16, -42, -99, -100, -101);

    ft += ft_printf("ft_INT: %X %X %X %X %X %X %X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
    og_og += printf("og_INT: %X %X %X %X %X %X %X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, UINT_MAX, ULONG_MAX, 9223372036854775807LL);

    ft += ft_printf("ft_all: %X %X %X %X %X %X %X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    og_og += printf("og_all: %X %X %X %X %X %X %X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("ft: %d, og: %d\n", ft, og_og);

    printf("\n\nTESTING %%\n\n");
    ft = ft_printf("ft_d: %% \n");
    og_og = printf("og_d: %% \n");

    ft += ft_printf("ft_d: %%%% \n");
    og_og += printf("og_d: %%%% \n");

    ft += ft_printf("ft_INT: %% %% %% \n");
    og_og += printf("og_INT: %% %% %% \n");

    ft += ft_printf("ft_all: %%  %%  %% \n");
    og_og += printf("og_all: %%  %%  %% \n");

    ft += ft_printf("ft_d: %%   %%   %% \n");
    og_og += printf("og_d: %%   %%   %% \n");

    ft += ft_printf("ft_INT:%%\n");
    og_og += printf("og_INT:%%\n");
    
    ft += ft_printf("ft_all:%% %%\n");
    og_og += printf("og_all:%% %%\n");
    printf("ft: %d, og: %d\n", ft, og_og);
}