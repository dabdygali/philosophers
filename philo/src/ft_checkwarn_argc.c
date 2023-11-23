/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkwarn_argc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:53:56 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/23 15:20:35 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

/**
 * @brief Test and warns the arguments count.
 * @details Function test whether arguments count is within the range 
 * between \p min_argc and \p max_argc. If not within the range makes warning 
 * on standard error output.
 * @param argc Arguments counter.
 * @param min_argc Lower limit of the range of possible arguments count.
 * @param max_argc Upper limit of the range of possible arguments count.
 * @return Returns 0 if arguments count is not within the range or range
 * limits are not valid, -1 if function failed, otherwise returns 1.
*/
int	ft_checkwarn_argc(int argc, int min_argc, int max_argc)
{
	if (min_argc > max_argc || min_argc < 0 || max_argc < 0)
	{
		if (ft_putstr_fd("'min','max' are setup wrong\n", STDERR_FILENO) < 0)
			return (-1);
		return (0);
	}
	if (argc < min_argc)
	{
		if (ft_putstr_fd("Not enough arguments\n", STDERR_FILENO) < 0)
			return (-1);
		return (0);
	}
	if (argc > max_argc)
	{
		if (ft_putstr_fd("Too much arguments\n", STDERR_FILENO) < 0)
			return (-1);
		return (0);
	}
	return (1);
}
