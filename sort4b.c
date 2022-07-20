/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:53:13 by jmorneau          #+#    #+#             */
/*   Updated: 2022/07/20 17:14:35 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

int sortarray3forB(t_node **head, t_node *headB, bool printsort) 
{
	int nb_movements;

	nb_movements = 0;
	if (headB == NULL)
		return (0);
	while (checkifsorted(*head) == false)
	{
		if ((*head)->next->next != NULL && (*head)->value > (*head)->next->value && (*head)->value > (*head)->next->next->value)
			nb_movements += rb(head, headB);
		else if ((*head)->value > (*head)->next->value)
			nb_movements += sb(*head, headB);
		else if ((*head)->value < (*head)->next->value)
			nb_movements += rrb(head, headB);
	}
	if (printsort)
		printf("Sorted. \nNombres d'actions : %d", nb_movements);
	return(nb_movements);
}

int sortarray3forBinverser(t_node **head, t_node *headB, bool printsort) 
{
	int nb_movements;

	nb_movements = 0;
	if (headB == NULL)
		return (0);
	while (checkifNOTsorted(*head) == false)
	{
		if ((*head)->next->next != NULL && (*head)->value < (*head)->next->value && (*head)->value < (*head)->next->next->value)
			nb_movements += rb(head, headB);
		else if ((*head)->value < (*head)->next->value)
			nb_movements += sb(*head, headB);
		else if ((*head)->value > (*head)->next->value)
			nb_movements += rrb(head, headB);
	}
	if (printsort)
		printf("Sorted. \nNombres d'actions : %d", nb_movements);
	return(nb_movements);
}