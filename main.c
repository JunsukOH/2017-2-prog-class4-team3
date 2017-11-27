#include "header.h"

int main(void) 
{
	node *head = NULL;
	head = (node *)malloc(sizeof(node));
	int crt = 0;
	int n;
	int a;
	while (!feof(stdin))
	{
		if (crt == 0)
			printf("Create %dst node (Ctrl + Z to terminate) >> ", crt + 1);
		else if (crt == 1)
			printf("Create %dnd node (Ctrl + Z to terminate) >> ", crt + 1);
		else
			printf("Create %dth node (Ctrl + Z to terminate) >> ", crt + 1);
		scanf("%d", &n);
		appendnode(head, crt++, n); \
	}
	while (crt-- > 0)
	{
		printf("PressNumber ( 1 : Delete, 2 : Print Value, 3 : Terminate ) >> ");
		scanf("%d", &a);
		if (a == 1)
		{
			int n2;
			printf("Insert number to delete >> ");
			scanf("%d", &n2);
			deletenode(head, n2);
		}
		else if (a == 2)
		{
			int temp;
			printf("Insert number to print >> ");
			scanf("%d", &temp);
			printf("Result : %d \n", printvalue(head, temp));
		}
		else if (a == 3)
			exit(1);
	}
	return 0;
}