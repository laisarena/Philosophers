/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:25:04 by lfrasson          #+#    #+#             */
/*   Updated: 2021/08/28 21:41:42 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_forks(t_param *param)
{
	int	size;

	size = param->number_of_philo;
	param->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * size);
	if (!param->forks)
		return (FAIL);	
	return (SUCCESS);
}

int	initialize_structures(t_param *param)
{
	create_forks(param);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_param	param;
	int		status;

	status = parse_input(argc, argv, &param);
	if (status == FAIL)
		return (status);
	initialize_structures(&param);
	//start_routine();
	//
	return (SUCCESS);
}
