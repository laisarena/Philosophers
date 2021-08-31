/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:01:46 by lfrasson          #+#    #+#             */
/*   Updated: 2021/08/30 21:14:08 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_hands(t_philo *philo, t_mutex **forks)
{
	philo->hand.left = forks[philo->index - 1];
	philo->hand.right = forks[philo->index];
	if (philo->hand.right == NULL)
		philo->hand.right = forks[0];
}

static void	initialize_philos(t_param *param)
{
	int		index;
	int		size;
	t_philo	*philo;

	index = 0;
	size = param->number_of_philo;
	while (param->philos[index])
	{
		param->philos[index] = malloc(sizeof(t_philo));
		philo = param->philos[index];
		philo->index = index + 1;
		set_hands(philo, param->forks);
		index++;
	}
}

int	create_philos(t_param *param)
{
	int	size;

	size = param->number_of_philo;
	param->philos = malloc(sizeof(t_philo *) * (size + 1));
	if (!param->philos)
		return (FAIL);
	param->philos[size] = NULL;
	initialize_philos(param);
	return (SUCCESS);
}
