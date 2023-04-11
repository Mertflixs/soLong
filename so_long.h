/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:56:24 by malasaha          #+#    #+#             */
/*   Updated: 2022/06/20 16:39:30 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "ft_printf/ft_printf.h"

typedef struct s_list
{
	void	*mlx;
	void	*win;
	void	*player;
	void	*wall;
	void	*coll;
	void	*exit;
	char	*map;
	int		sizex;
	int		sizey;
	int		fd;
	int		index;
	int		slen;
	int		cc;
	int		x;
	int		y;
	int		pindex;
	int		movecount;	
}			t_list;

size_t		ft_strlen(char *str);
char		*ft_strdup(char *str);
int			ft_strchr(char *s, int c);
char		*ft_read(int fd, char *left_str);
int			checkmap(t_list *main);
int			creatmap(t_list *main, char *file);
int			checkarray(t_list *main);
void		moveleft(t_list *main);
void		moveright(t_list *main);
void		movedown(t_list *main);
void		moveup(t_list *main);
void		ft_free(t_list *main);
int			ft_printf(const char *s, ...);
void		putimage(t_list *main);
int			setup(t_list *main);
void		creatmap_free(t_list *main);

#endif
