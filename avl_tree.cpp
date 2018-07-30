#include<iostream>
#include<vector>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;
typedef long long int ll;


struct node{
		node* left;
		node* right;
		int data;
		int h;
};

node* getnode(int x)
{
	node* temp=new node();
	temp->left=temp->right=NULL;
	temp->h=0;
	temp->data=x;
	return temp;
}

int maX(node* root1,node* root2)
{
	if(root1==NULL && root2==NULL)
		return 0;
	else if(root1!=NULL && root2!=NULL)
		return max(root1->h,root2->h);
	else
		return root1==NULL?root2->h:root1->h;
}

node* rr(node* root)
{
	node* temp=root->left;
	root->left=temp->right;
	temp->right=root;
	temp->h=1+maX(temp->left,temp->right);
	root->h=1+maX(root->left,root->right);

	return temp;
}

node* rl(node* root)
{
	node* temp=root->right;
	root->right=temp->left;
	temp->left=root;
	root->h=1+maX(root->left,root->right);
	temp->h=1+maX(temp->left,temp->right);

	return temp;
}

void display(node* root);
int fun(node* root1,node* root2);

node* insert(node* root,int x)
{
	if(root==NULL)
	{
		root=getnode(x);
		return root;
	}
	else if(x<= root->data)
	{
		root->left=insert(root->left,x);
	}
	else
		root->right=insert(root->right,x);

	

	//root->h=1+maX(root->left,root->right);

	


	int b=fun(root->left,root->right);
	
	if(b>1)
	{
		if(fun(root->left->left,root->left->right)>=0)
		{
			return rr(root);
		}
		else
		{
			root->left=rl(root->left);
			return rr(root);
		}
	}
	if(b<-1)
	{
		if(fun(root->right->right,root->right->left)>=0)
		{
			return rl(root);
		}
		else
		{
			root->right=rr(root->right);
			return rl(root);
		}

	}
	root->h=1+maX(root->left,root->right);


	return root;
}

int main()
{
	int n,num,x;
	struct node* root=NULL;

	for(;;)
	{
		cout<<"1. Insert"<<endl;
		cout<<"2. Inorder"<<endl;
		cout<<"Enter any other element to quit"<<endl;

		cin>>n;
		switch(n)
		{
			case 1:
			cout<<"Enter the element"<<endl;
			cin>>x;
			root=insert(root,x);
			break;

			case 2:
			cout<<"element		"<<"	h"<<endl;
			display(root);
			break;

			default:
			exit(0);		
		}
	}

return 0;
}


void display(node* root)
{
	if(root==NULL)
		return;

	display(root->left);
	cout<<"	 "<<root->data<<"		"<<root->h<<endl;
	display(root->right);
}


int fun(node* root1,node* root2)
{
	if(root1==NULL && root2==NULL)
		return 0;
	else if(root1!=NULL && root2!=NULL)
		return (root1->h)-(root2->h);
	else
		return root1==NULL?0-(root2->h):root1->h;
}









