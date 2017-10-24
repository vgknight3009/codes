// Level order traversal of K-ary tree
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
typedef struct TreeNode
{
	int data;
	struct TreeNode **children;
} TreeNode;
 
typedef struct ListNode
{
	TreeNode *tnode;
	struct ListNode *next;
} ListNode;
 
typedef struct Queue
{
	ListNode *front;
	ListNode *rear;
} Queue;
 
TreeNode *newTreeNode(int data, int k)
{
	TreeNode *tnode = (TreeNode*) malloc(sizeof(TreeNode));
	tnode->data = data;
	tnode->children = (TreeNode**) malloc(k*sizeof(TreeNode*));
	int i;
	for(i = 0; i < k; i++)
		tnode->children[i] = NULL;
	return tnode;
}
 
ListNode *newListNode(TreeNode *tnode)
{
	ListNode *lnode = (ListNode*) malloc(sizeof(ListNode));
	lnode->tnode = tnode;
	lnode->next = NULL;
	return lnode;
}
 
Queue *newQueue()
{
	Queue *Q = (Queue*) malloc(sizeof(Queue));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}
 
int isEmpty(Queue *Q)
{
	return (Q->front == NULL);
}
 
void enqueue(Queue *Q, TreeNode *tnode)
{
	if(isEmpty(Q))
	{
		Q->rear = Q->front = newListNode(tnode);
	}
	else
	{
		Q->rear->next = newListNode(tnode);
		Q->rear = Q->rear->next;
	}
}
 
TreeNode *dequeue(Queue *Q)
{
	assert(!isEmpty(Q));
	ListNode *temp = Q->front;
	Q->front = Q->front->next;
	if(!Q->front)
		Q->rear = NULL;
	TreeNode *tnode = temp->tnode;
	free(temp);
	return tnode;
}
 
void kAryLevelOrder(TreeNode *root, int k)
{
	if(!root)
		return;
	Queue *Q = newQueue();
	enqueue(Q, root);
	while(!isEmpty(Q))
	{
		TreeNode *tnode = dequeue(Q);
		int i;
		for(i = 0; i < k; i++)
		{
			if(tnode->children[i])
				enqueue(Q, tnode->children[i]);
		}
		printf("%d ", tnode->data);
	}
	printf("\n");
}
 
int main()
{
	int K = 3;
	int count = 0;
	TreeNode *root = newTreeNode(count++, K);
	int i, j, t;
	for(i = 0; i < K; i++)
		root->children[i] = newTreeNode(count++, K);
	for(i = 0; i < K; i ++)
		for(j = 0; j < K; j++)
			root->children[i]->children[j] = newTreeNode(count++, K);
	kAryLevelOrder(root, K);
	return 0;
}
