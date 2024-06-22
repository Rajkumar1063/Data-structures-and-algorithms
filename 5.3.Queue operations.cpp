#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> v;
	int choice=1,element;
	cout<<"1.Enqueue\n2.Dequeue\n3.Top element\n4.Display.\nExit\n";
	while(choice!=5)
	{
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter element to be enqueued: ";
				cin>>element;
				v.push_back(element);
				break;
			case 2:
				cout<<"Dequeued element is "<<v.front()<<endl;
				v.erase(v.begin()+0);
				break;
			case 3:
				cout<<"Top element of queue is "<<v.front()<<endl;
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
