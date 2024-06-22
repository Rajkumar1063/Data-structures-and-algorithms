#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;
int postfix_evaluation(vector<char>& v)
{
	int n=v.size();
	vector<int>v1;
	for(int i=0;i<n;i++)
	{
		if(v[i] =='+' || v[i] =='-' || v[i] == '/' || v[i] == '*' ||  v[i] == '^')
		{
			int num1,num2;
			num1=v1.back();
			v1.pop_back();
			num2=v1.back();
			v1.pop_back();
			cout<<"Operator: "<<v[i]<<endl;
			cout<<"Pop "<<num1<<endl;
			cout<<"Pop "<<num2<<endl;
			switch(v[i])
			{
                case '+':
                    v1.push_back(num1 + num2);
                    cout<<num1+num2<<endl;;
                    break;
                case '-':
                    v1.push_back(num1 - num2);
                    cout<<num1-num2<<endl;
                    break;
                case '*':
                    v1.push_back(num1 * num2);
                    cout<<num1*num2<<endl;
                    break;
                case '/':
                    v1.push_back(num1 / num2);
                    cout<<num1/num2<<endl;
                    break;
                case '^':
                    v1.push_back(pow(num1, num2));
                    cout<<pow(num1,num2)<<endl;
                    break;
            }
		}
		else
		{
			cout<<"Push "<<v[i]<<endl;
			v[i]=v[i]-'0';
			v1.push_back(v[i]);
		}
	}
	return v1[0];
}
int main()
{
	vector<char> v;
	int n;
	cout<<"Enter number of characters: ";
	cin>>n;
	char element;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter element: ";
		cin>>element;
		v.push_back(element);
	}
	int result=postfix_evaluation(v);
	cout<<"Result is "<<result<<endl;
}
