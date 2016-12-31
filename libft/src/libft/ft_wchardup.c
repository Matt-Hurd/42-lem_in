/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchardup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 22:20:09 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/30 22:20:34 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

wchar_t		*ft_wchardup(wchar_t *in)
{
	wchar_t *ret;
	size_t	count;
	size_t	i;

	count = 0;
	while (in[count])
		count++;
	ret = (wchar_t *)ft_memalloc(sizeof(wchar_t) * (count + 1));
	i = 0;
	while (i < count)
	{
		ret[i] = in[i];
		i++;
	}
	return (ret);
}
