/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:30:55 by dabdygal          #+#    #+#             */
/*   Updated: 2023/12/11 16:39:55 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"

int	control_write(t_seat *seat, int status)
{
	if (lock_warn(&seat->cntrl->lock, &seat->print->lock) != 0)
		return (-1);
	seat->cntrl->status = status;
	if (unlock_warn(&seat->cntrl->lock, &seat->print->lock) != 0)
		return (-1);
	return (0);
}
