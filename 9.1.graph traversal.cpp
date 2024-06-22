#include<iostream>
#include<vector>
using namespace std;
struct node
{
	char id;
	node *link;
};
struct gnode
{
	char id;
	int visited;
	node *flink;
};

class graph
{
	gnode g[10];
	int n;
	vector<char> s;
	public:
		void initialise()
		{
			for(int i=0;i<n;i++)
			{
				g[i].visited=0;
				g[i].flink=NULL;
			}
		}
		void constructgraph()
		{
			cout<<"Enter no of vertices: ";
			cin>>n;
			initialise();
			for(int i=0;i<n;i++)
			{
				cout<<"Enter id of vertex "<<i+1<<": ";
				cin>>g[i].id;
				int nadj;
				cout<<"Enter no of adjacent vertices of "<<g[i].id<<": ";
				cin>>nadj;
				for(int j=0;j<nadj;j++)
				{
					node *pnew=new node;
					cout<<"Enter id of adjacent vertex "<<j+1<<": ";
					cin>>pnew->id;
					pnew->link=g[i].flink;
					g[i].flink=pnew;
				}
			}
		}
		void display()
		{
			for(int i=0;i<n;i++)
			{
				cout<<g[i].id<<" -----> ";
				node *ploc;
				ploc=g[i].flink;
				while(ploc!=NULL)
				{
					cout<<ploc->id<<" ";
					ploc=ploc->link;
				}
				cout<<endl;
			}
		}
		int findindex(char x)
		{
			for(int i=0;i<n;i++)
			{
				if(g[i].id==x)
					return i;
			}
		}
		bool inlist(char x)
		{
			for(int i=0;i<s.size();i++)
			{
				if(s[i]==x)
					return false;
			}
			return true;
		}
		void dfs(int x)
		{
			for(int i=0;i<n;i++)
			{
				g[i].visited=0;
			}
			s.push_back(g[x].id);
			while(!s.empty())
			{
				char x=s.back();
				s.pop_back();
				cout<<x;
				int index=findindex(x);
				g[index].visited=1;
				node *ploc;
				ploc=g[index].flink;
				while(ploc!=NULL)
				{
					index=findindex(ploc->id);
					if(g[index].visited==0 && inlist(ploc->id))
						s.push_back(ploc->id);	
					ploc=ploc->link;	
				}
			}
			for(int i=0;i<n;i++)//disjoint graph
			{
				if(g[i].visited==0)
				{
					cout<<g[i].id<<" ";
				}
			}
			s.clear();
			cout<<endl;
		}
		void bfs(int x)
		{
			for(int i=0;i<n;i++)
			{
				g[i].visited=0;
			}
			s.push_back(g[x].id);
			while(!s.empty())
			{
				char x=s.front();
				s.erase(s.begin()+0);
				cout<<x;
				int index=findindex(x);
				g[index].visited=1;
				node *ploc;
				ploc=g[index].flink;
				while(ploc!=NULL)
				{
					index=findindex(ploc->id);
					if(g[index].visited==0 && inlist(ploc->id))
						s.push_back(ploc->id);	
					ploc=ploc->link;	
				}
			}
			for(int i=0;i<n;i++)//disjoint graph
			{
				if(g[i].visited==0)
				{
					cout<<g[i].id<<" ";
				}
			}
		}
};
int main()
{
	graph g;
	g.constructgraph();
	int choice;
	int x;
	cout<<"Adjacency list\n";
	g.display();
	cout<<"1.DFS\n2.BFS\n3.Exit";
	while(choice!=3)
	{
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter index of starting vertex: ";
				cin>>x;
				g.dfs(x);
				break;
			case 2:
				cout<<"Enter index of starting vertex: ";
				cin>>x;
				g.bfs(x);
				break;		
		}
	}
}
