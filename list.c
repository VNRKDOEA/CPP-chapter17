/*list.c ֧����������ĺ���*/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*�ֲ�����ԭ��*/
static void CopyToNode(Item item, List pnode);

/*�ӿں���*/
/*����������Ϊ��*/
void InitializeList(List *plist)
{
	*plist = NULL;
}

/*�������Ϊ�գ�����true*/
bool ListIsEmpty(List *plist)
{
	if (*plist == NULL)
		return true;
	else
		return false;
}

/*�����������������true*/
bool ListIsFull(List *plist)
{
	Node * pt;
	bool full;
	pt = (Node *)malloc(sizeof(Node));
	if (pt = NULL)
		full = true;
	else
		full = false;
	free(pt);

	return full;
}

/*���ؽڵ������*/
unsigned int ListItemCount(const List *plist)
{
	unsigned int count = 0;
	Node * pnode = *plist; /*��������Ŀ�ʼ*/

	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next;
	}

	return count;
}

/*�����洢��Ľڵ㣬�������������plistָ�������ĩβ*/
bool AddItem(Item item, List *plist)
{
	Node * pnew;
	Node * scan = *plist;
	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
		return false;/*ʧ��ʱ�˳�����*/
	CopyToNode(item, pnew);
	pnew->next = NULL;
	
	if (scan == NULL)/*������*/
		*plist = pnew;/*pnew��������ͷ*/
	else
	{
		while (scan->next != NULL)
			scan = scan->next;/*�ҵ�����ĩβ*/
		scan->next = pnew;/*��pnew��ӵ�����ĩβ*/
	}
	return true;
}

/*����ÿ���ڵ㲢ִ��pfunָ��ĺ���*/
void Traverse(const List *plist, void(*pfun)(Item item))
{
	Node * pnode = *plist;

	while (pnode != NULL)
	{
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}

/*�ͷ���malloc()������ڴ�*/
/*��������ָ��ΪNULL*/
void EmptyTheList(List *plist)
{
	Node * psave;

	while (*plist != NULL)
	{
		psave = (*plist)->next;
		free(*plist);
		*plist = psave;
	}
}

/*�ֲ���������*/
/*��һ����Ŀ�������ڵ���*/
static void CopyToNode(Item item, List pnode)
{
	pnode->item = item;
}