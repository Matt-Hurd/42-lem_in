/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 19:17:17 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/30 22:31:08 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	ft_conv_ws(char in, t_output *out, t_arg *flags, va_list *ap)
{
	wchar_t *s;
	char	*str;

	(void)in;
	s = va_arg(*ap, wchar_t *);
	if (!s)
	{
		if (!flags->got_precis
			|| (flags->got_precis && flags->precision >= 6))
			str = ft_strdup("(null)");
		else
			str = ft_strdup("");
	}
	else
	{
		s = ft_wchardup(s);
		handle_precision((char **)&s, flags, 'w');
		str = ft_wcharp_to_str(s);
	}
	handle_padding(&str, flags, 'w');
	out->str = ft_strnjoin(out->str, out->len, str, ft_strlen(str));
	out->len += ft_strlen(str);
	free(str);
}

void		ft_conv_s(char in, t_output *out, t_arg *flags, va_list *ap)
{
	char *s;

	(void)in;
	if (flags->length == l || in == 'S')
	{
		ft_conv_ws(in, out, flags, ap);
		return ;
	}
	s = va_arg(*ap, char *);
	if (!s)
	{
		if (!flags->got_precis
			|| (flags->got_precis && flags->precision >= 6))
			s = ft_strdup("(null)");
		else
			s = ft_strdup("");
	}
	else
		s = ft_strdup(s);
	handle_precision(&s, flags, 's');
	handle_padding(&s, flags, 's');
	out->str = ft_strnjoinf(out->str, out->len, s, ft_strlen(s));
	out->len += ft_strlen(s);
	free(s);
}
