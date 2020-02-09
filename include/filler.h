/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:46:05 by hde-ghel          #+#    #+#             */
/*   Updated: 2020/02/09 19:50:24 by hde-ghel         ###   ########.fr       */
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


typedef	struct	s_filler
{
	char	**map;
	char	**piece;
	char	player;
	int		end;
	t_xy	c_map;
	t_xy	c_piece;


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
int		algo(t_filler *env);

/*
** dev_tools.c
*/
void		print_map_info(t_filler *env);
void		print_piece_info(t_filler *env);


#endif
