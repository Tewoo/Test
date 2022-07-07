/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:15:27 by jmorneau          #+#    #+#             */
/*   Updated: 2022/07/07 15:34:22 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


struct node
{
	int value;
	struct node* next;
}; typedef struct node t_node;



void printchained (t_node *head)
{
	t_node *temp;
	
	temp = head;
	while (temp != NULL)
	{
		printf("%d \n", temp->value);
		temp = temp->next;
	}
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

t_node *find_node(int value, t_node *head)
{
	t_node *tmp = head;
	while (tmp != NULL)
	{
		if (tmp->value == value)
			return (tmp);
		tmp = tmp->next;
	}
	return NULL;
}

void insert_after(t_node *tmp1, t_node *newnode)
{
	newnode->next = tmp1->next;
	tmp1->next = newnode;
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

int main()
{
	
	t_node *head = NULL;	
	t_node *tmp;
	srand(time(NULL));

	for(int i = 0; i < 5; i++)
		//rand() % 500
		insert_at_head(&head, creat_new_node(i));


	tmp = find_node(1, head);
	remove_after(tmp, &head);


	printchained(head);
	printf("-------- \nSTACK A");
	return (0);
}