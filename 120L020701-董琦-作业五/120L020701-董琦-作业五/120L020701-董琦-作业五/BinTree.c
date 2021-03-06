#define _CRT_SECURE_NO_WARNINGS
#include "BinTree.h"
#include <stdlib.h>
#include <stdio.h>
BinTree MakeEmpty(BinTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}
int Find(ElementType X, BinTree T)  //返回比较的次数，若成功为正值，若失败返回相反数
{
	if (T == NULL)
		return 0; //树为空，不需比较
	else
	{
		Position CurNode;//当前节点
		CurNode = T;
		int Count = 0;  
		while (CurNode != NULL)
		{
			Count++;//比较次数加一
			if (X < CurNode->Element)
				CurNode = CurNode->Left;
			else if (X > CurNode->Element)
				CurNode = CurNode->Right;
			else return Count;  //查找成功
		}
		return Count * (-1);//查找失败
	}
}
Position FindMin(BinTree T)
{
	if (T == NULL)
		return NULL;
	else if (T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);
}
Position FindMax(BinTree T)
{
	if (T == NULL)
		return NULL;
	else if (T->Right == NULL)
		return T;
	else
		return FindMax(T->Right);
}
BinTree Insert(ElementType X, BinTree T) 
{
	if (T == NULL)
	{
		T = malloc(sizeof(struct TreeNode));
		if (T == NULL)
		{
			printf("out of space!");
			exit(1);
		}
		else
		{
			T->Element = X;
			T->Left = T->Right = NULL;
		}
	}
	else if (X < T->Element)
		T->Left = Insert(X, T->Left);
	else if (X > T->Element)
		T->Right = Insert(X, T->Right);
	return T;
}
BinTree Delete(ElementType X, BinTree T)
{
	Position TmpCell;
	if (T == NULL)
	{
		printf("no such element");
		return T;
	}
	else if (X < T->Element)
		T->Left = Delete(X, T->Left);
	else if (X > T->Element)
		T->Right = Delete(X, T->Right);
	else if (T->Left && T->Right)
	{
		TmpCell = FindMin(T->Right);
		T->Element = TmpCell->Element;
		T->Right = Delete(T->Element, T->Right);
	}
	else
	{
		TmpCell = T;
		if (T->Left == NULL)
			T = T->Right;
		else if (T->Right == NULL)
			T = T->Left;
		free(TmpCell);
	}
	return T;
}
void Visit(Position P)
{
	if (P != NULL)
	{
		printf("%d\t", P->Element);
	}
}
void MidVisit(BinTree T)
{
	if (T != NULL)
	{
		MidVisit(T->Left);
		Visit(T);
		MidVisit(T->Right);
	}
}
BinTree BuildTree(ElementType* Data,int Size)
{
	BinTree Tree=NULL;
	int i;
	for (i = 0; i < Size; i++)
	{
		Tree = Insert(Data[i], Tree);
	}
	return Tree;
}