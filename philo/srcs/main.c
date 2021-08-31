/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:25:04 by lfrasson          #+#    #+#             */
/*   Updated: 2021/08/30 21:00:26 by lfrasson         ###   ########.fr       */
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
