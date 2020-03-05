/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_placable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:37:19 by hde-ghel          #+#    #+#             */
/*   Updated: 2020/03/03 21:30:44 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int				check_piece_part(t_filler *env, t_xy *m, t_xy *p)
{
	if ((m->y + p->y) >= 0 && (m->y + p->y) < env->c_map.y &&
			(m->x + p->x) >= 0 && (m->x + p->x) < env->c_map.x)
	{
		if (env->map[m->y + p->y][m->x + p->x] != env->enemy)
		{
			if (env->map[m->y + p->y][m->x + p->x] == env->player)
				env->overlap += 1;
			return (0);
		}
	}
	return (-1);
}

int				is_placable(t_filler *env, t_xy m)
{
	t_xy	p;

	p.x = 0;
	p.y = 0;
	env->overlap = 0;
	init_save_max(env);
	while (p.y < env->c_piece.y)
	{
		p.x = 0;
		while (p.x < env->c_piece.x)
		{
			if (env->piece[p.y][p.x] == '*')
				if (check_piece_part(env, &m, &p) == -1)
					return (-1);
			check_max(env, &m, &p);
			p.x++;
		}
		p.y++;
	}
	if (env->overlap == 1)
		return (0);
	return (-1);
}

t_list_filler	*add_link(t_filler *env, t_list_filler *list, t_xy m)
{
	t_list_filler	*new;

	if (!(new = ft_memalloc(sizeof(t_list_filler))))
		return (free_list(list));
	init_list(new);
	fill_list(env, new, m);
	new->next = list;
	return (new);
}

int				list_possible(t_filler *env, t_list_filler **lst)
{
	t_xy	m;

	m.x = -env->c_piece.x;
	m.y = -env->c_piece.y;
	while (m.y < env->c_map.y)
	{
		m.x = -env->c_piece.x;
		while (m.x < env->c_map.x)
		{
			if (env->first_turn)
				check_last_move(env, m);
			if (!is_placable(env, m))
				if (!(*lst = add_link(env, *lst, m)))
					return (-1);
			m.x++;
		}
		m.y++;
	}
	if (!env->first_turn)
	{
		env->first_turn = 1;
		env->c_enemy.x = env->c_map.x / 2;
		env->c_enemy.y = env->c_map.y / 2;
	}
	return (0);
}
