/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_seats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:20:27 by dabdygal          #+#    #+#             */
/*   Updated: 2023/12/13 10:57:23 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <unistd.h>

static void	prep_seats(t_seat *seats, t_shared *common)
{
	int	i;

	i = 0;
	while (i < common->total)
	{
		(seats + i)->id = i + 1;
		(seats + i)->die_time = common->die_time;
		(seats + i)->eat_time = common->eat_time;
		(seats + i)->sleep_time = common->sleep_time;
		(seats + i)->must_eat = common->must_eat;
		(seats + i)->print = &common->print;
		(seats + i)->cntrl = &common->cntrl;
		(seats + i)->right_fork = common->forks + i;
		(seats + i)->state = sleeping;
		(seats + i)->prev_meal = 0;
		if (i < common->total - 1)
			(seats + i)->left_fork = common->forks + i + 1;
		else
			(seats + i)->left_fork = common->forks;
		i++;
	}
}

int	init_seats_clean(t_seat **seats, t_shared *common)
{
	*seats = (t_seat *) malloc(sizeof(t_seat) * common->total);
	if (*seats == NULL)
	{
		ft_putstr_fd("Failed to malloc seats\n", STDERR_FILENO);
		terminate_common_warn(common);
		return (-1);
	}
	prep_seats(*seats, common);
	return (0);
}
