/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 23:00:30 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/30 23:01:37 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdelall(t_list *lst)
{
	if (!lst)
		return ;
	if (lst->next)
		ft_lstdelall(lst->next);
	free(lst->content);
	free(lst);
}
