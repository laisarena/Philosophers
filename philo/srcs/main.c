/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:25:04 by lfrasson          #+#    #+#             */
/*   Updated: 2021/08/29 19:04:34 by lfrasson         ###   ########.fr       */
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

int	create_philos(t_param *param)
{
	int	size;

	size = param->number_of_philo;
	param->philos = (t_philo *)malloc(sizeof(t_philo) * (size + 1));
	if (!param->forks)
		return (FAIL);
	ft_bzero(param->philos, sizeof(t_philo));
	return (SUCCESS);
}

int	create_forks(t_param *param)
{
	int	size;

	size = param->number_of_philo;
	param->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* (size + 1));
	if (!param->forks)
		return (FAIL);
	ft_bzero(param->forks, sizeof(pthread_mutex_t));
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
