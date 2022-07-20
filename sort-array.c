/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort-array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:02:34 by jmorneau          #+#    #+#             */
/*   Updated: 2022/07/20 17:24:35 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

int sortarray3(t_node **head, t_node *headB, bool printsort) //
{
	int nb_movements;

	nb_movements = 0;
	while (checkifsorted(*head) == false)
	{
		if ((*head)->next->next != NULL && (*head)->value > (*head)->next->value && (*head)->value > (*head)->next->next->value)
			nb_movements += ra(head, headB);
		else if ((*head)->value > (*head)->next->value)
			nb_movements += sa(*head, headB);
		else if ((*head)->value < (*head)->next->value)
			nb_movements += rra(head, headB);
	}
	if (printsort)
		printf("Sorted. \nNombres d'actions : %d", nb_movements);
	return (nb_movements);
}

void sortarray5(t_node *headA, t_node *headB)
{
	int nb_movements;
	int middle;
	
	middle = sizeofchainedlist(headA) / 2; // assume for now 
	nb_movements = 0;
	while (sizeofchainedlist(headB) != middle)
	{
		if (headA->value <= middle)
		nb_movements +=	pb(&headA, &headB);
		else
			nb_movements += ra(&headA, headB);
	}
	nb_movements += sortarray3(&headA, headB, false);															// peut rajouter un ss ici
	nb_movements += sortarray3forBinverser(&headB, headA, false);
	nb_movements += pa(&headA, &headB);
	nb_movements += pa(&headA, &headB);
	nb_movements += pa(&headA, &headB);
	
	if (checkifsorted(headA))
		printf("Sorted. \nNombres d'actions : %d", nb_movements);
	else
		printf("error");
}

void sortarray(int argc, char **argv)
{
	t_node *headA;
	t_node *headB;

	headA = NULL;
	headB = NULL;

	printf("Init A and B \n");
	for (int i = 0; i < argc - 1; i++)
		insert_at_head(&headA, creat_new_node(ft_atoi(argv[i + 1])));

	printchainedboth(headA, headB);
	if (!checkifsorted(headA))
	{

		if (argc - 1 <= 3)
			sortarray3(&headA, headB, true);
		else if (argc - 1 <= 6)
			sortarray5(headA, headB);
		else
			return;
	}
	else
		printf("Sorted. \nNombres d'actions : %d", 0);
}