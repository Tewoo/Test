/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:04:00 by jmorneau          #+#    #+#             */
/*   Updated: 2022/07/27 14:14:01 by jmorneau         ###   ########.fr       */
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


int sa(t_node *head, t_node *headB);
int ra(t_node **head, t_node *headB);
int rra(t_node **head, t_node *headB);
int pb(t_node **head1, t_node **head2);

int sb(t_node *head, t_node *headB);
int rb(t_node **head, t_node *headB);
int rrb(t_node **head, t_node *headB);
int pa(t_node **head1, t_node **head2);

int ss(t_node *head, t_node *headB, int printss);
int rr(t_node **head, t_node **headB, int printss);
int rrr(t_node **head, t_node **headB, int printss);

// UTILES

void printchained (t_node *head);
void printchainedboth(t_node *head1, t_node *head2);
t_node *creat_new_node(int value);
void insert_at_head(t_node **head, t_node *node_to_insert);
void remove_after(t_node *node_to_delete, t_node **head);
int	ft_atoi(const char *str);
void sortarray(int argc, char **argv);
bool checkifsorted(t_node *head);
int sortarray3forB(t_node **head, t_node *headB, bool printsort);
int biggestNumber (t_node *headA);
int smallestNumber (t_node *headA);
int sortarray3forBinverser(t_node **head, t_node *headB, bool printsort);
int sizeofchainedlist (t_node *headA);
bool checkifNOTsorted(t_node *head);
int sortarray3(t_node **head, t_node *headB, bool printsort);
int sortarray3test(t_node **headA, t_node **headB);
void freehead(t_node **head);
int lastvalue (t_node **head);
int middlevalue (t_node *headA);
void sortarray100forB(t_node **headA, t_node **headB);
int sortarray100_2(t_node **headA, t_node **headB);
int calcluechunck(t_node **headA, int sizeofheadA);
int sortarraybychunk(t_node **headA, t_node **headB, int i);
int hold_first(t_node **headA, t_node **headB, int taillelist, int nb_chunck);
int sort_headA(t_node **headA, t_node **headB);
