#include<iostream>
using namespace std;
void recbinarysearch(int arr[],int low,int high,int element)
{
	if(low<=high)
	{
		int mid=(low+high)/2;
		if(arr[mid]==element)
			cout<<"Element found at index "<<mid<<endl;
		else if(arr[mid]>element)
			recbinarysearch(arr,low,mid-1,element);
		else
			recbinarysearch(arr,mid+1,high,element);		
	}
	else
		cout<<"Element not found.\n";
	
}
void binarysearch(int arr[],int low,int high,int element)
{
	int i=0;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(arr[mid]==element)
		{
			i=1;
			cout<<"Element found at index "<<mid<<endl;
			break;
		}
		else if(arr[mid]>element)
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	if(i==0)
		cout<<"Element not found."<<endl;
}
int main()
{
	int arr[]={1,2,3,4,5,6,7,8};
	int n=sizeof(arr)/sizeof(int);
	binarysearch(arr,0,n,3);
	recbinarysearch(arr,0,n,9);
}
