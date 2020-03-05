/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:06:08 by hde-ghel          #+#    #+#             */
/*   Updated: 2020/03/03 21:23:02 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int					check_dist(t_xy start, int x_end, int y_end)
{
	int		dist;
	int		x;
	int		y;

	if ((x = start.x - x_end) < 0)
		x *= -1;
	if ((y = start.y - y_end) < 0)
		y *= -1;
	dist = x + y;
	return (dist);
}

t_list_filler		check_closest_to(t_list_filler *list, t_xy c)
{
	t_list_filler	best_link;
	t_list_filler	*tmp;
	int				dist_min;

	tmp = list;
	dist_min = INT_MAX;
	while (tmp != NULL)
	{
		if (check_dist(tmp->avg_c, c.x, c.y) <= dist_min)
		{
			dist_min = check_dist(tmp->avg_c, c.x, c.y);
			best_link = *tmp;
		}
		tmp = tmp->next;
	}
	return (best_link);
}

void				check_last_move(t_filler *env, t_xy m)
{
	if (m.x >= 0 && m.y >= 0 && env->map[m.y][m.x] == env->enemy &&
			env->map[m.y][m.x] != env->old_map[m.y][m.x])
	{
		env->c_enemy.y = m.y;
		env->c_enemy.x = m.x;
	}
}

void				check_best_pos(t_filler *env, t_list_filler *list)
{
	t_list_filler	best_pos;

	best_pos = check_closest_to(list, env->c_enemy);
	env->c_place.x = best_pos.coord.x;
	env->c_place.y = best_pos.coord.y;
}
