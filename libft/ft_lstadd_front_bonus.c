/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:40:03 by afadouac          #+#    #+#             */
/*   Updated: 2023/11/18 15:02:06 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*int main() {
	t_list *list = NULL;
	int data1 = 42;
	t_list *node1 = (t_list*)malloc(sizeof(t_list));
	node1->content = &data1;
	node1->next = NULL;
	
	int data2 = 24;
	t_list *node2 = (t_list*)malloc(sizeof(t_list));
	node2->content = &data2;
	node2->next = NULL;
	
	ft_lstadd_front(&list, node1);
	ft_lstadd_front(&list, node2);
	
	t_list *current = list;
	while (current != NULL) {
		printf("Content: %d\n", *(int*)(current->content));
		current = current->next;
	}
	free(node1);
	free(node2);
	
	return 0;
}*/