/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:21:28 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/26 16:13:15 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

static void	philo_died(t_philo *p, int id)
{
	p->death = 1;
	printf("%llu %d died\n", get_time(p), id);
	release_all(p);
	return ;
}

void	timer(t_philo *p, int id)
{
	uint64_t	last_meal_time;
	uint64_t	elapsed;

	last_meal_time = get_time(p);
	while (p->death != 1 && p->all_have_eaten != 1)
	{
		while (!p->eating[id - 1] && !p->all_have_eaten
			&& !p->death)
		{
			elapsed = get_time(p) - last_meal_time;
			if (elapsed > p->tdie)
				return (philo_died(p, id));
			ft_usleep(1);
		}
		if (p->eating[id - 1])
			last_meal_time = get_time(p);
		while (p->eating[id - 1] && !p->all_have_eaten
			&& !p->death)
		{
			elapsed = get_time(p) - last_meal_time;
			if (elapsed > p->tdie)
				return (philo_died(p, id));
			ft_usleep(1);
		}
	}
	release_all(p);
}
