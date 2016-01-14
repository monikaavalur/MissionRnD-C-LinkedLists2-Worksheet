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
	if (head == NULL )
		return NULL;
	if (head->next == NULL)
		return head->num;
	int length = 1;
	struct node *ptr1 = head;  // Will move 1 node frwd
	struct node *ptr2 = head;  // Will move 2 nodes frwd
	if (head != NULL)
	{
		head = head->next;
		length = length + 1;

	}
	printf("%d\n", length);
	if (length % 2 != 0)
	{
		// we don't need to check for ptr1. because ptr2 ahead of ptr1
		while (ptr2->next != NULL && ptr2->next->next != NULL)
		{
			ptr2 = ptr2->next->next;
			ptr1 = ptr1->next;
		}
		return ptr1->num;
	}
	if (length % 2 == 0)
	{
		while (ptr2->next != NULL && ptr2->next->next != NULL)
		{
			ptr2 = ptr2->next->next;
			ptr1 = ptr1->next;
		}
		int average = (ptr1->num + ptr1->next->num) / 2;
		return average;
	}


	}