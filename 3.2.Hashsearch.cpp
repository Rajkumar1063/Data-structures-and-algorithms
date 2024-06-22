#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter number of elements: ";
	cin>>n;
	int a[n][n/2];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n/2;j++)
		{
			a[i][j]=-1;
		}
	}
	cout<<"Enter elements: \n";
	int element,loc;
	for(int i=0;i<n;i++)
	{
		cin>>element;
		loc=element%10;
		cout<<loc<<endl;
		if(a[loc][0]==-1)
			a[loc][0]=element;
		else
		{
			for(int j=1;j<n/2;j++)
			{
				if(a[loc][j]==-1)
				{
					a[loc][j]=element;
					break;
				}
				else
					continue;	
			}
		}	
	}
	cout<<"Array after inserting elements: \n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n/2;j++)
		{
			if(a[i][j]!=-1)
				cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Enter elements to be searched: ";
	cin>>element;
	loc=element%10;
	for(int i=0;i<n/2;i++)
	{
		if(a[loc][i]==element)
		{
			cout<<"Element found.";
			return 0;
		}
	}
	cout<<"Element not found.\n";
}
