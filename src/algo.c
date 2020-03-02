/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:06:08 by hde-ghel          #+#    #+#             */
/*   Updated: 2020/03/02 22:07:47 by hde-ghel         ###   ########.fr       */
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

t_list_filler		check_closest_to(t_filler *env, t_list_filler *list, t_xy c)
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
	return(best_link);
}

void		init_coord_to_reach(t_filler *env)
{
	if (env->enemy_zone == 4)
	{
		env->f_corner.x = env->c_map.x;
		env->f_corner.y = 0;
		env->s_corner.x = 0;
		env->s_corner.y = env->c_map.y;
	}
	if (env->enemy_zone == 3)
	{
		env->f_corner.x = 0;
		env->f_corner.y = 0;
		env->s_corner.x = env->c_map.x;
		env->s_corner.y = env->c_map.y;
	}
	if (env->enemy_zone == 2)
	{
		env->f_corner.x = 0;
		env->f_corner.y = 0;
		env->s_corner.x = env->c_map.x;
		env->s_corner.y = env->c_map.y;
	}
	if (env->enemy_zone == 1)
	{
		env->f_corner.x = env->c_map.x;
		env->f_corner.y = 0;
		env->s_corner.x = 0;
		env->s_corner.y = env->c_map.y;
	}
}

void		init_last_corner(t_filler *env)
{
	if (env->enemy_zone == 4)
	{
		env->s_corner.x = env->c_map.x;
		env->s_corner.y = env->c_map.y;
	}
	if (env->enemy_zone == 3)
	{
		env->s_corner.x = 0;
		env->s_corner.y = env->c_map.y;
	}
	if (env->enemy_zone == 2)
	{
		env->s_corner.x = env->c_map.x;
		env->s_corner.y = 0;
	}
	if (env->enemy_zone == 1)
	{
		env->s_corner.x = 0;
		env->s_corner.y = 0;
	}
}

void		check_last_move(t_filler *env, t_xy m)
{
	if (m.x > 0 && m.y > 0 && env->map[m.y][m.x] == env->enemy[1] && env->map[m.y][m.x] != env->old_map[m.y][m.x])
	{
		env->c_enemy.y = m.y;
		env->c_enemy.x = m.x;
	}
}

void		check_best_pos(t_filler *env, t_list_filler *list)
{
	t_list_filler	best_pos;

	best_pos = check_closest_to(env, list, env->c_enemy);
	ft_putstr_fd("\n c.en.x = ", env->fd);
	ft_putnbr_fd(env->c_enemy.x, env->fd);
	ft_putstr_fd("\n c.en.y = ", env->fd);
	ft_putnbr_fd(env->c_enemy.y, env->fd);
	/*
	init_coord_to_reach(env);
	if (env->first_corner == 0)
	{
		best_pos = check_closest_to(env, list, env->f_corner);
		if (best_pos.max_x.x == env->c_map.x -1 || best_pos.min_y.y == 0)
			env->first_corner = 1;
	}
	else if (env->second_corner == 0)
	{
		best_pos = check_closest_to(env, list, env->s_corner);
		if (best_pos.max_x.x == 0 || best_pos.min_y.y == env->c_map.y - 1)
			env->second_corner = 1;
	}
	else
	{
		init_last_corner(env);
		best_pos = check_closest_to(env, list, env->s_corner);
	}
//	else
		//fill enemy side (enemy corner)
	*/
	env->c_place.x = best_pos.coord.x;
	env->c_place.y = best_pos.coord.y;
}

void		check_enemy_pos(t_filler *env, t_xy m)
{
	if (m.x > 0 && m.y > 0 && env->map[m.y][m.x] == env->enemy[1])
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
