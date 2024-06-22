#include<iostream>
using namespace std;
# define infinite 999
int n;
char graph[10];
int wtgraph[10][10];
int minwt(int wt[],bool mstset[])
{
	int mwt,minindex;
	mwt=infinite;
	minindex=0;
	for(int i=0;i<n;i++)
	{
		if(mstset[i]==false && wt[i]<mwt)
		{
			mwt=wt[i];
			minindex=i;
		}
	}
	return minindex;
}
void printmst(int parent[])
{
	int i;
	cout<<"Minimum spanning tree.\n";
	for(i=1;i<n;i++)
	{
		cout<<graph[parent[i]]<<" to "<<graph[i]<<" - "<<wtgraph[i][parent[i]];
		cout<<"\n";
	}
}
void mst()
{
	int parent[10],i,j,u,v;
	int wt[10];
	bool mstset[10];
	for(i=0;i<n;i++)
	{
		wt[i]=infinite;
		mstset[i]=false;
	}
	parent[0]=-1;
	wt[0]=0;
	for(j=0;j<n-1;j++)
	{
		u=minwt(wt,mstset);
		mstset[u]=true;
		for(v=0;v<n;v++)
		{
			if(wtgraph[u][v]!=0 && mstset[v]==false && wt[v]>wtgraph[u][v])
			{
				parent[v]=u;
				wt[v]=wtgraph[u][v];
			}
		}
	}
	printmst(parent);
}
int main()
{
	cout<<"Enter number of vertices: ";
	cin>>n;
	int i,j;
	for(i=0;i<n;i++)
	{
		cout<<"Enter vertex "<<i+1<<": ";
		cin>>graph[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
				cout<<"Enter weight of "<<graph[i]<<" to "<<graph[j]<<": ";
				cin>>wtgraph[i][j];
			}
		}
	}
	mst();
}
