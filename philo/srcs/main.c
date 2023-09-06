/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:51:15 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/09/06 09:18:17 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (check_args(argc, argv) == 1)
	{
		write(2, "Argument error.\n", 17);
		return (1);
	}
	init_struct(argc, argv, &philo);
	if (allocate_struct(&philo) == 1)
		return (1);
	simulation(&philo);
	free_struct(&philo);
}
