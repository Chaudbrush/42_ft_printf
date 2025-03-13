/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spc_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:45:22 by vloureir          #+#    #+#             */
/*   Updated: 2025/03/11 12:45:25 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>

int	ft_printf(const char *format, ...);

int main(void)
{
    int ft;
    int og_og;
    char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";

    printf("\n\nTESTING c\n\n");
    ft = ft_printf("ft_d:%c\n", '0');
    og_og = printf("og_d:%c\n", '0');

    ft += ft_printf("ft_d: %c\n", '0' - 256);
    og_og += printf("og_d: %c\n", '0' - 256);

    ft += ft_printf("ft_INT: %c \n", '0' + 256);
    og_og += printf("og_INT: %c \n", '0' + 256);

    ft += ft_printf("ft_d: %c %c %c \n", '0', 0, '1');
    og_og += printf("og_d: %c %c %c \n", '0', 0, '1');

    ft += ft_printf("ft_d: %c %c %c \n", ' ', ' ', ' ');
    og_og += printf("og_d: %c %c %c \n", ' ', ' ', ' ');

    ft += ft_printf("ft_INT: %c %c %c \n", '1', '2', '3');
    og_og += printf("og_INT: %c %c %c \n", '1', '2', '3');

    ft += ft_printf("ft_d: %c %c %c \n", '2', '1', 0);
    og_og += printf("og_d: %c %c %c \n", '2', '1', 0);

    ft += ft_printf("ft_INT: %c %c %c \n", 0, '1', '2');
    og_og += printf("og_INT: %c %c %c \n", 0, '1', '2');
    printf("ft: %d, og: %d\n", ft, og_og);

    printf("\n\nTESTING s\n\n");
    ft = ft_printf("ft:%s\n", "");
    og_og = printf("og:%s\n", "");

    ft += ft_printf("ft: %s\n", "");
    og_og += printf("og: %s\n", "");

    ft += ft_printf("ft:%s \n", "");
    og_og += printf("og:%s \n", "");

    ft += ft_printf("ft: %s \n", "");
    og_og += printf("og: %s \n", "");

    ft += ft_printf("ft: %s \n", "-");
    og_og += printf("og: %s \n", "-");

    ft += ft_printf("ft: %s %s \n", "", "-");
    og_og += printf("og: %s %s \n", "", "-");

    ft += ft_printf("ft: %s %s \n", " - ", "");
    og_og += printf("og: %s %s \n", " - ", "");

    ft += ft_printf("ft: %s %s %s %s %s\n", " - ", "", "4", "", s2);
    og_og += printf("og: %s %s %s %s %s\n", " - ", "", "4", "", s2);

    ft += ft_printf("ft: %s %s %s %s %s \n", " - ", "", "4", "", "2 ");
    og_og += printf("og: %s %s %s %s %s \n", " - ", "", "4", "", "2 ");

    ft += ft_printf("ft: NULL %s NULL \n", NULL);
    og_og += printf("og: NULL %s NULL \n", NULL);
    printf("ft: %d, og: %d\n", ft, og_og);

    printf("\n\nTESTING p\n\n");
    ft = ft_printf("ft: %p %p \n", (void *)0, (void *)0);
    og_og = printf("og: %p %p \n", (void *)0, (void *)0);

    ft += ft_printf("ft: %p \n", (void *)-1);
    og_og += printf("og: %p \n", (void *)-1);

    ft += ft_printf("ft: %p \n", (void *)1);
    og_og += printf("og: %p \n", (void *)1);

    ft += ft_printf("ft: %p \n", (void *)42);
    og_og += printf("og: %p \n", (void *)42);

    ft += ft_printf("ft: %p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);
    og_og += printf("og: %p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);

    ft += ft_printf("ft: %p %p \n", (void *)INT_MIN, (void *)INT_MAX);
    og_og += printf("og: %p %p \n", (void *)INT_MIN, (void *)INT_MAX);

    ft += ft_printf("ft: %p %p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX);
    og_og += printf("og: %p %p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX);

    printf("ft: %d, og: %d\n", ft, og_og);
}