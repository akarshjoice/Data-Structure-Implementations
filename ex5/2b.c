#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	long int d;
	long int w;
	struct node *next;
};
struct node* head[10001];
struct Edge
{
	long int start;
	long int end;
	long int weight;
};
struct Graph
{
	long int E;
	long int V;
	struct Edge* edge;
};
struct subset 
{
	long int parent;	
	
	long int rank;	
};
int Find(struct subset subsets[],long int i) 
{
		if (subsets[i].parent != i) 
		{

		subsets[i].parent = Find(subsets, subsets[i].parent);
		}
			
		return subsets[i].parent;

}
void Union(struct subset subsets[], long int vertXSubset, long int vertYSubset) 
{

	long int rootOfX = Find(subsets, vertXSubset);
	long int rootOfY = Find(subsets, vertYSubset);
		     
	if (subsets[rootOfX].rank < subsets[rootOfY].rank) 
	{				     
		 subsets[rootOfX].parent = rootOfY;
     	}
       else if (subsets[rootOfX].rank > subsets[rootOfY].rank) 
       {
            subsets[rootOfY].parent = rootOfX;					        }
	else 
	{
		subsets[rootOfY].parent = rootOfX;
		subsets[rootOfX].rank++;
        }
}
struct Graph* createGraph(long int E,long int V) 
{
struct Graph* graph = (struct Graph*) malloc (sizeof(struct Graph));
graph->E=E;
graph->V=V;
graph->edge=(struct Edge*)malloc(graph->E*sizeof(struct Edge));
return graph;
}
void sort(struct Graph* graph) 
{
	long int i, j, noOfEdges = graph->E;
	struct Edge* tempEdge = (struct Edge*) malloc (sizeof(struct Edge));
for (i = 1; i < noOfEdges; i++) 
{	
for (j = 0; j < noOfEdges - i; j++) 
{
if (graph->edge[j].weight > graph->edge[j+1].weight) 
{										tempEdge->start = graph->edge[j].start;						tempEdge->end = graph->edge[j].end;
tempEdge->weight = graph->edge[j].weight;
graph->edge[j] = graph->edge[j+1];
graph->edge[j+1].start = tempEdge->start;
graph->edge[j+1].end = tempEdge->end;
graph->edge[j+1].weight = tempEdge->weight;
}
}
}
}
int hasCycle(struct Graph* graph) 
{

	long int i, j, vertXSubset, vertYSubset;
	long int V = graph->V;
	long int E = graph->E;
struct subset* subsets = (struct subset*) malloc (V * sizeof(struct subset));
for (i = 0; i < V; i++) 
{
					 	 					subsets[i].parent = i;
	subsets[i].rank = 0;
	 	 								}
			
for (j = 0; j < E; j++) 
{
	vertXSubset = Find(subsets, graph->edge[j].start);
	vertYSubset = Find(subsets, graph->edge[j].end);
	if (vertXSubset == vertYSubset) {										return 1;								}
										Union(subsets, vertXSubset, vertYSubset);

										}
	return 0;

}



void kruskal(struct Graph* graph) 
{
long int i, j;
long int E = graph->E;
long int V = graph->V;
sort(graph);

	struct Graph* graphMST = createGraph(V - 1, V);

	for (i = 0, j = 0; i < E && j < V - 1; i++) 
	{
		graphMST->edge[j] = graph->edge[i];
		graphMST->E = j + 1;
		if (!hasCycle(graphMST)) 
		{	
			j++;
		}
	}
	long int sum;
	sum=0;
	for(i=0;i<graphMST->E;i++)
		sum=sum+graphMST->edge[i].weight;
	printf("%ld",sum);
}


int main()
{
	struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
	long int i;
	long int e;
	e=0;
	for(i=0;i<10001;i++)
		head[i]=NULL;
	long int j;
	j=0;
	i=0;
	long int n;
	char ch[10000],ju;
	int num;
	long int num1;
	struct node* t;
	scanf("%ld",&n);
	graph->V=n;
	ju=getchar();
	while(i<n)
	{
		gets(ch);
		t=head[i];
		for(j=0;ch[j]!='\0';j++)
		{
				if(ch[j]==' ')
							continue;
				while(ch[j]!=' '&&ch[j]!='\0')
				{
						num=ch[j]-'0';
							num1=num1*10+num;
								j++;
				}
				j--;
		struct node* temp=(struct node*)malloc(sizeof(struct node));
				temp->d=num1;
				temp->next=NULL;
				if(head[i]==NULL)
				{
						head[i]=temp;
							t=head[i];
							e++;
				}
					else
					{
							t->next=temp;
								t=t->next;
					e++;
					}
					num1=0;
		}
		i++;
	}
	i=0;
	j=0;
	num1=0;
	struct node* te;

	while(i<n)
	{
		gets(ch);
		te=head[i];
		for(j=0;ch[j]!='\0';j++)
		{
				if(ch[j]==' ')
							continue;
				while(ch[j]!=' '&&ch[j]!='\0')
				{
						num=ch[j]-'0';
							num1=num1*10+num;
								j++;
				}
				j--;
				te->w=num1;
				te=te->next;
				num1=0;
		}
		i++;
	}
	graph->E=e;
	graph->edge=(struct Edge*)malloc(e*sizeof(struct Edge));
	j=0;
	for(i=0;i<n;i++)
	{
	struct node* t=head[i];
	while(t!=NULL)
	{
		graph->edge[j].start=i;
		graph->edge[j].end=t->d;
		graph->edge[j].weight=t->w;
		t=t->next;
		j++;
	}
	}
	kruskal(graph);


}

