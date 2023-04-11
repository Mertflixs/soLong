/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:35:47 by malasaha          #+#    #+#             */
/*   Updated: 2022/05/16 18:43:08 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putnbr(int c, int *s)
{
	if (c == -2147483648)
	{
		*s += ft_putchar('-');
		*s += ft_putchar('2');
		c = 147483648;
	}
	if (c < 0)
	{
		*s += ft_putchar('-');
		c *= -1;
	}
	if (c >= 0 && c <= 9)
	{
		*s += ft_putchar(c + 48);
	}
	if (c > 9)
	{
		ft_putnbr(c / 10, s);
		ft_putnbr(c % 10, s);
	}
	return (*s);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_unsigned(unsigned int n, int *s)
{
	if (n >= 0 && n <= 9)
		*s += ft_putchar(n + 48);
	if (n > 9)
	{
		ft_unsigned(n / 10, s);
		ft_unsigned(n % 10, s);
	}
	return (*s);
}
