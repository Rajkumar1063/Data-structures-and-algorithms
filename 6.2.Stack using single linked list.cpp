#include<iostream>
using namespace std;
struct node
{
	int data;
	node* link;
};
struct lst
{
	int count;
	node* head;
}list;
void push(int datain)
{
	node* pnew=new node;
	pnew->data=datain;
	if(list.head==NULL)
	{
		list.head=pnew;
		pnew->link=NULL;
	}
	else
	{
		pnew->link=list.head;
		list.head=pnew;
	}
}
void display()
{
	node *ploc;
	ploc=list.head;
	while(ploc!=NULL)
	{
		cout<<ploc->data<<endl;
		ploc=ploc->link;
	}
	if(list.head==NULL)
	{
		cout<<"Empty list.\n";
	}
}
void pop()
{
	if(list.head==NULL)
	{
		cout<<"Empty list.\n";
    }
    else
    {
    	cout<<list.head->data<<endl;
    	list.head=list.head->link;
	}
}
int main()
{
	int data,choice;
	cout<<"1.Push\n2.Display\n3.Pop.\n4.Exit.\n";
	while(choice!=4)
	{
		cout<<"Enter choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter data to be inserted: ";
				cin>>data;
				push(data);
				break;
			case 2:
			    display();
				break;
			case 3:
			    pop();
				break;		
		}
	}
}
