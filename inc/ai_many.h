#ifndef AI_MANY_H

# define AI_MANY_H

typedef struct	s_pos
{
	t_coord		coord;
	int			p_weight;
	int			s_weight;
}				t_pos;

t_list			*list_possible_position(t_params params);
#endif