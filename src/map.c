/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 12:30:43 by hde-ghel          #+#    #+#             */
/*   Updated: 2020/02/09 16:21:12 by hde-ghel         ###   ########.fr       */
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

int		map_allocation(t_filler *env, char *line)
{
	env->c_map = check_size(env, line);

	return (0);
}

int		piece_allocation(t_filler *env)
{
	char *line;

	env->c_map = check_size(env, line);
	return (0);
}

void		fill_piece(t_filler *env)
{
}

void		fill_map(t_filler *env)
{
}
