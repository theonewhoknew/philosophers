#include "../inc/philo.h"
#include <stdio.h>

void	print_params(t_param *param)
{
	printf("number of philo: %d\n", param->n);
	printf("time to die: %d\n", param->tdie);
	printf("time to eat: %d\n", param->teat);
	printf("time to sleep: %d\n", param->tsleep);
}