#include <stdlib.h>
#include <stdio.h>

struct t_node 
{
	int value;
	struct t_node *next;
}; typedef struct t_node node;



node *creat_new_node(int value)
{
	node *tmp = malloc(sizeof(node));
	tmp->next = NULL;
	tmp->value = value;
	return (tmp);
}

void print_tmp(node *head)
{
	node *tmp = head;

	while (tmp != NULL)
	{
		printf("%d - ", tmp->value);
		tmp = tmp->next;
	}
}

node *find_node(int value, node *head)
{
	node *tmp = head;

	while (tmp != NULL)
	{
		if (tmp->value == value)
			return (tmp);
		tmp = tmp->next;
	}
	return NULL;

}

void insert_after(node *tmp1, node *newnode)
{
	newnode->next = tmp1->next;
	tmp1->next = newnode;
}



void insert(node **head, node *tmp)
{
		tmp->next = *head;
		*head = tmp;
}

int main()
{
	node *head = NULL;
	node *tmp = NULL;

	for (int i = 1; i <= 100; i++)
		insert(&head, creat_new_node(i));


	insert_after(find_node(13, head), creat_new_node(1110));

	print_tmp(head);
	return (0);


}
