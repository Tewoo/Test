/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:53:13 by jmorneau          #+#    #+#             */
/*   Updated: 2022/07/23 15:22:36 by jmorneau         ###   ########.fr       */
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
	return (nb_movements);
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
	return (nb_movements);
}

int testjspgros(t_node **head)
{
	if ((*head)->next->next != NULL && (*head)->value > (*head)->next->value && (*head)->value > (*head)->next->next->value)
		return (10);
	else if ((*head)->value > (*head)->next->value)
		return (1);
	else if ((*head)->value < (*head)->next->value)
		return (100);
	return (0);
}

int testjspgros2(t_node **head)
{
	if ((*head)->next->next != NULL && (*head)->value < (*head)->next->value && (*head)->value < (*head)->next->next->value)
		return (10);
	else if ((*head)->value < (*head)->next->value)
		return (1);
	else if ((*head)->value > (*head)->next->value)
		return (100);
	return (0);
}

int sortarray3only1(t_node **head, t_node *headB)
{
	if (!checkifsorted(*head))
	{
		if ((*head)->next->next != NULL && (*head)->value > (*head)->next->value && (*head)->value > (*head)->next->next->value)
			ra(head, headB);
		else if ((*head)->value > (*head)->next->value)
			sa(*head, headB);
		else if ((*head)->value < (*head)->next->value)
			rra(head, headB);
		return (1);
	}
	return (0);
}

int sortarray3only1inverse(t_node **head, t_node *headB)
{
	if (!checkifNOTsorted(*head))
	{
		if ((*head)->next->next != NULL && (*head)->value < (*head)->next->value && (*head)->value < (*head)->next->next->value)
			rb(head, headB);
		else if ((*head)->value < (*head)->next->value)
			sb(*head, headB);
		else if ((*head)->value > (*head)->next->value)
			rrb(head, headB);
		return (1);
	}
	return (0);
}

int sortarray3test(t_node **headA, t_node **headB)
{
	int nb_movements;

	nb_movements = 0;
	while (checkifsorted(*headA) == false || checkifNOTsorted(*headB) == false)
	{

		if (testjspgros(headA) + testjspgros2(headB) == 2 && checkifsorted(*headA) == false && checkifNOTsorted(*headB) == false)
			nb_movements += ss(*headA, *headB, 1);
		else if (testjspgros(headA) + testjspgros2(headB) == 20 && checkifsorted(*headA) == false && checkifNOTsorted(*headB) == false)
			nb_movements += rr(headA, headB, 1);
		else if (testjspgros(headA) + testjspgros2(headB) == 200 && checkifsorted(*headA) == false && checkifNOTsorted(*headB) == false)
			nb_movements += rrr(headA, headB, 1);
		else
		{
			nb_movements += sortarray3only1(headA, *headB);
			nb_movements += sortarray3only1inverse(headB, *headA);
		}
	}
	return (nb_movements);
}

void sortarray100forB(t_node **headA, t_node **headB)
{
	int nb_movements;
	int middle;
	int i;
	int sizeofheadA;
	
	sizeofheadA = sizeofchainedlist(*headB) / 2;
	i = 0;
	middle = middlevalue(*headB); 
	nb_movements = 0;



	while (i != sizeofheadA + 1)
	{
		printf("%d", middle);
		if ((*headB)->value > middle)
		{
			nb_movements +=	pa(headA, headB);
			if ((*headA)->value > (*headA)->next->value)
				sa(*headA, *headB);
			i++;
		}
		else if (lastvalue(headA) > middle)
			nb_movements += rrb(headB, *headA);
		else
			nb_movements += rb(headB, *headA);

	}
	sortarray3forBinverser(headB, *headA, false);
	while (*headB != NULL)
		pa(headA, headB);
		

	// while (*headB != NULL)
	// {
	// 	if ((*headB)->next == NULL)
	// 	{
	// 		pa(headA, headB) ;
	// 		break ;
	// 	}
	// 	else if ((*headB)->next->next != NULL && (*headB)->value > (*headB)->next->value && (*headB)->value < (*headB)->next->next->value)
	// 		rb(headB, *headA);
	// 	else if ((*headB)->value < (*headB)->next->value)
	// 		sb(*headB, *headA);
	// 	else
	// 		pa(headA, headB);
	// }	
}
