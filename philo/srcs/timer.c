/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:21:28 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/28 10:50:47 by dtome-pe         ###   ########.fr       */
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
	uint64_t	last;
	uint64_t	ela;

	while (!p->start)
		continue ;
	last = get_time(p);
	while (p->death != 1 && p->eaten != 1)
	{	
		while (!p->eating[id - 1])
		{
			ela = get_time(p) - last;
			if (ela > p->tdie)
				return (philo_died(p, id));
		}
		last = get_time(p);
		while (p->eating[id - 1])
		{
			ela = get_time(p) - last;
			if (ela > p->tdie)
				return (philo_died(p, id));
		}
	}
	release_all(p);
}
