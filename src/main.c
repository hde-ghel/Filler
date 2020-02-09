/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:40:39 by hde-ghel          #+#    #+#             */
/*   Updated: 2020/02/09 19:56:52 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/filler.h"

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
	ft_putstr_fd("Player =", env->fd);
	ft_putchar_fd(env->player, env->fd);
	ft_putstr_fd("\n", env->fd);
	return (0);
}

int		play(t_filler *env, char *line)
{

	if (map_allocation(env, line) == -1)
		return (-1);
	if (!(piece_allocation(env)))
		return (-1);//FREE_MAP
	algo(env);
		//free_all();
	return (0);
}

int		read_vm(t_filler *env)
{
	int		gnl_check;
	char	*line;

	while ((gnl_check = get_next_line(0, &line)) > 0)
	{
		if (ft_strstr(line, "Plateau"))
			play(env, line);//PROTECTION
		ft_strdel(&line);
	}
	if (gnl_check < 0)
		return (-1);
	return (0);
}

int	main(void)
{
	t_filler	env;

	ft_bzero(&env, sizeof(t_filler));
	env.fd = open("/Users/hde-ghel/Desktop/repo_19/filler/log/log2", O_WRONLY);
	
	if (get_player(&env) == -1)
		return (-1);
	while (1)
	{
		if (read_vm(&env) == -1)
			return (-1);
	}
	close(env.fd);
	return (0);
}
