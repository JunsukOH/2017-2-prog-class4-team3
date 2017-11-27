#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node *next;
};

typedef struct node LINK;

LINK* createNode(int data)
{
	LINK* cur;
	cur = (LINK *) malloc(sizeof(LINK));
	
	if(cur == NULL)
	{
		printf("error");
		return NULL;
	}
	
	cur->value = data;
	cur->next = NULL;
}

LINK* append(LINK* head, LINK* cur)
{
	LINK* nextNode = head;
	
	if (head == NULL)
	{
		head = cur;
		return head;
	}
	
	while (nextNode->next != NULL)
	{
		nextNode = nextNode->next;
	}
	
	nextNode->next = cur;
	
	return head;
}

int numberof(LINK* head)
{
	int cnt = 0;
	LINK* nextNode = head;
	
	while(nextNode != NULL)
	{
		nextNode = nextNode->next;
		cnt++;
	}
	
	return cnt;
}

LINK* invert(LINK *head)
{
	LINK *trail, *middle;
	middle = NULL;
 	while(head)
	{
		trail = middle;
		middle = head;
		head = head->next;
		middle->next = trail;
	}
	
	return middle;
}

LINK* middle(LINK *head, int number)
{
	int i = number/2;
	int cnt = 0;
	LINK* nextNode = head;
	
	while(nextNode != NULL)
	{
		if (cnt == i) printf("%d", nextNode->value);
		nextNode = nextNode->next;
		cnt++;
	}
}

void printlist(LINK* head)
{
	LINK* nextNode = head;
	
	while(nextNode != NULL)
	{
		printf("%d ", nextNode->value);
		nextNode = nextNode->next;
	}
}

LINK* odddelete(LINK* head)
{
	int cnt = 1;
	LINK* nextNode = head;
	LINK* even = NULL;
	LINK* cur;
	
	while(nextNode != NULL)
	{
		if (cnt%2 == 0)
		{
			cur = createNode(nextNode->value);
			even = append(even, cur);
		}
		nextNode = nextNode->next;
		cnt++;
	}
	
	return even;
}

int main()
{
	int number = 0;
	LINK* head = NULL;
	LINK* cur;
	
	printf("�������� �Է����ּ���. (Ctrl-Z�� ����) : ");
	while (scanf("%d", &number) != NULL)
	{
		cur = createNode(number);
		if(cur == NULL)
		{
			printf("error");
			exit(1);
		}
		head = append(head, cur);
	}
	printf("\n");
	
	int i = numberof(head);
	printf("�Է��� �ڷ��� ���� : %d", i);
	printf("\n\n"); 
	
	printf("�Է� �ڷḦ �Է� �������� ��� : ");
	head = invert(head);
	printlist(head);
	head = invert(head);
	printf("\n\n");
	
	printf("�Է� �ڷ��� �߰� ��ġ�� �ִ� �� : ");
	middle(head, i);
	printf("\n\n");
	
	printf("�Է� �ڷḦ �Է� ������ ��� : ");
	printlist(head);
	printf("\n\n");
	
	printf("�Է� �ڷῡ�� Ȧ�� ��° �ڷḦ ���� : ");
	head = odddelete(head);
	printlist(head);
	printf("\n");
	
	return 0;
}
