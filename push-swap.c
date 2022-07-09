/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:15:27 by jmorneau          #+#    #+#             */
/*   Updated: 2022/07/08 21:26:27 by jmorneau         ###   ########.fr       */
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

void insert_at_head(t_node **head, t_node *node_to_insert);
t_node *creat_new_node(int value);

void sa(t_node *head)
{
	printf ("sa \n");
	int first = head->value;
	head->value = head->next->value;
	head->next->value = first;
}

void sb(t_node *head)
{
	printf("sb \n");

	int first = head->value;
	head->value = head->next->value;
	head->next->value = first;
}

void ss(t_node *head1, t_node *head2)
{
	//printf("ss \n");
	sa(head1);
	sb(head2);
}

void ra(t_node **head)
{
	int value = (**head).value;
	t_node *new_node;
	
	t_node *tmp2 = *head;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	//tmp2->next = new_node;

	printf("%d - ", tmp2->value);
}

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

void printchainedboth(t_node *head1, t_node *head2)
{
	printchained(head1);
	printf("-------- \nSTACK A \n");
	printchained(head2);
	printf("-------- \nSTACK B \n");
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
	t_node *head2 = NULL;	
	t_node *tmp;
	srand(time(NULL));

	for(int i = 0; i < 5; i++)
		//rand() % 500
		insert_at_head(&head, creat_new_node(i));
		
	for(int i = 0; i < 5; i++)
		insert_at_head(&head2, creat_new_node(i));

	printchainedboth (head, head2);
	ra(&head);
	printchainedboth (head, head2);
	return (0);
}

