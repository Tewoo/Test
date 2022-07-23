/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:11:24 by jmorneau          #+#    #+#             */
/*   Updated: 2022/07/22 17:23:19 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"


void printchained (t_node *head)
{
	t_node *temp;
	
	temp = head;
	if (head == NULL)
	{
		printf("NULL \n");
		return ;
	}
	while (temp != NULL)
	{
		printf("\t%d\n", temp->value);
		temp = temp->next;
	}
}

void printchainedboth(t_node *head1, t_node *head2) // a improve >;-)
{
	t_node *temp;
	t_node *temp2;
	
	temp = head1;
	temp2 = head2;
	while (temp != NULL || temp2 != NULL)
	{		
		printf("\t\t");
		if (temp != NULL)
		{
			printf("%d", temp->value);
			temp = temp->next;
		}
		printf("\t\t\t");
		if (temp2 != NULL)
		{
			printf("%d", temp2->value);
			temp2 = temp2->next;
		}
		
		printf("\n");
	}
	printf("--------------- A \t--------------- B\n");
	printf("- - - - - - - - - - - - - - - - - - - - -\n");
}

t_node *creat_new_node(int value)
{
	t_node *result;
	result = malloc(sizeof(t_node));
	result->value = value;
	result->next = NULL;
	return (result);
}

void insert_at_head(t_node **head, t_node *node_to_insert)
{
	node_to_insert->next = *head;
	*head = node_to_insert;
}

void remove_after(t_node *node_to_delete, t_node **head)
{
	t_node *tmp = *head;
	if (tmp == node_to_delete)
		*head = (*head)->next;
	else
	{
		while (tmp != NULL)
		{
			if (tmp->next == node_to_delete)
				tmp->next = tmp->next->next;
			tmp = tmp->next;
		}
	}
	free(node_to_delete);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	signe;
	int	res;

	res = 0;
	signe = 1;
	i = 0;
	while ((str[i] > 8 && 14 > str[i]) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] > 47 && 58 > str[i])
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * signe);
}

bool checkifsorted(t_node *head)
{
	t_node *tmp;
	
	tmp = head;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (false);
		tmp = tmp->next;	
	}
	return (true);
}
bool checkifNOTsorted(t_node *head)
{
	t_node *tmp;
	
	tmp = head;
	while (tmp->next != NULL)
	{
		if (tmp->value < tmp->next->value)
			return (false);
		tmp = tmp->next;	
	}
	return (true);
}

int biggestNumber (t_node *headA)
{
	t_node *tmp;
	int value;

	value = 0;
	tmp = headA;
	while (tmp != NULL)
	{
		if (tmp->value > value)
			value = tmp->value;
		tmp = tmp->next;
	}	
	return (value);
}

int smallestNumber (t_node *headA)
{
	t_node *tmp;
	int value;

	value = 2147483647;
	tmp = headA;
	while (tmp != NULL)
	{
		if (tmp->value < value)
			value = tmp->value;
		tmp = tmp->next;
	}	
	return (value);
}

int sizeofchainedlist (t_node *headA)
{
	t_node *tmp;
	int value;

	value = 0;
	tmp = headA;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		value++;
	}
	return (value);
}

void freehead(t_node **head)
{
	t_node *tmp;
	
	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}

int lastvalue (t_node **head)
{
	t_node *tmp;

	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp->value);
}

int middlevalue (t_node *headA)
{
	t_node *tmp;
	int middlevalue = biggestNumber(headA);
	int i = 0;
	int ok = 1 + sizeofchainedlist(headA) / 2;
	if (sizeofchainedlist(headA) % 2 == 1)
		ok++;	

	while (1) // 
	{
		tmp = headA;
		while (tmp != NULL)
		{
			if (middlevalue == tmp->value)
				i++;
			tmp = tmp->next;
		}
		if (i == ok)
			break ;
		middlevalue--;
	}
	return (middlevalue); 
}
