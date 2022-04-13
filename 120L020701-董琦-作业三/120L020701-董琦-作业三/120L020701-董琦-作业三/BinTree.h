#ifndef ____BINTREE___
#define ____BINTREE___
struct  TreeNode;
#define  ElementType int
typedef struct TreeNode* PtrToTreeNode;
typedef PtrToTreeNode Position;
typedef PtrToTreeNode BinTree;

BinTree MakeEmpty(BinTree T);
BinTree Insert(ElementType X, BinTree T);
BinTree Delete(ElementType X, BinTree T);
Position Find(ElementType X, BinTree T);
Position FindMin(BinTree T);
Position FindMax(BinTree T);
void Visit(Position P);

struct  TreeNode
{
	ElementType Element;
	BinTree Left;
	BinTree Right;
};

#endif // !____BINTREE___
