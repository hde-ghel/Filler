/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 19:42:24 by hde-ghel          #+#    #+#             */
/*   Updated: 2020/03/02 19:48:53 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/filler.h"

void		send_coord(t_filler *env)
{
	ft_putnbr(env->c_place.y);
	ft_putchar(' ');
	ft_putnbr(env->c_place.x);
	ft_putchar('\n');
/*
	ft_putstr_fd("\ncoord y = ", env->fd);
	ft_putnbr_fd(env->c_place.y, env->fd);
	ft_putstr_fd("\ncoord x = ", env->fd);
	ft_putnbr_fd(env->c_place.x, env->fd);
	ft_putstr_fd("\n", env->fd);
	*/
}

void		print_player(t_filler *env)
{
	ft_putstr_fd("Player = ", env->fd);
	ft_putchar_fd(env->player[1], env->fd);
	ft_putstr_fd("\nEnemy = ",env->fd);
	ft_putchar_fd(env->player[1], env->fd);
	ft_putstr_fd("\n", env->fd);
}

void	print_map_info(t_filler *env)
{
	int		i;

	i = 0;
	ft_putstr_fd("\nMAP info :\n", env->fd);
	ft_putstr_fd("size X = " ,env->fd);
	ft_putnbr_fd(env->c_map.x, env->fd);
	ft_putstr_fd("\nsize y = " ,env->fd);
	ft_putnbr_fd(env->c_map.y, env->fd);
	ft_putstr_fd("\n\n", env->fd);

	while (env->map[i])
	{
		ft_putnbr_fd(i, env->fd);
		ft_putstr_fd(" " ,env->fd);
		if (i < 10)
			ft_putstr_fd(" " ,env->fd);
		ft_putstr_fd(env->map[i++] ,env->fd);
		ft_putstr_fd("\n" ,env->fd);
	}
}
void	print_piece_info(t_filler *env)
{
	int		i;

	i = 0;
	ft_putstr_fd("\nPIECE info :\n", env->fd);
	ft_putstr_fd("size X = " ,env->fd);
	ft_putnbr_fd(env->c_piece.x, env->fd);
	ft_putstr_fd("\nsize y = " ,env->fd);
	ft_putnbr_fd(env->c_piece.y, env->fd);
	ft_putstr_fd("\n\n", env->fd);

	while (env->piece[i])
	{
		ft_putnbr_fd(i, env->fd);
		ft_putstr_fd(" " ,env->fd);
		ft_putstr_fd(env->piece[i++] ,env->fd);
		ft_putstr_fd("\n" ,env->fd);
	}
}

void		print_list(t_filler *env, t_list_filler *list)
{
	t_list_filler *tmp;
	int		i;

	i = 1;
	tmp = list;
	while (tmp != NULL)
	{
		ft_putstr_fd("\n\n LINK : \n\n " ,env->fd);
		ft_putnbr_fd(i, env->fd);

		ft_putstr_fd("\ncoord_x = " ,env->fd);
		ft_putnbr_fd(tmp->coord.x, env->fd);
		ft_putstr_fd("\ncoord_y = " ,env->fd);
		ft_putnbr_fd(tmp->coord.y, env->fd);
		ft_putstr_fd("\nmax_x.x = " ,env->fd);
		ft_putnbr_fd(tmp->max_x.x, env->fd);
		ft_putstr_fd("\nmax_x.y = " ,env->fd);
		ft_putnbr_fd(tmp->max_x.y, env->fd);
		ft_putstr_fd("\nmin_x.x = " ,env->fd);
		ft_putnbr_fd(tmp->min_x.x, env->fd);
		ft_putstr_fd("\nmin_x.y = " ,env->fd);
		ft_putnbr_fd(tmp->min_x.y, env->fd);

		ft_putstr_fd("\nmax_y.x = " ,env->fd);
		ft_putnbr_fd(tmp->max_y.x, env->fd);
		ft_putstr_fd("\nmax_y.y = " ,env->fd);
		ft_putnbr_fd(tmp->max_y.y, env->fd);
		ft_putstr_fd("\nmin_y.x = " ,env->fd);
		ft_putnbr_fd(tmp->min_y.x, env->fd);
		ft_putstr_fd("\nmin_y.y = " ,env->fd);
		ft_putnbr_fd(tmp->min_y.y, env->fd);
		i++;
		tmp = tmp->next;
	}
}
