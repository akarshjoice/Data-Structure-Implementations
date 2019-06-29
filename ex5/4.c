#include<stdio.h>
#include<stdlib.h>
struct edge
{
	long int u;
	long int v;
	long int w;
};
struct graph
{
	long int V;
	long int E;
	struct edge *e;
};

int negcycle(struct graph *g,long int s,long int a[]);
int dnegcycle(struct graph *g);
int main()
{
	long int a,b,i,c,d,f;
	struct graph *g=(struct graph*)malloc(sizeof(struct graph));
	scanf("%ld %ld",&a,&b);
	g->V=a;
	g->E=b;
	g->e=(struct edge*)malloc(b*sizeof(struct edge));

	for(i=0;i<b;i++)
	{
		scanf("%ld %ld %ld",&c,&d,&f);
		g->e[i].u=c;
		g->e[i].v=d;
		g->e[i].w=f;
	}

	printf("%d",dnegcycle(g));
}
int negcycle(struct graph* g,long int s,long int d[])
{
	long int i,j,u,v,w,tv,te;
	tv=g->V;
	te=g->E;
	//long int d[tv];
	long int p[tv];
	for(i=0;i<tv;i++)
	{
		d[i]=99999;
		p[i]=0;
	}
	d[s]=0;
	for(i=1;i<=tv-1;i++)
	{
		for(j=0;j<te;j++)
		{
			u=g->e[j].u;
			v=g->e[j].v;
			w=g->e[j].w;
			if(d[u]!=99999&&d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				p[v]=u;
			}
		}
	}
	for(i=0;i<te;i++)
	{
		u=g->e[i].u;
		v=g->e[i].v;
		w=g->e[i].w;
		if(d[u]!=99999&&d[v]>d[u]+w)
		{
			return 1;
		}
	}
	return -1;
}
int dnegcycle(struct graph* g)
{
	long int tv,i;
	tv=g->V;
	int vi[tv];
	for(i=0;i<tv;i++)
		vi[tv]=0;
	long int d[tv];

	for(i=0;i<tv;i++)
	{
		if(vi[i]==0)
		{
			if(negcycle(g,i,d)==1)
				return 1;
			for(i=0;i<tv;i++)
			{
				if(d[i]!=99999)
					vi[i]=1;
			}
		}
	}
	return -1;
}


