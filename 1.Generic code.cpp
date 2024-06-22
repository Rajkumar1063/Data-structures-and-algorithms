#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	void *ptr;
	int a=5;
	ptr=&a;
	cout<<*((int*)ptr)<<endl;
	ptr=(int *)malloc(sizeof(int));
	int b=10;
	ptr=&b;
	cout<<*((int*)ptr)<<endl;
}
