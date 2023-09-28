/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:51:15 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/09/28 17:35:45 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{	
	t_param p;
	t_philo	*philo;

	if (check_args(argc, argv) == 1)
	{
		write(2, "Argument error.\n", 17);
		return (1);
	}
	init_params(argc, argv, &p);
	philo = init_philo(&p, philo);
	if (!philo)
		return (1);
	simulation(&p, philo);
}
