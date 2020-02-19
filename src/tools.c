# include "../include/filler.h"

void		init_list(t_list_filler *list)
{
	list->coord_x = 0;
	list->coord_y = 0;
	list->max_x = 0;
	list->max_y = 0;
	list->min_x = 0;
	list->min_y = 0;
}

void		fill_list(t_filler *env, t_list_filler *list, t_xy m)
{
	list->coord_x = m.x;
	list->coord_y = m.y;
}
