/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 22:55:29 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/30 22:31:15 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	handle_wchar_precision(wchar_t **str, t_arg *flags)
{
	size_t	curr_len;
	int		count;

	if (ft_wcharp_len(*str) <= flags->precision)
		return ;
	curr_len = 0;
	count = 0;
	while ((*str)[count] && curr_len <= flags->precision)
		curr_len += ft_wchar_len((*str)[count++]);
	(*str)[count - 1] = 0;
}

static void	digit_precision(char **str, t_arg *flags, char type)
{
	char	*n;
	char	alt;
	char	*orig;

	orig = *str;
	flags->pad_zeroes = 0;
	if (ft_strlen(*str) > flags->precision)
		return ;
	alt = (!ft_isalnum((*str)[0]) && type == 'd') ? (*str)[0] : 0;
	if (alt)
		(*str)++;
	n = ft_strnew(flags->precision + !!alt);
	ft_memset(n + !!alt, '0', flags->precision - ft_strlen(*str));
	ft_strcpy(n + flags->precision - ft_strlen(*str) + !!alt, *str);
	if (alt)
		n[0] = alt;
	free(orig);
	*str = n;
}

void		handle_precision(char **str, t_arg *flags, char type)
{
	if (!flags->got_precis)
		return ;
	if (type == 'w')
		handle_wchar_precision((wchar_t **)str, flags);
	else if (type == 's')
	{
		if (ft_strlen(*str) <= flags->precision)
			return ;
		(*str)[flags->precision] = 0;
	}
	else if (type == 'd' || type == 'u')
		digit_precision(str, flags, type);
}
