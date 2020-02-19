/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:46:05 by hde-ghel          #+#    #+#             */
/*   Updated: 2020/02/11 11:52:05 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include <fcntl.h>

# include <stdio.h>

typedef	struct	s_xy
{
	int		x;
	int		y;
}				t_xy;

typedef	struct	s_list_filler	t_list_filler;

struct			s_list_filler
{
	int				coord_x;
	int				coord_y;
	int				max_x;
	int				min_x;
	int				max_y;
	int				min_y;
	t_list_filler	*next;
};

typedef	struct	s_filler
{
	char	**map;
	char	**piece;
	char	player;
	char	enemy;
	int		end;
	t_xy	c_map;
	t_xy	c_piece;
	t_xy	c_place;
	int		overlap;


	FILE		*fd_log;
	int			fd;
}				t_filler;

/*
** map.c
*/
int			map_allocation(t_filler *env, char *line);
int			piece_allocation(t_filler *env);

/*
** filler_algo.c
*/
int			list_possible(t_filler *env, t_list_filler **lst);

/*
** tools.c
*/
void		init_list(t_list_filler *list);
void		fill_list(t_filler *env, t_list_filler *list, t_xy m);

/*
** dev_tools.c
*/
void		print_map_info(t_filler *env);
void		print_piece_info(t_filler *env);
void		print_player(t_filler *env);
void		send_coord(t_filler *env);

#endif
