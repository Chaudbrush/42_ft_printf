/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:46:35 by vloureir          #+#    #+#             */
/*   Updated: 2025/03/13 15:55:28 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H

# define FTPRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int ft_printf(const char *format, ...);
int	mod_putchar(char c);
int	mod_putnbr(int nb);
int	mod_putnbr_u(unsigned int nb);
int	mod_puthex(unsigned int nb, char c);
int	sort_int(int nb, char c);
int	mod_putstr(char *str);
int	mod_putmem(size_t nb);
int	check_mem(size_t nb);
int	sort_string(void *data, char c);

#endif
