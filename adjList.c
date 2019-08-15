#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
	int data;
	struct node* next;
};

struct AdjList
{
	struct node* head;
};

struct Graph
{
	int v;
	struct AdjList* array;
};

struct node* newNode(int new_data)
{
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=new_data;
	new_node->next=NULL;
	return new_node;
}

struct Graph* createGraph(int v)
{
	struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
	graph->v=v;
	graph->array=(struct AdjList*)malloc(sizeof(struct AdjList)*v);
	for(int i=0;i<graph->v;i++)
	{
		graph->array[i].head=NULL;
	}
	return graph;
}

void printGraph(struct Graph* graph)
{
	int i;
	for(i=0;i<graph->v;i++)
	{
		printf("%d",i);
		struct node* beast=graph->array[i].head;
		while(beast)
		{
			printf("->%d ",beast->data);
			beast=beast->next;
		}
		printf("\n");
	}
	return;
}

void addEdge(struct Graph *graph,int m,int k)
{
	struct node* new_node=newNode(k);
	struct node* t=graph->array[m].head;
	if(!t)
	{
		graph->array[m].head=new_node;
	}
	else
	{
		while(t->next)
		{
			t=t->next;
		}
		t->next=new_node;
	}
	new_node=newNode(m);
	t=graph->array[k].head;
	if(!t)
	{
		graph->array[k].head=new_node;
	}
	else
	{
		while(t->next)
		{
			t=t->next;
		}
		t->next=new_node;
	}
}

int main()
{
	int test,i,v,m,n,k;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %d",&v,&n);
		struct Graph* graph=createGraph(v);
		//scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&m,&k);
			addEdge(graph,m,k);
		}
	//	printf("Adjcency List of vertices of above graph\n");
		printGraph(graph);
	}
	return 0;
}
