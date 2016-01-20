/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/
struct node *insert_any(int pos, int data_value,struct node *head);
#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K)
{
	if (head == NULL || K <= 0)
		return NULL;
	else
	{
		int length=0;
		struct node *start = head;
		int temp = K;
		while (start != NULL)
		{
			length++;
			start = start->next;
		}
		while (K <= length)
		{
			head=insert_any(K, K,head);
			K = temp + K;
		}
	}
	return head;
}
struct node *insert_any(int pos, int data_value,struct node *start)
{
	int key;
	key = pos;

	pos--;
	struct node *temp = (struct node *)malloc(sizeof(struct node));

	//Traverse till pos
	struct node *ptr = start;
	while (pos != 0)
	{
		ptr = ptr->next;
		pos--;
	}
	temp->num = data_value;
	temp->next = ptr->next;
	ptr->next = temp;
	return start;
}