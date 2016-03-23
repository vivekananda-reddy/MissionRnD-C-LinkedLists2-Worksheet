/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	struct node *templast = head, *traverse,*temp;
	int index = 0;
	if (head == NULL)
	{
		return NULL;
	}
	while (templast->next != NULL)
	{
		templast = templast->next;
		index++;

	}
	temp = templast;
	while (temp!= head)
	{
		for (traverse = head; traverse->next != temp; traverse = traverse->next);
		temp->next = traverse;
		temp = traverse;

	}
	temp->next = NULL;
	head = templast;
	return head;


}
