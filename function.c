#include "header.h"

void appendnode(node *head, int crt, int value)
{
	node *newnode = NULL;
	newnode = (node *)malloc(sizeof(node));
	newnode->value = value;
	for (int i = 0; i < crt; i++)
		head = head->next;
	head->next = newnode;
}
void deletenode(node *head, int n)
{
	node *crtnode = head;
	for (int i = 1; i < n; i++)
		crtnode = crtnode->next;
	node *temp = crtnode->next;
	crtnode->next = crtnode->next->next;
	free(temp);
}
int printvalue(node *head, int n)
{
	node *crtnode = head;
	for (int i = 0; i < n; i++)
		crtnode = crtnode->next;
	return crtnode->value;
}