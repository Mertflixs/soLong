/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:51:42 by malasaha          #+#    #+#             */
/*   Updated: 2022/06/20 18:16:30 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		a;
	char	*array;
	size_t	len;

	a = 0;
	i = 0;
	if (s1 != NULL)
	{
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
		array = (char *)malloc(sizeof(char) * (len));
		if (array == NULL)
			return (0);
		while (s1[i] != '\0')
			array[a++] = s1[i++];
		i = 0;
		while (s2[i] != '\0')
			array[a++] = s2[i++];
		array[a] = '\0';
		free(s1);
		return (array);
	}
	return (0);
}

char	*ft_read(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	rd_bytes = 1;
	left_str = ft_strdup("");
	buff = malloc(sizeof(char) * 2);
	if (!buff)
		return (0);
	while (rd_bytes != 0)
	{
		if (!buff)
			return (NULL);
		rd_bytes = read(fd, buff, 1);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

void	creatmap_free(t_list *main)
{
	ft_printf("Error\n");
	free(main->map);
	free(main);
}
