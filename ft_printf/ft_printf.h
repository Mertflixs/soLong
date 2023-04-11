/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:23:37 by malasaha          #+#    #+#             */
/*   Updated: 2022/05/16 18:44:11 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_putchar(int c);
int	ft_putnbr(int c, int *s);
int	ft_putstr(char *str);
int	ft_unsigned(unsigned int n, int *s);

int	ft_pointer(unsigned long long n, int *s);
int	ft_lowerx(unsigned int n, int *s);
int	ft_upperx(unsigned int n, int *s);

int	ft_checker(va_list *args, char c);
int	ft_printf(const char *s, ...);

#endif