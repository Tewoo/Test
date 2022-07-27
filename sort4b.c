/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:53:13 by jmorneau          #+#    #+#             */
/*   Updated: 2022/07/27 19:13:28 by jmorneau         ###   ########.fr       */
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

int sortarray100_2(t_node **headA, t_node **headB)
{
	int nb_movements;
	int middle;
	int i;
	int sizeofheadA;

	sizeofheadA = sizeofchainedlist(*headA) / 2;
	i = 0;
	middle = middlevalue(*headA);
	nb_movements = 0;

	while (sizeofchainedlist(*headA) != sizeofheadA + 1)
	{
		if ((*headA)->value <= middle)
			nb_movements += pb(headA, headB);
		else
			nb_movements += ra(headA, *headB);
	}
	return (nb_movements);
}

int sortarraybychunk(t_node **headA, t_node **headB, int i)
{
	int nb_movements;

	nb_movements = 0;
	while ((*headB)->next != NULL && i > 0)
	{

		if ((*headB)->next->value == biggestNumber(*headB)) // biggest number par chunk // ra + 1 ; rra - 1
			nb_movements += sb(*headB, *headA);
		else if (lastvalue(headB) == biggestNumber(*headB))
		{
			nb_movements += rrb(headB, *headA);
			i--;
		}
		else if ((*headB)->value == biggestNumber(*headB))
		{
			nb_movements += pa(headA, headB);
			i--;
			if ((*headA)->value > (*headA)->next->value)
				nb_movements += sa(*headA, *headB);
		}
		else
		{
			nb_movements += rb(headB, *headA);
			i++;
		}
	}
	if ((*headB)->next == NULL)
		nb_movements += pa(headA, headB);
	return (nb_movements);
}

int find_next(t_node **headA, t_node **headB, int i)
{
	int j = 0;
	t_node *tmp = *headA;

	while (tmp->value > i)
	{
		tmp = tmp->next;
		j++;
	}
	return (j);
}


int sort_headB(t_node **headA, t_node **headB)
{
	int nb_movements = 0;

	if (smallestNumber(*headA) < (*headB)->value)
		rb(headB, *headA);
	// else
	// 	rrb(headB, *headA);
	// if ((*headB)->next != NULL && (*headB)->value < (*headB)->next->value)
	// 	nb_movements +=	sb(*headB, *headA);
	
	
	return (nb_movements);

}

int hold_first(t_node **headA, t_node **headB, int taillelist, int nb_chunck)
{
	int i = 0;
	int j;
	int nb_movements = 0;
	int nb_pa = 0;

	while (i < (taillelist / 5))
	{
		j = 0;
		if ((*headA)->value <= nb_chunck)
		{
			if (*headB != NULL &&  smallestNumber(*headB) > (*headA)->value)
			{
				nb_movements += pb(headA, headB); // pourrait faire une truc du genre i += pb et return (nb_mouvements + i)
				nb_movements +=	rb(headB, *headA);
			}
			else
				nb_movements += pb(headA, headB);
			while (!checkifNOTsorted(*headB))
			{
				if ((*headB)->next != NULL && (*headB)->value < (*headB)->next->value)
					nb_movements +=	sb(*headB, *headA);
				if (!checkifNOTsorted(*headB))
				{
					nb_movements +=	pa(headA, headB);
					nb_pa++;
				}
			}
			while (nb_pa > 0)
			{
				nb_movements += pb(headA, headB);
				nb_pa--;
			}
			i++;
		}
		else
		{
			j = find_next(headA, headB, nb_chunck);
			if (j < taillelist / 2)
			{
				while (j-- > 0)
					nb_movements += ra(headA, *headB);
			}
			else
			{
				while (j-- > 0)
					nb_movements += rra(headA, *headB);
			}
		}
	}
	return (nb_movements);
}