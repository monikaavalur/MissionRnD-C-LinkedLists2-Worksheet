/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
struct node * reverse(struct node *new_node, struct node **head);
struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) 
{
	if (head == NULL)
		return 0;
	reverse(head, &head);
	return head;

}
struct node * reverse(struct node *new_node, struct node **head)
{

	if (new_node->next == 0)
	{
		*head = new_node;
		return new_node;
	}
	else
	{
		struct node *previous_node = reverse(new_node->next, head);
		previous_node->next = new_node;
		new_node->next = 0;
		return new_node;
	}

}



