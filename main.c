/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:41:51 by malasaha          #+#    #+#             */
/*   Updated: 2022/06/20 18:45:29 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_list *main)
{
	mlx_destroy_image(main->mlx, main->player);
	mlx_destroy_image(main->mlx, main->wall);
	mlx_destroy_image(main->mlx, main->exit);
	mlx_destroy_image(main->mlx, main->coll);
	mlx_destroy_image(main->mlx, main->win);
	free(main->map);
	free(main);
}

int	move(int keycode, t_list *main)
{
	if (keycode == 13 || keycode == 126)
		moveup(main);
	if (keycode == 1 || keycode == 125)
		movedown(main);
	if (keycode == 2 || keycode == 124)
		moveright(main);
	if (keycode == 0 || keycode == 123)
		moveleft(main);
	if (keycode == 53)
	{
		ft_free(main);
		ft_printf("%sdiamonds left in cave...!\n", "\x1B[31m");
		exit(0);
		return (0);
	}
	mlx_clear_window(main->mlx, main->win);
	putimage(main);
	ft_printf("%snumber of steps = %d\n", "\033[33m", main->movecount + 1);
	return (1);
}

int	bercheck(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (s[i - 1] != 'r' || s[i - 2] != 'e' || s[i - 3] != 'b' || \
		s[i - 4] != '.' || i < 4)
	{
		ft_printf("%sError\nWrong File Name!\n", "\x1B[31m");
		return (0);
	}
	return (1);
}

int	xbutton(t_list *main)
{
	(void)main;
	ft_free(main);
	ft_printf("%sGAME OVER !\n", "\x1B[31m");
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*main;

	if (ac == 2)
	{
		main = malloc(sizeof(t_list));
		if (!(bercheck(av[1])))
		{
			ft_printf("Map name has to end with .ber extension\n");
			free(main);
			return (0);
		}
		if (!(creatmap(main, av[1])))
		{
			creatmap_free(main);
			return (0);
		}
		mlx_hook(main->win, 2, 1L << 0, move, main);
		mlx_hook(main->win, 17, 0, xbutton, main);
		mlx_loop(main->mlx);
	}
	else
	{
		ft_printf("%sError\nWrong Argument Number!\n", "\x1B[31m");
		exit(0);
	}
}
