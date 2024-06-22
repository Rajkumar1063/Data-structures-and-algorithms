#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left;
	node *right;
	node(int val)
	{
		data=val;
		left=NULL;
		right=NULL;
	}
};
node* insert(node *root,int data)
{
	if(root==NULL)
		return new node(data);
	if(data<root->data)
		root->left=insert(root->left,data);
	else
		root->right=insert(root->right,data);
	return root;		
}
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
node* minnode(node *root)
{
	node *min=root;
	while(min->left!=NULL)
	{
		min=min->left;
	}
	return min;
}
node* deletebst(node *root,int dltkey)
{
	if(root==NULL)
		return root;
	if(dltkey<root->data)
			root->left=deletebst(root->left,dltkey);
	else if(dltkey>root->data)
			root->right=deletebst(root->right,dltkey);
	else
	{
		if(root->left==NULL && root->right==NULL)
			return NULL;
		else if(root->left==NULL)
			return root->right;
		else if(root->right==NULL)
			return root->left;
		else
		{
			node* temp=minnode(root->right);
			root->data=temp->data;
			root->right=deletebst(root->right,temp->data);
		}			
	}
	return root;
}
/*node* minnode(node *nd)
{
	node *min=nd;
	while(min->left!=NULL)
	{
		min=min->left;
	}
	return min;
}
node* deletebst(node *nd,int dltkey)
{
	if(nd==NULL)
	{
		return nd;
	}
	else
	{
		if(dltkey<nd->data)
		{
			nd->left=deletebst(nd->left,dltkey);
		}
		else if(dltkey>nd->data)
		{
			nd->right=deletebst(nd->right,dltkey);
		}
		else
		{
			if(nd->left==NULL && nd->right==NULL)
			{
				return NULL;
			}
			else if(nd->left==NULL)
			{
				node* temp=nd->right;
				return temp;
			}
			else if(nd->right==NULL)
			{
				node* temp=nd->left;
				return temp;
			}
			else
			{
				node* temp=minnode(nd->right);//min of right subtree
				nd->data=temp->data;
				nd->right=deletebst(nd->right,temp->data);
			}
	 	}
	}
	return nd;
}*/
int main()
{
	node *root=NULL;
	int j,element;
	cout<<"Enter element: ";
	cin>>element;
	root=insert(root,element);
	cout<<"Wish to continue?(0/1): ";
	cin>>j;
	while(j!=0)
	{
		cout<<"Enter element: ";
		cin>>element;
		insert(root,element);
		cout<<"Wish to continue?(0/1): ";
		cin>>j;
	}
	cout<<"Inorder traversal: ";
	inorder(root);
	cout<<endl;
	cout<<"Enter data to be deleted: ";
	cin>>element;
	deletebst(root,element);
	inorder(root);
	cout<<endl;
	return 0;
}
