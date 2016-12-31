/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharp_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 22:21:57 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/30 22:38:40 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_wcharp_to_str(wchar_t *in)
{
	size_t	len;
	char	*ret;
	int		pos;

	len = ft_wcharp_len(in);
	ret = ft_strnew(len);
	pos = 0;
	while (*in)
	{
		ft_wchar_to_str(*in, ret + pos);
		pos += ft_wchar_len(*in);
		in++;
	}
	return (ret);
}
