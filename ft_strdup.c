/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:56:10 by malasaha          #+#    #+#             */
/*   Updated: 2022/05/14 16:35:49 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *str)
{
	int		i;
	int		len;
	char	*temp;

	i = 0;
	len = ft_strlen(str);
	temp = (char *)malloc(sizeof(char) * len + 1);
	if (!temp)
		return (0);
	while (i < len)
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
