/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:11:24 by jmorneau          #+#    #+#             */
/*   Updated: 2022/07/19 12:34:29 by jmorneau         ###   ########.fr       */
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
		printf("%d \n", temp->value);
		temp = temp->next;
	}
}

void printchainedboth(t_node *head1, t_node *head2)
{
	printchained(head1);
	printf("----------------------- \nSTACK A \n\n");
	printchained(head2);
	printf("----------------------- \nSTACK B \n\n");
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
