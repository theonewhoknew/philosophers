/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:15:00 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/09/26 16:05:31 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	fill_eating(t_philo *p)
{
	int	i;

	i = 0;
	while (i < p->n)
	{
		p->eating[i] = 0;
		i++;
	}
}

void	fill_times_eaten(t_philo *p)
{
	int	i;

	i = 0;
	while (i < p->n)
	{
		p->times_eaten[i] = 0;
		i++;
	}
}

void	fill_eaten_enough(t_philo *p)
{
	int	i;

	i = 0;
	while (i < p->n)
	{
		p->eaten_enough[i] = 0;
		i++;
	}
}

void	fill_ready(t_philo *p)
{
	int	i;

	i = 0;
	while (i < p->n)
	{
		p->ready[i] = 0;
		i++;
	}
}
