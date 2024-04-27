/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:41:01 by afadouac          #+#    #+#             */
/*   Updated: 2023/11/18 00:55:15 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || !del)
		return ;
	del(lst->content);
	free(lst);
}

// void	del(void *ptr)
// {
// 	printf("%s\n", (char *) ptr);
// 	free(ptr);
// }
// int	main()
// {
// 	t_list	*head;

// 	head = ft_lstnew(ft_strdup("im heada"));
// 	ft_lstdelone(head, del);
// 	return (0);
// }