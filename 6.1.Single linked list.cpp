#include<iostream>
using namespace std;
struct node
{
	int data;
	node *link;
};
struct lst
{
	int count;
	node *head;
}list;
void initialise()
{
	list.count=0;
	list.head=NULL;
}
node* searchnode(int datain)
{
	node *ploc,*ppre=NULL;
	ploc=list.head;
	while(ploc!=NULL &&ploc->data<datain)
	{
		ppre=ploc;
		ploc=ploc->link;
	}
	return ppre;
}
void insertnode(node *ppre,int datain)
{
	node *pnew=new node;
	pnew->data=datain;
	if(ppre==NULL)//insertion at empty list or beginning of a list
	{
		pnew->link=list.head;
		list.head=pnew;
	}
	else//insertion at middle or end of a list
	{
		pnew->link=ppre->link;
		ppre->link=pnew;
	}
	list.count+=1;
	cout<<"List count is "<<list.count<<endl;
}
void deletenode(int datain)
{
	node *ppre=NULL,*ploc;
	ploc=list.head;
	while(ploc!=NULL && ploc->data!=datain)
	{
		ppre=ploc;
		ploc=ploc->link;
	}
	if(ploc==NULL)
	{
		cout<<"Data to be deleted is not found.\n";
	}
	else
	{
		if(ppre==NULL)//deletion at beginning of a list
		{
			list.head=list.head->link;
		}
		else//deletion at middle or end of a list
		{
			ppre->link=ppre->link->link;
		}
		list.count-=1;
		cout<<"List count is "<<list.count<<endl;
	}
}
void sort()
{
	node *i,*j;
	for(i=NULL;i!=list.head->link;i=j)
	{
		for(j=list.head;j->link!=i;j=j->link)
		{
			if(j->data<=j->link->data)
			{
				swap(j->data,j->link->data);
			}
		}
	}
	cout<<"Sorted Successfully.\n";
}
void display()
{
	node *ploc;
	ploc=list.head;
	while(ploc!=NULL)
	{
		cout<<ploc->data<<" ";
		ploc=ploc->link;
	}
	cout<<endl;
}
int main()
{
	initialise();
	int choice=1;
	int data;
	node *ppre;
	cout<<"1.Insert\n2.Delete\n3.Display.\n4.Sort.\n";
	while(choice!=5)
	{
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter data to be inserted: ";
				cin>>data;
				ppre=searchnode(data);
				insertnode(ppre,data);
				break;
			case 2:
				cout<<"Enter data to be deleted: ";
				cin>>data;
				deletenode(data);	
			case 3:
				display();
				break;	
			case 4:
				sort();
				display();
				break;		
		}
	}
}
