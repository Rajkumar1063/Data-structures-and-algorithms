#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
string prefix_to_postfix(vector<string>& v)
{
	int n=v.size();
	vector<string>v1;
	for(int i=n-1;i>=0;i--)
	{
		if(v[i] =="+" || v[i] =="-" || v[i] == "/" || v[i] == "*" ||  v[i] == "^")
		{
			string a,b,c,d;
			a=v1.back();v1.pop_back();
			b=v1.back();v1.pop_back();
			c=v[i];
			d=a+b+c;
			cout<<"Operator: "<<v[i]<<endl;
			cout<<"Pop "<<a<<endl;
			cout<<"Pop "<<b<<endl;
			cout<<"Concatenation: "<<d<<endl;
			cout<<"Push "<<d<<endl;
			v1.push_back(d);
		}
		else
		{
			cout<<"Push "<<v[i]<<endl;
			v1.push_back(v[i]);
		}
	}
	return v1[0];
}
int main()
{
	vector<string> v;
	int n;
	cout<<"Enter number of characters: ";
	cin>>n;
	string element;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter element: ";
		cin>>element;
		v.push_back(element);
	}
	cout<<"Prefix expression: ";
	for(int i=0;i<n;i++)
	{
		cout<<v[i];
	}
	cout<<endl;
	string str=	prefix_to_postfix(v);
	cout<<"\nPostfix expression: ";
	cout<<str;
	return 0;
}
