/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node *newhead, *temp;
	if (head1 == NULL)
	{
		return head2;
	}
	else if (head2==NULL)
	{
		return head1;
	}
	if (head1->num > head2->num)
	{
		newhead = head2;
		head2 = head2->next;
	}
	else
	{
		newhead = head1;
		head1 = head1->next;
	}
	temp = newhead;
	while (1)
	{
		if (head1 == NULL)
		{
			temp->next = head2;
			break;
		}
		else if (head2 == NULL)
		{
			temp->next = head1;
			break;
		}
		else if (head1->num > head2->num)
		{
			temp->next = head2;
			temp = temp->next;
			head2 = head2->next;

		}
		else
		{
			temp->next = head1;
			temp = temp->next;
			head1 = head1->next;

		}
	}
	return newhead;
}
