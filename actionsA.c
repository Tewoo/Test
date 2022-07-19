/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actionsA.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:09:12 by jmorneau          #+#    #+#             */
/*   Updated: 2022/07/19 12:16:38 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

bool sa(t_node *head)
{
	int first = head->value;
	head->value = head->next->value;
	head->next->value = first;
	return(checkifsorted(head));
}

bool ra(t_node **head)
{
	t_node *tmp = *head;
	t_node *first = *head;
		
	*head = (*head)->next;
	while(tmp != NULL)
	{
		if (tmp->next == NULL)
		{
			tmp->next = first;
			first->next = NULL;
			break;	
		}
		tmp = tmp->next;
	}
	return(checkifsorted(*head));

}

bool rra(t_node **head)
{
	t_node *tmp = *head;
	t_node *last = NULL;
		
	while(tmp != NULL)
	{
		if (tmp->next->next == NULL)
		{
			last = tmp;
			tmp = tmp->next;
			last->next = NULL;
			break;			
		}
		tmp = tmp->next;
	}
	tmp->next = *head;
	*head = tmp;
	return(checkifsorted(*head));	
}

void pb(t_node **head1, t_node **head2)
{
	t_node *tmp = *head1;
	*head1 = (*head1)->next;
	tmp->next = *head2;
	*head2 = tmp;
}
