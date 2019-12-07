#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int n;
int cost[50][50],new_cost[50][50],parent[50];
int find(int);
int uni(int,int);

void krushkal(int n,int cost[50][50])
{
	int ne=1,u,v,a,b,i,j,k,min,mincost=0;
	for(int y=0;y<50;y++)
	{
	parent[y]=0;
	}

	printf("\n\nThe edges of Minimum Cost Spanning Tree are :\n");
	while(ne < n)
	{
		for(i=1,min=INT_MAX;i<=n;i++)
		{
			for(j=1;j <= n;j++)
			{
				if(cost[i][j] < min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			printf("%d edge (%d,%d) =%d\n",ne++,a,b,min);
			mincost +=min;
		}
		cost[a][b]=cost[b][a]=INT_MAX;
	}
	printf("\n\tMinimum cost = %d\n",mincost);


}
int find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}
int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}

int main()
{
	printf("\n_______________________________________________________________________________________________________________________________________________________________________________");
	printf("\n\n\t\t\t\t\tWelcome to Tirth's Broadband\n\n");
	printf("_______________________________________________________________________________________________________________________________________________________________________________");




int c;
do{
printf("\n\n\n --> Enter 1 to establish new network.");
printf("\n           2 to add a new point(vertex).");
printf("\n           3 to see my network.");
printf("\n           0 to exit.");

printf("\n\n Enter your choice : ");
scanf("%d",&c);

int new[50] = {-9};

switch (c)
{
case 1:


printf("\n\tImplementation of Kruskal's algorithm\n");
	printf("\nEnter the no. of vertices : ");
	scanf("%d",&n);

	printf("\nEnter the cost adjacency matrix:\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=INT_MAX;
			new_cost[i][j]=cost[i][j];
		}
	}



	krushkal(n,new_cost);
	break;
case 2:


	for(int q=0;q<n;q++)
	{
	printf("Enter the distance of new point from Point %d : ",(q+1));
	scanf("%d",&new[q]);
	}
	n++;



	for(int p = 1;p<=n;p++)
	{
		if(p==n)
		cost[p][p] = INT_MAX;
		else
		{
					cost[n][p]=new[p-1];
					cost[p][n]= new[p-1];

		}

	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{

			new_cost[i][j]=cost[i][j];
		}
	}
printf("\n");

	// for(int i=1;i<=n;i++)                                for  Testing
	// 		{for(int j=1;j<=n;j++)
	// 			printf("(%d,%d)= %d  ,  ",i,j,cost[i][j]);
	// 			printf("\n");
	// 		}

	krushkal(n,new_cost);

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{

			new_cost[i][j]=cost[i][j];
		}
	}
	break;

	case 3:

	printf("\nYour network is: ");
	krushkal(n,new_cost);

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{

			new_cost[i][j]=cost[i][j];
		}
	}
	break;

	case 0:
		c=0;





default:
	printf("\n Enter valid input...!!!!\n");
	break;
}




}while(c!=0);


}
