/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 01:21:23 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/04 01:21:45 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long			ft_atol(const char *str)
{
	long	n;
	int		isneg;

	isneg = 0;
	n = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		isneg = 1;
		str++;
	}
	while (*str && ft_isdigit(*str))
		n = n * 10 + (*str++ - '0');
	if (isneg)
		return (-n);
	else
		return (n);
}
