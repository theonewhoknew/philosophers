/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:19:27 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/26 16:38:31 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>

static int  check_start(t_philo *p)
{
	int i;

	i = 0;
	while (i < p->n)
	{
		if (p->ready[i])
			i++;
		else
			return (0);
	}
	return (1);
}

void	*super_routine(void *arg)
{
	int		i;
	int		c;
	t_philo	*p;

	p = (t_philo *)arg;
/* 	while (check_start(p) == 0)
		continue ; */
//	p->s_t = get_start_time();
//	p->start = 1;
	if (p->opt == 1)
	{
		while (p->death != 1 && p->all_have_eaten != 1)
		{	
			c = 0;
			i = 0;
			while (i < p->n && p->death != 1)
			{
				if (p->eaten_enough[i] == 1)
					++c;
				i++;
			}
			if (c == p->n)
				p->all_have_eaten = 1;
		}
	}
	return (NULL);
}
