/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:40:39 by hde-ghel          #+#    #+#             */
/*   Updated: 2020/03/02 22:07:50 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/filler.h"

int		get_player(t_filler *env)
{
	char	*line;

	if (get_next_line(0, &line) == -1)
		return (-1);
	if (ft_strstr(line, "p1"))
	{
		env->player[1] = 'O';
		env->player[0] = 'o';
	}
	else if (ft_strstr(line, "p2"))
	{
		env->player[1] = 'X';
		env->player[0] = 'x';
	}
	env->enemy[1] = (env->player[1] == 'O') ? 'X' : 'O';
	env->enemy[0] = (env->player[1] == 'O') ? 'x' : 'o';
	ft_strdel(&line);
	//print_player(env);
	return (0);
}

int		play(t_filler *env, char *line)
{
	t_list_filler	*placable;

	placable = NULL;
	env->c_place.y = 0;
	env->c_place.x = 0;
	if (map_allocation(env, line) == -1)
		return (-1);
	if ((piece_allocation(env)) == -1)
	{
		//FREE_MAP
		return (-1);
	}
	if (list_possible(env, &placable) == 1)//protection
		return (-1); //FREE_ALL
	if (placable == NULL)
	{
		env->c_place.x = 0;
		env->c_place.y = 0;
	}
	else
	{
		check_best_pos(env, placable);
	}
	//Free_map
	env->old_map = env->map;
	send_coord(env);

	//FREE_ALL

	return (0);
}

int		read_vm(t_filler *env)
{
	int		gnl_check;
	char	*line;

	//ft_putstr_fd(, env->fd);
	while ((gnl_check = get_next_line(0, &line)) > 0)
	{
		if (gnl_check < 0)
			return (-1);
		if (ft_strstr(line, "Plateau"))
		{
			if (play(env, line) == -1)
				return (-1);
		}
		ft_strdel(&line);
	}
	return (0);
}

int	main(void)
{
	t_filler	env;

	ft_bzero(&env, sizeof(t_filler));
	env.fd = open("/Users/hde-ghel/Desktop/repo_19/filler/log/log2", O_WRONLY);

	if (get_player(&env) == -1)
		return (-1);
	//while (1)
	//{
		if (read_vm(&env) == -1)
			return (-1);
	//}
	close(env.fd);
	return (0);
}
