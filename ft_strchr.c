/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:37:25 by malasaha          #+#    #+#             */
/*   Updated: 2022/05/15 16:38:30 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strchr(char *s, int c)
{
	int				i;
	unsigned int	p;

	i = 0;
	p = (char) c;
	if (p == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char)p)
			return (0);
		i++;
	}
	return (1);
}
