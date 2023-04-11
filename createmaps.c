/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createmaps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:50:12 by malasaha          #+#    #+#             */
/*   Updated: 2022/06/20 16:14:41 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sizexy(t_list *main)
{
	int	i;

	i = 0;
	while (main->map[i] != '\0')
	{
		if (main->map[i] != '\n' && main->sizey == 0)
			main->sizex += 64;
		if (main->map[i] == '\n')
			main->sizey += 64;
		i++;
	}
	main->sizey += 64;
	printf("%d %d\n", main->sizex, main->sizey);
}

void	putimage2(t_list *main, int i)
{
	if (main->map[i] == 'P')
	{
		mlx_put_image_to_window(main->mlx, main->win, main->player, \
		main->x, main->y);
		main->x += 64;
	}
	if (main->map[i] == 'E')
	{
		mlx_put_image_to_window(main->mlx, main->win, main->exit, \
		main->x, main->y);
		main->x += 64;
	}
	if (main->map[i] == 'C')
	{
		mlx_put_image_to_window(main->mlx, main->win, main->coll, \
		main->x, main->y);
		main->x += 64;
	}
}

void	putimage(t_list *main)
{
	int	i;

	i = 0;
	main->x = 0;
	main->y = 0;
	while (main->map[i])
	{
		if (main->map[i] == '1')
		{
			mlx_put_image_to_window(main->mlx, main->win, main->wall, \
			main->x, main->y);
			main->x += 64;
		}
		if (main->map[i] == '0')
			main->x += 64;
		if (main->map[i] == '\n')
		{
			main->x = 0;
			main->y += 64;
		}
		if (main->map[i] == 'E' || main->map[i] == 'P' || main->map[i] == 'C')
			putimage2(main, i);
		i++;
	}
}

int	setup(t_list *main)
{
	int	a;
	int	b;

	a = 65;
	b = 65;
	main->mlx = mlx_init();
	main->win = mlx_new_window(main->mlx, main->sizex, main->sizey, "So_Long");
	main->wall = mlx_xpm_file_to_image(main->mlx, "wall.xpm", &a, &b);
	main->exit = mlx_xpm_file_to_image(main->mlx, "exit.xpm", &a, &b);
	main->player = mlx_xpm_file_to_image(main->mlx, "player.xpm", &a, &b);
	main->coll = mlx_xpm_file_to_image(main->mlx, "coll.xpm", &a, &b);
	if (main->wall == NULL || main->exit == NULL \
	|| main->player == NULL || main->coll == NULL)
		return (0);
	main->sizex = 0;
	main->sizey = 0;
	putimage(main);
	return (1);
}

int	creatmap(t_list *main, char *file)
{
	main->fd = open(file, O_RDONLY);
	if (main->fd < 0)
		return (0);
	main->map = ft_read(main->fd, main->map);
	if (!main->map)
		return (0);
	if (!(checkmap(main)))
		return (0);
	sizexy(main);
	if (!setup(main))
	{
		ft_printf("Error\n");
		exit(0);
	}
	return (1);
}
