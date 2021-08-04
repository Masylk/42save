#include "philosophers.h"

int	get_fork(t_vars *vars, int index)
{
	return (vars->forks[index % vars->nb]);
}

void	get_forks_back(t_vars *vars, int fl, int fr)
{
	vars->forks[fl % vars->nb] = 1;
	vars->forks[fr % vars->nb] = 1;
}

int	get_forks(t_vars *vars, int fl, int fr)
{
	if (get_fork(vars, fl) && get_fork(vars, fr))
	{
		vars->forks[fl % vars->nb] = 0;
		vars->forks[fr % vars->nb] = 0;
		return (1);
	}
	return (0);
}
