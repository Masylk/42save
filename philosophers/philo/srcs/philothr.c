#include "philosophers.h"

void	*philo_life(void *args)
{
	t_vars	*vars;
	t_philo	*list;

	(void)list;
	vars = (t_vars *)args;
	list = vars->plist;
	//debug_philo(list);
	return (NULL);
}
