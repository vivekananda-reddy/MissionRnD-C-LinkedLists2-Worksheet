/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
struct node* insert1(struct node**, struct node*, int);
struct node * insertAtEveryKthNode(struct node *head, int K) {
	struct node*temp = head;
	int i=K;
	if (head==NULL||K<1)
		return NULL;
	while (temp != NULL)
	{
		if (i > 1)
		{
			temp = temp->next;
			i--;
			continue;
		}
		temp=insert1(&head,temp,K);
		temp = temp->next;
		i = K;
	}
	return head;
}
struct node* insert1(struct node**head, struct node*temp, int K)
{
	struct node* x,*temp2=temp->next;
	x = (struct node*)malloc(sizeof(struct node*));
	x->num = K;
	temp->next = x;
	x->next = temp2;
	temp = temp->next;
	return temp;
}
