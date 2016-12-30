/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 05:31:58 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/30 05:35:32 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int		find_length(t_lemin *lemin, int *test_path, int pc)
{
	int x;
	int len;

	x = -1;
	len = 0;
	while (++x < pc)
		len += lemin->patharr[test_path[x]]->length;
	return (len);
}

void	copy_arr(int *dest, int *src, int len)
{
	while (len--)
		dest[len] = src[len];
}
