/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:51:15 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/09/28 11:10:53 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{	
	t_param param;

	if (check_args(argc, argv) == 1)
	{
		write(2, "Argument error.\n", 17);
		return (1);
	}
	init_params(argc, argv, &param);
	if (allocate_struct(&p) == 1)
		return (1);
	simulation(&p);
	free_struct(&p);
}
