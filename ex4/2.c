#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	long int data;
	struct node* ls;
	struct node* rs;

};
struct node* bst=NULL;
void insert(struct node*,long int);
struct node* binsert(struct node*,struct node*);
void search(struct node*,long int);
long int findMax(struct node*);
long int findMin(struct node*);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
long int predecessor(struct node*,long int);
long int successor(struct node*,long int);
struct node* findnode(struct node*,long int);
void delete(struct node*,long int);
struct node* bdelete(struct node*,struct node*);
int main()
{
	char str[10];
	long int a;
	
	do
	{
		scanf("%s",str);

	if(!strcmp(str,"insr"))
	{
		scanf("%ld",&a);
		insert(bst,a);
	}
	else if(!strcmp(str,"srch"))
	{
		scanf("%ld",&a);
		search(bst,a);
		printf("\n");
	}
	else if(!strcmp(str,"minm"))
	{
		if(bst==NULL)
			printf("NIL\n");
		else
			printf("%ld\n",findMin(bst));
	}
	else if(!strcmp(str,"maxm"))
	{
		if(bst==NULL)
			printf("NIL\n");
		else
			printf("%ld\n",findMax(bst));
	}
	else if(!strcmp(str,"inor"))
	{
		inorder(bst);
		printf("\n");
	}
	else if(!strcmp(str,"prer"))
	{
		preorder(bst);
		printf("\n");
	}
	else if(!strcmp(str,"post"))
	{	
		postorder(bst);
		printf("\n");
	}
	else if(!strcmp(str,"pred"))
	{
		scanf("%ld",&a);
		a=predecessor(bst,a);
		if(a==-1)
			printf("NIL\n");
		else if(a==-2)
			printf("NOT FOUND\n");
		else
			printf("%ld\n",a);
	}
	else if(!strcmp(str,"succ"))
	{
		scanf("%ld",&a);
		a=successor(bst,a);
		if(a==-1)
			printf("NIL\n");
	        else if(a==-2)
                        printf("NOT FOUND\n");
		else
	                printf("%ld\n",a);
	}
	else if(!strcmp(str,"delt"))
	{
		scanf("%ld",&a);
		delete(bst,a);

	}

	}while(strcmp(str,"stop"));
}

struct node* findnode(struct node* root,long int key)
{
if(root==NULL)
	return NULL;
else if(root->data==key)
	return root;
else if(root->data>=key)
	findnode(root->ls,key);
else
	findnode(root->rs,key);
}

void insert(struct node* tree,long int elem)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=elem;
	temp->ls=NULL;
	temp->rs=NULL;
	bst=binsert(tree,temp);
}

struct node* binsert(struct node* root,struct node* new)
{
	if(root==NULL)
		return new;
	else if(root->data>=new->data)
	{
		root->ls=binsert(root->ls,new);
		return root;
	}
	else
		root->rs=binsert(root->rs,new);
		return root;
}
void search(struct node* root,long int key)
{
	if(root==NULL)
		printf("NOT FOUND");
	else if(root->data==key)
		printf("FOUND");
	else if(root->data<key)
		search(root->rs,key);
	else
		search(root->ls,key);
}
long int findMax(struct node* root)
{
	if(root->rs==NULL)
		return (root->data);
	else
		findMax(root->rs);
}
long int findMin(struct node* root)
{
	if(root->ls==NULL)
		return (root->data);
	else
		findMin(root->ls);
}
void inorder(struct node* root)
{
	if(root!=NULL)
	{
		inorder(root->ls);
		printf("%ld ",root->data);
		inorder(root->rs);
	}
}
void preorder(struct node* root)
{
	if(root!=NULL)
	{
		printf("%ld ",root->data);
		preorder(root->ls);
		preorder(root->rs);
	}
}
void postorder(struct node* root)
{
	if(root!=NULL)
	{
		postorder(root->ls);
		postorder(root->rs);
		printf("%ld ",root->data);
	}
}
long int predecessor(struct node* root,long int key)
{
	struct node* p;
	struct node* q;
	struct node* r;
	r=findnode(bst,key);
	if(r==NULL)
		return -2;
	else if(r->ls!=NULL)
		return(findMax(r->ls));
	else
	{
		p=root;
		if(p->data<key)
			q=p->rs;
		else
		{
			q=p->ls;
			p=NULL;
		}
		while(q!=NULL&&q->data!=key)
		{
			if(key<=q->data)
				q=q->ls;
			else
			{
				p=q;
				q=q->rs;
			}
		}
		if(p!=NULL)
		return (p->data);
		else
		return -1;
	}
}	

long int successor(struct node* root,long int key)
{
	struct node* p;
	struct node* q;
	struct node* r;
	r=findnode(bst,key);
	if(r==NULL)
		return -2;
	else if(r->rs!=NULL)
		return(findMin(r->rs));
	else
	{
		p=root;
		if(p->data<=key)
		{
			q=p->rs;
			p=NULL;
		}
		else
			q=p->ls;
		while(q!=NULL&&q->data!=key)
		{
			if(key>=q->data)
				q=q->rs;
			else
			{
				p=q;
				q=q->ls;
			}
		}
		if(p!=NULL)
		return (p->data);
		else
		return -1;
	}

}
void delete(struct node* r,long int key)
{
	struct node* p=findnode(bst,key);
	if(p!=NULL)
		bst=bdelete(bst,p);
}
struct node* bdelete(struct node* r,struct node* p)
{
	struct node* q;
	struct node* x;
	
	if(p==r)
	{
		if(r->rs==NULL)
		{
			q=r->ls;
			r->ls=NULL;
			return q;
		}
		else if(r->ls==NULL)
		{
			q=r->rs;
			r->rs=NULL;
			return q;
		}
		else
		{
			q=r->rs;
			if(q->ls==NULL)
			{
				x=r->ls;
				r->ls=NULL;
				q->ls=x;
				return q;
			}
			else
			{
				x=q->ls;
				while(x->ls!=NULL)
				{
					q=x;
					x=x->ls;
				}
				x->ls=p->ls;
				p->ls=NULL;
				q->ls=x->rs;
				x->rs=r->rs;
				return x;
			}
		}
	}
	else if(p->data<r->data)
		r->ls=bdelete(r->ls,p);
	else
		r->rs=bdelete(r->rs,p);

}

