/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:08:25 by malasaha          #+#    #+#             */
/*   Updated: 2022/06/20 15:20:46 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkarray(t_list *main)
{
	int	i;
	int	ec;
	int	pc;

	main->cc = 0;
	i = 0;
	ec = 0;
	pc = 0;
	while (main->map[i])
	{
		if (main->map[i] == 'E')
			ec++;
		if (main->map[i] == 'C')
			main->cc++;
		if (main->map[i] == 'P')
		{
			main->pindex = i;
			pc++;
		}
		i++;
	}
	if (ec == 0 || main->cc == 0 || pc != 1)
		return (0);
	return (1);
}

static int	checksides(t_list *main)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (main->map[i])
	{
		if (main->map[i] == '\n')
		{
			if (main->map[i + 1] != '1' || main->map[i - 1] != '1')
				return (0);
		}
		i++;
	}
	i = 0;
	while (main->map[i])
	{
		if (main->map[i] != '\n')
			x++;
		if (main->map[i++] == '\n')
			x = 0;
		if (x > main->slen || (x < main->slen && main->map[i] == '\n'))
			return (0);
	}
	return (1);
}

static int	checkwall(t_list *main)
{
	int	i;

	i = 0;
	while (main->map[i] != '\n')
	{
		if (main->map[i] != '1')
			return (0);
		i++;
	}
	main->slen = i;
	i = 0;
	while (main->map[i])
		i++;
	i--;
	while (main->map[i] != '\n')
	{
		if (main->map[i] != '1')
			return (0);
		i--;
	}
	return (1);
}

static int	checksquare(t_list *main)
{
	int	i;
	int	xc;
	int	yc;

	i = 0;
	xc = 0;
	yc = 2;
	while (main->map[i++] != '\n')
		xc++;
	while (main->map[i])
	{
		if (main->map[i] == '\n')
			yc++;
		i++;
	}
	if (xc == yc)
		return (0);
	return (1);
}

int	checkmap(t_list *main)
{
	int	i;

	i = 0;
	if (!checkarray(main))
		return (0);
	if (!checkwall(main))
		return (0);
	if (!checksquare(main))
		return (0);
	if (!checksides(main))
		return (0);
	while (main->map[i])
	{
		if ((ft_strchr("ECP10", main->map[i]) && main->map[i] != '\n'))
			return (0);
		i++;
	}
	return (1);
}
