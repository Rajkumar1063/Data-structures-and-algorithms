#include<iostream>
#include<cstdlib>
using namespace std;
int fib(int n)
{
	if(n==0 || n==1)
		return 1;
	else
		return(fib(n-1)+fib(n-2));		
}
int gcd(int a,int b)
{
	if(a==0)
		return b;
	else if(b==0)
		return a;
	else
		return(b,a%b);			
}
void toh(int n,char source,char dest,char aux)
{
	if(n==1)
		cout<<"Move disk from "<<source<<" to "<<dest<<endl;
	else
	{
		toh(n-1,source,aux,dest);
		cout<<"Move disk from "<<source<<" to "<<dest<<endl;
		toh(n-1,aux,dest,source);
	}	
}
int main()
{
	cout<<fib(4)<<endl;
	cout<<gcd(10,20)<<endl;
	toh(3,'A','B','C');
	return 0;
}
