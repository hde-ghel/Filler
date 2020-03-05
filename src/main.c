/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:40:39 by hde-ghel          #+#    #+#             */
/*   Updated: 2020/03/05 14:35:13 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		get_player(t_filler *env)
{
	char	*line;

	if (get_next_line(0, &line) <= 0)
		return (-1);
	if (ft_strstr(line, "p1"))
		env->player = 'O';
	else if (ft_strstr(line, "p2"))
		env->player = 'X';
	env->enemy = (env->player == 'O') ? 'X' : 'O';
	ft_strdel(&line);
	return (0);
}

int		play(t_filler *env, char *line)
{
	t_list_filler	*placable;

	placable = NULL;
	env->c_place.y = 0;
	env->c_place.x = 0;
	if (map_allocation(env, line) == -1)
		return (free_all(env));
	if ((piece_allocation(env)) == -1)
		return (free_all(env));
	if (list_possible(env, &placable) == -1)
		return (free_all(env));
	if (placable == NULL)
		ft_bzero(&env->c_place, sizeof(t_xy));
	else
	{
		check_best_pos(env, placable);
		free_list(placable);
	}
	free_tab(env->old_map, NULL);
	free_tab(env->piece, NULL);
	env->old_map = env->map;
	send_coord(env);
	return (0);
}

int		read_vm(t_filler *env)
{
	int		gnl_check;
	char	*line;

	while ((gnl_check = get_next_line(0, &line)) > 0)
	{
		if (gnl_check < 0)
			return (-1);
		if (ft_strstr(line, "Plateau"))
		{
			if (play(env, line) == -1)
			{
				ft_strdel(&line);
				return (-1);
			}
		}
		ft_strdel(&line);
	}
	free_tab(env->old_map, NULL);
	return (0);
}

/*
** env.fd = open("/Users/hde-ghel/Desktop/repo_19/filler/log/log2", O_WRONLY);
*/

int		main(void)
{
	t_filler	env;

	ft_bzero(&env, sizeof(t_filler));
	if (get_player(&env) == -1)
		return (-1);
	if (read_vm(&env) == -1)
		return (-1);
	close(env.fd);
	return (0);
}
