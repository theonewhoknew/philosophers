/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:51:39 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/07/19 10:19:50 by theonewhokn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>

void	run_philo(t_philo *philo, int id)
{	
	int delay;

	delay = 0;
	philo->ready[id - 1] = 1;
	while (philo->start != 1)
		;
	while (philo->death != 1 && philo->all_have_eaten != 1)
	{
		if (p_think(philo, id, &delay) == 1)
			return ;
		if (p_eat(philo, id) == 1)
			return ;
		if (p_sleep(philo, id) == 1)
			return ;
	}
}