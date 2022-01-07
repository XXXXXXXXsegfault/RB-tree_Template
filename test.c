#include <stdio.h>
#include <stdlib.h>
struct rbtree_test
{
	int color;
	int val;
	struct rbtree_test *left;
	struct rbtree_test *right;
	struct rbtree_test *parent;
} *rbtree_root;
#define RBTREE_TYPE struct rbtree_test
#define RBTREE_CMP(node1,node2) ((node1)->val>(node2)->val)
#define RBTREE_LEFT left
#define RBTREE_RIGHT right
#define RBTREE_PARENT parent
#define RBTREE_COLOR color
#define RBTREE_INSERT rbtree_test_insert
#define RBTREE_DELETE rbtree_test_delete
#define RBTREE_FIND rbtree_test_find
#include "rbtree.c"
void rbtree_insert_value(int val)
{
	struct rbtree_test *node;
	node=malloc(sizeof(*node));
	if(node==NULL)
	{
		fprintf(stderr,"Cannot allocate memory.\n");
		abort();
	}
	node->val=val;
	rbtree_test_insert(&rbtree_root,node);
}
void rbtree_delete_value(int val)
{
	struct rbtree_test *node,cmp;
	cmp.val=val;
	node=rbtree_test_delete(&rbtree_root,&cmp);
	if(node)
	{
		free(node);
	}
}
int array1[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
int array2[7]={3,4,5,6,8,10,12};
int main(void)
{
	int n=0;
	struct rbtree_test val;
	while(n<15)
	{
		rbtree_insert_value(array1[n]);
		n++;
	}
	n=0;
	while(n<7)
	{
		rbtree_delete_value(array2[n]);
		n++;
	}
	n=1;
	while(n<=15)
	{
		val.val=n;
		if(rbtree_test_find(rbtree_root,&val))
		{
			printf("Number %d is in RB-tree.\n",n);
		}
		n++;
	}
	return 0;
}
