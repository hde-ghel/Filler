/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 12:30:43 by hde-ghel          #+#    #+#             */
/*   Updated: 2020/02/11 13:12:10 by hde-ghel         ###   ########.fr       */
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
	while (ft_isdigit(line[i]))
		i++;
	size.x = ft_atoi(&line[i]);
	return (size);
}

int		skip_tomap(char *str)
{
	int		i;

	i = 0;
	while(ft_isdigit(str[i]))
		i++;
	return (i + 1);
}

int		map_allocation(t_filler *env, char *line)
{
	t_xy	count;
	char	*tmp;

	count.y = 0;
	env->c_map = check_size(env, line);
	if (get_next_line(0, &tmp) < 0) //SKIP 0123456
		return (-1);
	ft_strdel(&tmp);
	if (!(env->map = (char **)malloc(sizeof(char *) * (env->c_map.y + 1))))
		return (-1);
	while (count.y < env->c_map.y)
	{
		if (get_next_line(0, &tmp) < 0)
			return (-1);//FREE MAP
		env->map[count.y++] = ft_strdup(tmp + skip_tomap(tmp));//Protectio + free
		ft_strdel(&tmp);
	}
	env->map[count.y] = NULL;
	//print_fd
	print_map_info(env);
	return (0);
}

int		piece_allocation(t_filler *env)
{
	char	*tmp;
	int		count;

	count = 0;
	if (get_next_line(0, &tmp) < 0)
		return (-1);
	env->c_piece = check_size(env, tmp);
	ft_strdel(&tmp);
	if (!(env->piece = (char **)malloc(sizeof(char *) * (env->c_piece.y + 1))))
		return (-1);
	while (count < env->c_piece.y)
	{
		if (get_next_line(0, &tmp) < 0)
			return (-1);//FREE TAB + FREE MAP
		env->piece[count++] = ft_strdup(tmp);//Protection
		ft_strdel(&tmp);
	}
	env->piece[count] = NULL;
	//print_fd
	print_piece_info(env);
	return (0);
}
