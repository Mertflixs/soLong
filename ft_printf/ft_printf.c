/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:23:22 by malasaha          #+#    #+#             */
/*   Updated: 2022/05/14 16:35:58 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checker(va_list *args, char c)
{
	int	result;

	result = 0;
	if (c == 'c')
		result += ft_putchar(va_arg(*args, int));
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(*args, int), &result);
	else if (c == 's')
		result += ft_putstr(va_arg(*args, char *));
	else if (c == '%')
		result += write(1, "%", 1);
	else if (c == 'p')
	{
		result += write (1, "0x", 2);
		ft_pointer(va_arg(*args, unsigned long long), &result);
	}
	else if (c == 'u')
		ft_unsigned(va_arg(*args, unsigned int), &result);
	else if (c == 'x')
		ft_lowerx(va_arg(*args, unsigned int), &result);
	else if (c == 'X')
		ft_lowerx(va_arg(*args, unsigned int), &result);
	return (result);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		result;

	va_start(args, s);
	i = 0;
	result = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			result += ft_checker(&args, s[i]);
		}
		else
		{
			result += write(1, &s[i], 1);
		}
		i++;
	}
	va_end(args);
	return (result);
}
