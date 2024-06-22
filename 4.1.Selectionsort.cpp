#include<iostream>
using namespace std;
void selection_sort(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		int minindex=i;
		int smallest=a[i];
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<smallest)
			{
				smallest=a[j];
				minindex=j;	
			}
		}
		if(minindex!=i)
			swap(a[i],a[minindex]);
		cout<<"Pass "<<i+1<<endl;
		for(int k=0;k<n;k++)
		{
			cout<<a[k]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	int a[]={50,40,70,30,10,20};
	int n=sizeof(a)/sizeof(int);
	cout<<"Input array: \n";
	for(int k=0;k<n;k++)
	{
		cout<<a[k]<<" ";
	}
	cout<<endl;
	cout<<"Selection Sort: "<<endl;
	selection_sort(a,n);
	return 0;
}
