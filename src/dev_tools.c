/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 19:42:24 by hde-ghel          #+#    #+#             */
/*   Updated: 2020/02/09 19:55:08 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/filler.h"

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
