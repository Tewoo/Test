/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actionsA.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:09:12 by jmorneau          #+#    #+#             */
/*   Updated: 2022/07/20 11:09:47 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

int sa(t_node *head, t_node *headB)
{
	printf ("sa \n");
	int first = head->value;
	head->value = head->next->value;
	head->next->value = first;
	printchainedboth(head, headB);
	return(1);
}

int ra(t_node **head, t_node *headB)
{
	t_node *tmp = *head;
	t_node *first = *head;

	printf ("ra \n");		
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
	printchainedboth(*head, headB);
	return(1);
}

int rra(t_node **head, t_node *headB)
{
	t_node *tmp = *head;
	t_node *last = NULL;
		
	printf ("rra \n");		
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
	printchainedboth(*head, headB);
	return(1);	
}

int pb(t_node **head1, t_node **head2)
{
	printf ("pb \n");		
	t_node *tmp = *head1;
	*head1 = (*head1)->next;
	tmp->next = *head2;
	*head2 = tmp;
	printchainedboth(*head1, *head2);
	return (1);
}
