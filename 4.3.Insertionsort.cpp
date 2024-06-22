#include<iostream>
using namespace std;
void insertion_sort(int a[],int n)
{
	for(int i=1;i<n;i++)
	{
		int key=a[i];
		int j=i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
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
	int b1[]={5,8,3,6,1,4,2};
	int n2=sizeof(b1)/sizeof(int);
	cout<<"\nInput array: \n";
	for(int k=0;k<n2;k++)
	{
		cout<<b1[k]<<" ";
	}
	cout<<endl;
	cout<<"Insertion Sort: "<<endl;
	insertion_sort(b1,n2);
}
