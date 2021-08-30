/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:25:04 by lfrasson          #+#    #+#             */
/*   Updated: 2021/08/30 11:26:21 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = s;
	while (n--)
		*ptr++ = 0;
}

void	set_hands(t_philo *philo, t_mutex **forks)
{
	philo->hand.left = forks[philo->index - 1];
	philo->hand.right = forks[philo->index];
	if (philo->hand.right == NULL)
		philo->hand.right = forks[0];
}

void	initialize_philos(t_param *param)
{
	int	index;
	int	size;
	t_philo	philo;
	
	index = 0;
	size = param->number_of_philo;
	while (index < size)
	{
		philo = param->philos[index];
		philo.index = index + 1;
		set_hands(&philo, param->forks);
		index++;
	}
}

int	create_philos(t_param *param)
{
	int	size;

	size = param->number_of_philo;
	param->philos = (t_philo *)malloc(sizeof(t_philo) * (size + 1));
	if (!param->forks)
		return (FAIL);
	ft_bzero(param->philos, sizeof(t_philo));
	initialize_philos(param);
	return (SUCCESS);
}

void	initialize_forks(t_mutex **forks)
{
	while (*forks)
	{
		*forks = malloc(sizeof(t_mutex));
		pthread_mutex_init(*forks, NULL);
		forks++;
	}
}

int	create_forks(t_param *param)
{
	int	size;

	size = param->number_of_philo;
	param->forks = malloc(sizeof(t_mutex *) * (size + 1));
	if (!param->forks)
		return (FAIL);
	param->forks[size] = NULL;
	initialize_forks(param->forks);
	//ft_bzero(param->forks, sizeof(pthread_mutex_t));
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

void	free_structures(t_param *param)
{
	if (param->philos)
		free(param->philos);
	if (param->forks)
		free(param->forks);
}

int	main(int argc, char **argv)
{
	t_param	param;
	int		status;

	ft_bzero(&param, sizeof(t_param));
	status = parse_input(argc, argv, &param);
	if (status == FAIL)
		return (status);
	initialize_structures(&param);
	//start_routine();
	//
	free_structures(&param);
	return (SUCCESS);
}
