/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:36:41 by lfrasson          #+#    #+#             */
/*   Updated: 2021/08/26 19:55:00 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <limits.h>
# include "utils.h"

# define TRUE	1
# define FALSE	0

typedef struct s_time
{
	int	to_die;
	int	to_eat;
	int	to_sleep;
}	t_time;

typedef struct s_param
{
	int		number_of_philosophers;
	int		must_eat;
	t_time	time;
}	t_param;

int	parse_input(int argc, char **argv, t_param *param);

#endif
