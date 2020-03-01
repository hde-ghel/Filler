/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:06:08 by hde-ghel          #+#    #+#             */
/*   Updated: 2020/03/01 18:57:06 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/filler.h"

int		check_dist(t_xy start, int x_end, int y_end)
{
	int		dist;
	int		x;
	int		y;
	
	if ((x = start.x - x_end) < 0)
		x *= -1;
	if ((y = start.y - y_end) < 0)
		y *= -1;
	dist = x + y;
	return(dist);
}

t_list_filler		check_closest_to(t_filler *env, t_list_filler *list, int x, int y)
{
	t_list_filler	best_link;
	t_list_filler	*tmp;
	int				dist_min;

	tmp = list;
	dist_min = INT_MAX;
	while (tmp != NULL)
	{
		if (check_dist(tmp->max_x, x, y) <= dist_min)
			{
				dist_min = check_dist(tmp->max_x, x, y);
				best_link = *tmp;
			}
		tmp = tmp->next;
	}
	return(best_link);
}

void		check_best_pos(t_filler *env, t_list_filler *list)
{
	t_list_filler	best_pos;

	best_pos = check_closest_to(env, list, env->c_map.x, 0);
	if (best_pos.max_x.x == env->c_map.x -1 || best_pos.min_y.y == 0)
		best_pos = check_closest_to(env, list, 0, env->c_map.y);
	env->c_place.x = best_pos.coord.x;
	env->c_place.y = best_pos.coord.y;
}

void		check_enemy_pos(t_filler *env, t_xy m)
{
	if (m.x > 0 && m.y > 0 && env->map[m.y][m.x] == env->enemy)
	{
		if (m.y < env->c_map.y / 2)
		{
			if (m.x < env->c_map.x / 2)
				env->enemy_zone = 1;
			else
				env->enemy_zone = 2;
		}
		else
		{
			if (m.x < env->c_map.x / 2)
				env->enemy_zone = 3;
			else
				env->enemy_zone = 4;
		}
		env->first_turn = 1;
	}
}
