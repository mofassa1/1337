/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:43:12 by afadouac          #+#    #+#             */
/*   Updated: 2023/11/18 14:51:19 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new -> content = content;
	new->next = NULL;
	return (new);
}
// int main()
// {
// 	t_list *node;
// 	char content = 'b';
// 	node = ft_lstnew(content);
// 	if (!node)
// 		return 1;
// 	printf ("%c\n", node->content);
// 	printf("%s", node->next);
// }