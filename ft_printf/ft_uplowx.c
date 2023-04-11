/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uplowx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:46:41 by malasaha          #+#    #+#             */
/*   Updated: 2022/05/16 18:43:21 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_upperx(unsigned int n, int *s)
{
	if (n < 16)
	{
		if (n < 10)
		{
			*s += ft_putchar(n + 48);
		}
		else
		{
			*s += ft_putchar(n + 87);
		}
	}
	else
	{
		ft_upperx(n / 16, s);
		ft_upperx(n % 16, s);
	}
	return (*s);
}

int	ft_lowerx(unsigned int n, int *s)
{
	if (n < 16)
	{
		if (n < 10)
		{
			*s += ft_putchar(n + 48);
		}
		else
		{
			*s += ft_putchar(n + 55);
		}
	}
	else
	{
		ft_lowerx(n / 16, s);
		ft_lowerx(n % 16, s);
	}
	return (*s);
}

int	ft_pointer(unsigned long long n, int *s)
{
	if (n < 16)
	{
		if (n < 10)
		{
			*s += ft_putchar(n + 48);
		}
		else
		{
			*s += ft_putchar(n + 87);
		}
	}
	else
	{
		ft_pointer(n / 16, s);
		ft_pointer(n % 16, s);
	}
	return (*s);
}
