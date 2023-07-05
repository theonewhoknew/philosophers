#include "../inc/philo.h"
#include <stdio.h>

int main(int argc, char **argv)
{	
	t_philo	philo;

	if (check_args(argc, argv) == 1)
		return (0);
	init_struct(argc, argv, &philo);
	simulation(&philo);
}