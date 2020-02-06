/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:40:39 by hde-ghel          #+#    #+#             */
/*   Updated: 2020/02/06 13:03:48 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void		check_player(t_filler *env)
{
	env->msize_x = 2;

}

void		first_run(t_filler *env)
{
	check_player(env);
	env->msize_x = 2;
}

int	main(void)
{
	t_filler	env;

	ft_bzero(&env, sizeof(t_filler));
	if ((env.fd_log = fopen("filler_log", "w")) < 0)
		return (-1);
	first_run(&env);
	/*
	while (42)
	{

	}
	*/
	fprintf(env.fd_log, "%s", "boudin\n");
	fprintf(env.fd_log, "%s", "boudin dfhdsfgsd\n");
	fprintf(env.fd_log, "%s", "boudindfgj \n");
	return (0);
}
