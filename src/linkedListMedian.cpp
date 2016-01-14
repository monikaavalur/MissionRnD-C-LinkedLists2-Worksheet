/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) 
{
	struct node *previous_node = head;
	struct node *current_node = head;
	//traversing the linked list to find the median of the linked list
	if (head != NULL)
	{
		while (current_node != NULL&&current_node->next != NULL)
		{
			current_node = current_node->next->next;
			previous_node = previous_node->next;
		}
	}
	return previous_node->num;
}
