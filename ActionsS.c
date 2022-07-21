/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ActionsS.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:30:45 by jmorneau          #+#    #+#             */
/*   Updated: 2022/07/21 15:06:02 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

int ss(t_node *head, t_node *headB, int printss)
{
	if (head != NULL)
	{
		int first = head->value;
		head->value = head->next->value;
		head->next->value = first;
		if (printss != 0)
		{
			printf("ss \n");
			ss(headB, NULL, 0);
		}
		else
			return (1);
	}
	printchainedboth(head, headB);
	return (1);
}

int rr(t_node **head, t_node **headB, int printss)
{
	t_node *tmp = *head;
	t_node *first = *head;

	if (*head != NULL)
	{
		*head = (*head)->next;
		while (tmp != NULL)
		{
			if (tmp->next == NULL)
			{
				tmp->next = first;
				first->next = NULL;
				break;
			}
			tmp = tmp->next;
		}
		if (printss != 0)
		{
			printf("rr \n");
			rr(headB, NULL, 0);
		}
		else
			return (1);
	}
	printchainedboth(*head, *headB);
	return (1);
}

int rrr(t_node **head, t_node **headB, int printss)
{
	t_node *tmp = *head;
	t_node *last = NULL;

	if (*head != NULL)
	{
		while (tmp != NULL)
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
		if (printss != 0)
		{
			printf("rrr \n");
			rrr(headB, NULL, 0);
		}
		else
			return (1);
	}
	printchainedboth(*head, *headB);
	return (1);
}
