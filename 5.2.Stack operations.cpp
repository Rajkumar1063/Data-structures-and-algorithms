#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> v;
	int choice=1,element;
	cout<<"1.Push\n2.Pop\n3.Top element\n4.Display.\nExit\n";
	while(choice!=5)
	{
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter element to inserted into stack: ";
				cin>>element;
				v.push_back(element);
				break;
			case 2:
				cout<<"Element poped from stack is "<<v.back()<<endl;
				v.pop_back();
				break;
			case 3:
				cout<<"Top element of stack is "<<v.back()<<endl;
				break;
			case 4:
				for(int i=0;i<v.size();i++)
				{
					cout<<v[i]<<" ";
				}
				cout<<endl;
				break;		
		}
	}
	return 0;
}
