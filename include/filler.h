/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:46:05 by hde-ghel          #+#    #+#             */
/*   Updated: 2020/02/08 16:19:37 by hde-ghel         ###   ########.fr       */
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
}				t_filler;

/*
** Map.c
*/
t_xy		check_size(t_filler *env, char *line);
int			map_allocation(t_filler *env);




#endif
