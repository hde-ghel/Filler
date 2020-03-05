/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 21:59:18 by hde-ghel          #+#    #+#             */
/*   Updated: 2020/03/03 21:23:48 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int				free_tab(char **tab, char *str)
{
	int		i;

	i = 0;
	if (str)
		ft_strdel(&str);
	if (tab)
	{
		while (tab[i] != NULL)
		{
			ft_strdel(&tab[i]);
			i++;
		}
		free(tab);
	}
	return (-1);
}

int				free_all(t_filler *env)
{
	free_tab(env->map, NULL);
	free_tab(env->old_map, NULL);
	free_tab(env->piece, NULL);
	return (-1);
}

t_list_filler	*free_list(t_list_filler *list)
{
	t_list_filler	*tmp;

	while (list != NULL)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	return (NULL);
}
