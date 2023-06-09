/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:30:13 by malasaha          #+#    #+#             */
/*   Updated: 2022/06/20 18:43:36 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moveup(t_list *main)
{
	checkarray(main);
	if (main->map[main->pindex - main->slen - 1] != '1' \
		&& main->map[main->pindex - main->slen - 1] == '0')
	{
		main->map[main->pindex - main->slen - 1] = 'P';
		main->map[main->pindex] = '0';
		main->movecount++;
	}
	if (main->map[main->pindex - main->slen - 1] == 'C')
	{
		main->map[main->pindex - main->slen - 1] = 'P';
		main->map[main->pindex] = '0';
		main->movecount++;
	}
	if (main->map[main->pindex - main->slen - 1] == 'E' \
		&& main->cc == 0)
	{
		ft_printf("%sCongratulations All diamonds collected : %d steps", \
					"\x1B[31m", main->movecount + 2);
		ft_free(main);
		exit(0);
	}
}

void	movedown(t_list *main)
{
	checkarray(main);
	if (main->map[main->pindex + main->slen + 1] != '1' \
		&& main->map[main->pindex + main->slen + 1] == '0')
	{
		main->map[main->pindex + main->slen + 1] = 'P';
		main->map[main->pindex] = '0';
		main->movecount++;
	}
	if (main->map[main->pindex + main->slen + 1] == 'C')
	{
		main->map[main->pindex + main->slen + 1] = 'P';
		main->map[main->pindex] = '0';
		main->movecount++;
	}
	if (main->map[main->pindex + main->slen + 1] == 'E' \
		&& main->cc == 0)
	{
		ft_printf("%sCongratulations All diamonds collected : %d steps", \
					"\x1B[31m", main->movecount + 2);
		ft_free(main);
		exit(0);
	}
}

void	moveright(t_list *main)
{
	checkarray(main);
	if (main->map[main->pindex + 1] != '1' \
		&& main->map[main->pindex + 1] == '0')
	{
		main->map[main->pindex + 1] = 'P';
		main->map[main->pindex] = '0';
		main->movecount++;
	}
	if (main->map[main->pindex + 1] == 'C')
	{
		main->map[main->pindex + 1] = 'P';
		main->map[main->pindex] = '0';
		main->movecount++;
	}
	if (main->map[main->pindex + 1] == 'E' \
		&& main->cc == 0)
	{
		ft_printf("%sCongratulations All diamonds collected : %d steps", \
					"\x1B[31m", main->movecount + 2);
		ft_free(main);
		exit(0);
	}
}

void	moveleft(t_list *main)
{
	checkarray(main);
	if (main->map[main->pindex - 1] != '1' \
		&& main->map[main->pindex - 1] == '0')
	{
		main->map[main->pindex - 1] = 'P';
		main->map[main->pindex] = '0';
		main->movecount++;
	}
	if (main->map[main->pindex - 1] == 'C')
	{
		main->map[main->pindex - 1] = 'P';
		main->map[main->pindex] = '0';
		main->movecount++;
	}
	if (main->map[main->pindex - 1] == 'E' \
		&& main->cc == 0)
	{
		ft_printf("%sCongratulations All diamonds collected : %d steps", \
					"\x1B[31m", main->movecount + 2);
		ft_free(main);
		exit(0);
	}
}
