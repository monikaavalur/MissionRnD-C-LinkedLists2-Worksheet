/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>

struct node {
	int num;
	struct node *next;
};
struct node *insert(struct node *start, int data);
struct node * merge2LinkedLists(struct node *head1, struct node *head2) 
{
	if (head1 == NULL && head2 == NULL)
		return NULL;
	struct node *list3;//creating a new list and assigning null to it
	list3 = NULL;
	//loop to merge the two lists
	while (head1 != NULL && head2 != NULL)
	{
		//assigning the numbers to list3 by checking the different conditoins below
		if (head1->num < head2->num)
		{
			list3 = insert(list3, head1->num);
			head1 = head1->next;
		}
		else if (head2->num < head1->num)
		{
			list3 = insert(list3, head2->num);
			head2 = head2->next;
		}
		else if (head1->num == head2->num)
		{
			list3 = insert(list3, head1->num);
			head1 = head1->next;
			head2 = head2->next;
		}
	}
	//If second list has finished and elements left in first list
	while (head1 != NULL)
	{
		list3 = insert(list3, head1->num);
		head1 = head1->next;
	}
	//If first list has finished and elements left in second list
	while (head2 != NULL)
	{
		list3 = insert(list3, head2->num);
		head2 = head2->next;
	}
	return list3;
}
struct node *insert(struct node *start, int data)
{
	struct node *list, *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->num = data;
	//If list is empty
	if (start == NULL)
	{
		temp->next = start;
		start = temp;
		return start;
	}
	else    //Insert at the end of the list
	{
		list = start;
		while (list->next != NULL)
			list = list->next;
		temp->next = list->next;
		list->next = temp;
	}
	return start;
}//End of insert()
