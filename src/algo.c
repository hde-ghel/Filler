/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:06:08 by hde-ghel          #+#    #+#             */
/*   Updated: 2020/02/29 22:29:50 by hde-ghel         ###   ########.fr       */
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

void		check_best_pos(t_filler *env, t_list_filler *list)
{
	int				dist_min;
	t_list_filler	*tmp;

	tmp = list;
	dist_min = INT_MAX;
	while(tmp != NULL)
	{
		if (check_dist(tmp->max_x, env->c_map.x, 0) <= dist_min)
			{
				dist_min = check_dist(tmp->min_y, env->c_map.x / 2 , 0);
				env->c_place.x = tmp->coord.x;
				env->c_place.y = tmp->coord.y;
			}
		tmp = tmp->next;
	}
}
