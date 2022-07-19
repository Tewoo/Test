/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:04:00 by jmorneau          #+#    #+#             */
/*   Updated: 2022/07/19 12:17:32 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


struct node
{
	int value;
	struct node* next;
}; typedef struct node t_node;


// ACTIONS


bool sa(t_node *head);
bool ra(t_node **head);
bool rra(t_node **head);
void pb(t_node **head1, t_node **head2);


// UTILES

void printchained (t_node *head);
void printchainedboth(t_node *head1, t_node *head2);
t_node *creat_new_node(int value);
void insert_at_head(t_node **head, t_node *node_to_insert);
void remove_after(t_node *node_to_delete, t_node **head);
int	ft_atoi(const char *str);
void sortarray(int argc, char **argv);
bool checkifsorted(t_node *head);