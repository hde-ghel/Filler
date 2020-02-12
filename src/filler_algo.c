/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:35:51 by hde-ghel          #+#    #+#             */
/*   Updated: 2020/02/11 13:20:31 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		check_piece_part(t_filler *env, t_xy m, t_xy p)
{
	if ((m.y + p.y) >= 0 && (m.y + p.y) < env->c_map.y && (m.x + p.x) >= 0 &&
			(m.x + p.x) < env->c_map.x)
	{
		if (env->map[m.y + p.y][m.x + p.x] != env->enemy)
		{
			if (env->map[m.y + p.y][m.x + p.x] == env->player)
				env->overlap += 1;
			return (0);
		}
	}
	return (-1);
}

int		is_placable(t_filler *env, t_xy m)
{
	t_xy	p;

	env->overlap = 0;
	p.x = 0;
	p.y = 0;
	while(p.y < env->c_piece.y)
	{
		p.x = 0;
		while(p.x < env->c_piece.x)
		{
			if (env->piece[p.y][p.x] == '*')
				if (check_piece_part(env, m, p) == -1)
					return (-1);
			p.x++;
		}
		p.y++;
	}
	if (env->overlap == 1)
	{
		env->c_place.y = m.y;
		env->c_place.x = m.x;
		return (0);
	}
	return (-1);
}

int		algo(t_filler *env)
{
	t_xy	m;

	m.x = -env->c_piece.x;
	m.y = -env->c_piece.y;
	while (m.y < env->c_map.y)
	{
		m.x = -env->c_piece.x;
		while (m.x < env->c_map.x)
		{
			if (!is_placable(env, m))
				return (1);
			m.x++;
		}
		m.y++;
	}
	return (0);
}
