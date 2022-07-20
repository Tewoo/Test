/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actionsB.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:03:16 by jmorneau          #+#    #+#             */
/*   Updated: 2022/07/20 14:15:45 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

int sb(t_node *head, t_node *headB)
{
	printf ("sb \n");
	int first = head->value;
	head->value = head->next->value;
	head->next->value = first;
	printchainedboth(headB, head);
	return(1);
}

int rb(t_node **head, t_node *headB)
{
	t_node *tmp = *head;
	t_node *first = *head;

	printf ("rb \n");		
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
	printchainedboth(headB, *head);
	return(1);
}

int rrb(t_node **head, t_node *headB)
{
	t_node *tmp = *head;
	t_node *last = NULL;
		
	printf ("rrb \n");		
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
	printchainedboth(headB, *head);
	return(1);	
}

int pa(t_node **head2, t_node **head1)
{
	printf ("pa \n");		
	t_node *tmp = *head1;
	*head1 = (*head1)->next;
	tmp->next = *head2;
	*head2 = tmp;
	printchainedboth(*head2, *head1);
	return (1);
}
