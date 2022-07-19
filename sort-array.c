/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort-array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:02:34 by jmorneau          #+#    #+#             */
/*   Updated: 2022/07/19 12:54:56 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"


void sortarray3(int argc, char **argv)
{
	t_node *head;
	int nb_movements;
		
	nb_movements = 0;
	head = NULL;
	for(int i = 0; i < argc - 1; i++)
	 	insert_at_head(&head, creat_new_node(ft_atoi(argv[i + 1])));

	while (checkifsorted(head) == false)
	{
		if (head->value > head->next->value)
		{
			printf("sa \n");
			sa(head);
		}
		else if (head->value < head->next->value)
		{
			printf("rra \n");
			rra(&head);
		}
		nb_movements++;
	}
	printchained(head);
	if(checkifsorted(head))
		printf("Sorted. \nNombres d'actions : %d", nb_movements);
}

void sortarray5(int argc, char **argv)
{
	t_node *head;
	int nb_movements;
		
	nb_movements = 0;
	head = NULL;
	for(int i = 0; i < argc - 1; i++)
	 	insert_at_head(&head, creat_new_node(ft_atoi(argv[i + 1])));

	while (checkifsorted(head) == false)
	{


		
	}

	printchained(head);
}

void sortarray(int argc, char **argv)
{
	if (argc - 1 <= 3)
		sortarray3(argc ,argv);	
	else if (argc - 1 <= 5 &&  argc - 1 >= 4)
		sortarray5(argc, argv);
	
	
}