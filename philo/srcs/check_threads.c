/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:14:45 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/10/02 13:05:12 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>

static void	make_end(t_philo *ph, t_param *p, int i, int type)
{
	if (type == 1)
		print_state(&ph[i], DIE);
	else
		print_state(&ph[i], ITERS);
	pthread_mutex_lock(&(p->m_end));
	p->end = 1;
	pthread_mutex_unlock(&(p->m_end));
}

static int64_t	get_last(t_philo *ph, int i)
{
	int64_t	last;

	pthread_mutex_lock(&ph[i].m_last);
	last = ph[i].last;
	pthread_mutex_unlock(&ph[i].m_last);
	return (last);
}

void	check_threads(t_param *p, t_philo *ph)
{
	int		i;
	int		iters;
	int64_t	elapsed;
	int64_t	last;

	while (!p->end)
	{
		i = -1;
		while (++i < p->n)
		{
			last = get_last(ph, i);
			elapsed = get_time(p) - last;
			if (elapsed > p->tdie)
				make_end(ph, p, i, 1);
			pthread_mutex_lock(&ph[i].m_iters);
			iters = ph[i].iters;
			pthread_mutex_unlock(&ph[i].m_iters);
			if (p->max_iters > 0 && iters > p->max_iters)
				make_end(ph, p, i, 2);
		}
	}
	pthread_mutex_unlock(&p->m_end);
}
