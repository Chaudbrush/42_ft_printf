/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:26:46 by vloureir          #+#    #+#             */
/*   Updated: 2025/05/05 16:57:47 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	mod_putnbr(int nb);
int	mod_putchar(char c);
int	check_str(char *str);
int	check_mem(size_t nb);
int	mod_putstr(char *str);
int	mod_putmem(size_t nb);
int	mod_putnbr_u(unsigned int nb);
int	sort_format(va_list ap, char c);
int	mod_puthex(unsigned int nb, char c);
int	ft_printf(const char *format, ...);

#endif
