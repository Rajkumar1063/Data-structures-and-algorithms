#include<iostream>
#include<vector>
using namespace std;
#include<string>
int priority(string v)
{
	if(v == "+" || v == "-")
		return 1 ;
	else if(v == "*" || v == "/")
		return 2;	
	else
		return 0;	
}
string infix_to_postfix(vector<string> v)
{
	string result;
	vector<string>v1;
	for(int i=0;i<v.size();i++)
	{
		if(v[i]=="(")
		{
			cout<<"OP "<<v[i]<<endl;
			v1.push_back(v[i]);
		}
		else if(v[i]==")")
		{
			cout<<"CP "<<v[i]<<endl;
			while(!v1.empty() && v1.back()!="(")
			{
				result+=v1.back();
				v1.pop_back();
			}
			v1.pop_back();
		}
		else if( v[i]=="+" || v[i]=="-" || v[i]=="*" || v[i]=="/")
		{
			cout<<"Operator "<<v[i]<<endl;
			while(!v1.empty() && priority(v1.back())>=priority(v[i]))
			{
				result+=v1.back();
				v1.pop_back();
			}
			v1.push_back(v[i]);
		}
		else
		{
			cout<<"Operand "<<v[i]<<endl;
			result+=v[i];
		}
	}
	while(!v1.empty())
	{
		result+=v1.back();
		v1.pop_back();
	}
	return result;
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
		cout<<"Enter character: ";
		cin>>element;
		v.push_back(element);
	}
	cout<<"Infix expression is: ";
	for(int i=0;i<n;i++)
	{
		cout<<v[i];
	}
	cout<<endl;
	string result=infix_to_postfix(v);
	cout<<"Postfix expression is: "<<result<<endl;
}
