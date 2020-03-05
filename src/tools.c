/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:55:24 by hde-ghel          #+#    #+#             */
/*   Updated: 2020/03/03 21:31:13 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void		init_list(t_list_filler *list)
{
	list->coord.x = 0;
	list->coord.y = 0;
	list->max_x.x = 0;
	list->max_x.y = 0;
	list->max_y.x = 0;
	list->max_y.y = 0;
	list->min_x.x = 0;
	list->min_x.y = 0;
	list->min_y.x = 0;
	list->min_y.y = 0;
}

void		fill_list(t_filler *env, t_list_filler *list, t_xy m)
{
	list->coord = m;
	list->max_x = env->max_x;
	list->min_x = env->min_x;
	list->max_y = env->max_y;
	list->min_y = env->min_y;
	list->avg_c.x = (env->max_x.x + env->min_x.x + env->max_y.x + env->min_y.x)
		/ 4;
	list->avg_c.y = (env->max_x.y + env->min_x.y + env->max_y.y + env->min_y.y)
		/ 4;
}

void		init_save_max(t_filler *env)
{
	env->max_x.x = 0;
	env->max_x.y = 0;
	env->max_y.x = 0;
	env->max_y.y = 0;
	env->min_x.x = INT_MAX;
	env->min_x.y = 0;
	env->min_y.x = 0;
	env->min_y.y = INT_MAX;
}

void		check_max(t_filler *env, t_xy *m, t_xy *p)
{
	if ((m->y + p->y) > env->max_y.y)
	{
		env->max_y.x = m->x + p->x;
		env->max_y.y = m->y + p->y;
	}
	if ((m->y + p->y) < env->min_y.y)
	{
		env->min_y.x = m->x + p->x;
		env->min_y.y = m->y + p->y;
	}
	if ((m->x + p->x) > env->max_x.x)
	{
		env->max_x.x = m->x + p->x;
		env->max_x.y = m->y + p->y;
	}
	if ((m->x + p->x) < env->min_x.x)
	{
		env->min_x.x = m->x + p->x;
		env->min_x.y = m->y + p->y;
	}
}
