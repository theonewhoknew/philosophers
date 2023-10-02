/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:12:59 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/10/02 13:10:05 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>

void	print_params(t_param *param)
{
	printf("number of philo: %d\n", param->n);
	printf("time to die: %d\n", param->tdie);
	printf("time to eat: %d\n", param->teat);
	printf("time to sleep: %d\n", param->tsleep);
}

static void	print_aux(int64_t ms, int id, char *str)
{
	printf("%llu %d %s\n", ms, id, str);
}

void	print_state(t_philo *philo, int type)
{	
	int	end;

	end = 0;
	pthread_mutex_lock(&(philo->par->m_end));
	if (philo->par->end)
		end = 1;
	pthread_mutex_unlock(&(philo->par->m_end));
	pthread_mutex_lock(&(philo->par->m_print));
	if (!end && type == EAT)
		print_aux(get_time(philo->par), philo->id + 1, " is eating");
	else if (!end && type == SLEEP)
		print_aux(get_time(philo->par), philo->id + 1, " is sleeping");
	else if (!end && type == THINK)
		print_aux(get_time(philo->par), philo->id + 1, " is thinking");
	else if (!end && type == FORK)
		print_aux(get_time(philo->par), philo->id + 1, " has taken a fork");
	else if (!end && type == DIE)
		print_aux(get_time(philo->par), philo->id + 1, " has died");
	else if (!end && type == ITERS)
		printf("All philosophers have eaten enough!\n");
	else if (!end && type == DEBUG)
		print_aux(get_time(philo->par), philo->id + 1, " is here");
	pthread_mutex_unlock(&(philo->par->m_print));
}
