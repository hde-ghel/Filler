/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 12:30:43 by hde-ghel          #+#    #+#             */
/*   Updated: 2020/02/08 16:19:17 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/filler.h"

t_xy	check_size(t_filler *env, char *line)
{
	int		i;
	t_xy	size;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	size.y = ft_atoi(&line[i]);
	while (!ft_isdigit(line[i]))
		i++;
	size.x = ft_atoi(&line[i]);
	return (size);
}

int		map_allocation(t_filler *env)
{
	env->c_map = check_size()
}
