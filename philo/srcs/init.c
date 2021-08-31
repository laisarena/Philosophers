/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 11:56:31 by lfrasson          #+#    #+#             */
/*   Updated: 2021/08/30 21:03:41 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	initialize_forks(t_mutex **forks)
{
	while (*forks)
	{
		*forks = malloc(sizeof(t_mutex));
		pthread_mutex_init(*forks, NULL);
		forks++;
	}
}

static int	create_forks(t_param *param)
{
	int	size;

	size = param->number_of_philo;
	param->forks = malloc(sizeof(t_mutex *) * (size + 1));
	if (!param->forks)
		return (FAIL);
	param->forks[size] = NULL;
	initialize_forks(param->forks);
	return (SUCCESS);
}

int	initialize_structures(t_param *param)
{
	if (create_forks(param) == FAIL)
		return (FAIL);
	if (create_philos(param) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
