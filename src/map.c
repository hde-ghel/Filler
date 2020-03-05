/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 12:30:43 by hde-ghel          #+#    #+#             */
/*   Updated: 2020/03/05 14:36:59 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

t_xy	check_size(char *line)
{
	int		i;
	t_xy	size;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	size.y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	size.x = ft_atoi(&line[i]);
	return (size);
}

int		skip_tomap(char *str)
{
	int		i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (i + 1);
}

int		map_allocation(t_filler *env, char *line)
{
	t_xy	count;
	char	*tmp;

	count.y = 0;
	env->c_map = check_size(line);
	env->map = NULL;
	if (get_next_line(0, &tmp) <= 0)
		return (-1);
	ft_strdel(&tmp);
	if (!(env->map = (char **)malloc(sizeof(char *) * (env->c_map.y + 1))))
		return (-1);
	ft_bzero(env->map, sizeof(env->map));
	while (count.y < env->c_map.y)
	{
		if (get_next_line(0, &tmp) <= 0)
			return (free_tab(env->map, NULL));
		if (!(env->map[count.y++] = ft_strdup(tmp + skip_tomap(tmp))))
			return (free_tab(env->map, tmp));
		ft_strdel(&tmp);
	}
	env->map[count.y] = NULL;
	return (0);
}

int		piece_allocation(t_filler *env)
{
	char	*tmp;
	int		count;

	count = 0;
	if (get_next_line(0, &tmp) <= 0)
		return (-1);
	env->c_piece = check_size(tmp);
	ft_strdel(&tmp);
	if (!(env->piece = (char **)malloc(sizeof(char *) * (env->c_piece.y + 1))))
		return (-1);
	ft_bzero(env->piece, sizeof(env->map));
	while (count < env->c_piece.y)
	{
		if (get_next_line(0, &tmp) <= 0)
			return (free_tab(env->piece, NULL));
		if (!(env->piece[count++] = ft_strdup(tmp)))
			return (free_tab(env->piece, tmp));
		ft_strdel(&tmp);
	}
	env->piece[count] = NULL;
	return (0);
}
