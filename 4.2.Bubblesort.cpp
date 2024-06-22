#include<iostream>
using namespace std;
void bubble_sort(int a[],int n)
{
	bool swapped;
	for(int i=0;i<n-1;i++)
	{
		swapped=false;
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
				swapped=true;
			}
		}
		if(!swapped)
			break;
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
	int b[]={5,8,3,6,1,4,2};
	int n1=sizeof(b)/sizeof(int);
	cout<<"\nInput array: \n";
	for(int k=0;k<n1;k++)
	{
		cout<<b[k]<<" ";
	}
	cout<<endl;
	cout<<"Bubble Sort: "<<endl;
	bubble_sort(b,n1);
	return 0;
}
