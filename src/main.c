/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:40:39 by hde-ghel          #+#    #+#             */
/*   Updated: 2020/02/07 16:53:00 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		get_player(t_filler *env)
{
	char	*line;

	if (get_next_line(0, &line) == -1)
		return (-1);
	if (ft_strstr(line, "p1"))
		env->player = 'O';
	else if (ft_strstr(line, "p2"))
		env->player = 'X';
	ft_strdel(&line);
//print player
	fprintf(env->fd_log, "Player = %c\n", env->player);
	return (0);
}

int		parse_piece(t_filler *env)
{

	return (0);
}

int		parse_map(t_filler *env)
{

	return (0);
}

int		read_vm(t_filler *env)
{
	int		gnl_check;
	char	*line;
	int		ret;

	while (gnl_check > 0)
	{
		if ((gnl_check = get_next_line(0, &line)) > 0)
		{
			if (ft_strstr(line, "Plateau"))
				ret = parse_map(env);
			if (ft_strstr(line, "Piece"))
				ret = parse_piece(env);
			if (ft_strstr(line, "== O fin"))
			{
				env->end = 1;
				gnl_check = 0;
			}
			ft_strdel(&line);
		}
		else if (gnl_check < 0)
			return (-1);
	}
	return (0);
}

int	main(void)
{
	t_filler	env;

	ft_bzero(&env, sizeof(t_filler));
	if ((env.fd_log = fopen("/Users/hde-ghel/Desktop/repo_19/filler/filler_log", "w")) < 0)
		return (-1);
	if (get_player(&env) == -1)
		return (-1);
	while (env.end == 0)
	{
		if (read_vm(&env) == -1)
			return (-1);

	}

	/*
	while (42)
	{

	}
	*/
	return (0);
}
