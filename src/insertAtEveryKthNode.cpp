/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/
int getCount(struct node *head);
int insert_any(struct node *head, int pos, int data_value);
#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K)
{
	int length = getCount(head);
	if (head == NULL || K <= 0)
		return NULL;
	else
	{
		int temp = K;
		int value = K;
		length = 2 * length;
		while (K<length)
		{
			int result = insert_any(head,K, value);
			if (result == 0)
				break;
			else
				K = temp + K + 1;
		}
	}
	return head;
}
int getCount(struct node *head)
{
	int count = 0;
	struct node *ptr = head;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	return count;
}

int insert_any(struct node *head,int pos, int data_value)
{
	int flag;
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	pos--;
	struct node *new_node = head;
	while (pos != 0)
	{
		new_node = new_node->next;
		if (new_node == NULL)
		{
			printf("\nList is not upto the position\n");
			flag = 0;
			return flag;
			break;
		}
		pos--;
	}
	temp->num = data_value;
	temp->next = new_node->next;
	new_node->next = temp;
}
