#include<iostream>
using namespace std;
struct node
{
	int data;
	node *flink;
	node *blink;
};
struct lst
{
	int count;
	node *head;
	node *rear;
}list;
void initialise()
{
	list.count=0;
	list.head=NULL;
	list.rear=NULL;
}
node* searchnode(int datain)
{
	node *ploc,*ppre=NULL;
	ploc=list.head;
	while(ploc!=NULL &&ploc->data<datain)
	{
		ppre=ploc;
		ploc=ploc->flink;
	}
	return ppre;
}
void insertnode(node *ppre,int datain)
{
	node *pnew=new node;
	pnew->data=datain;
	if(ppre==NULL)//insertion at empty list or beginning of a list
	{
		if(list.head==NULL)//insertion at empty list
		{
			pnew->flink=list.head;
			pnew->blink=list.rear;
			list.head=pnew;
			list.rear=pnew;
		}
		else//insertion at beginning of a list
		{
			pnew->blink=NULL;
			pnew->flink=list.head;
			list.head->blink=pnew;
			list.head=pnew;
		}
	}
	else//insertion at middle or end of a list
	{
		if(ppre->flink==NULL)//insertion at end of a list
		{
			pnew->flink=NULL;
			pnew->blink=ppre;
			ppre->flink=pnew;
			list.rear=pnew;
		}
		else
		{
			pnew->flink=ppre->flink;
			pnew->blink=ppre;
			ppre->flink->blink=pnew;
			ppre->flink=pnew;
		}
	}
	list.count+=1;
	cout<<"List count is "<<list.count<<endl;
}
void deletenode(int datain)
{
	node *ploc,*ppre=NULL;
	ploc=list.head;
	while(ploc!=NULL &&ploc->data!=datain)
	{
		ppre=ploc;
		ploc=ploc->flink;
	}
	if(ploc==NULL)
	{
		cout<<"Data to be deleted is not found.\n";
	}
	else
	{
		if(ppre==NULL)
		{
			if(list.head->flink==NULL)//deleting only node in list
			{
				list.head=NULL;
				list.rear=NULL;
			}
			else//deleting first node
			{
				list.head->flink->blink=NULL;
				list.head=list.head->flink;
			}
		}
		else
		{
			if(ppre->flink->flink == NULL)//deleting last node
			{
				ppre->flink=NULL;
				list.rear=ppre;
			}
			else
			{
				ppre->flink->flink->blink=ppre;
				ppre->flink=ppre->flink->flink;
			}
		}
		list.count-=1;
		cout<<"List count is "<<list.count<<endl;
	}
}
void sort()
{
	node *i,*j;
	for(i=NULL;i!=list.head->flink;i=j)
	{
		for(j=list.head;j->flink!=i;j=j->flink)
		{
			if(j->data<=j->flink->data)
			{
				swap(j->data,j->flink->data);
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
		ploc=ploc->flink;
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
