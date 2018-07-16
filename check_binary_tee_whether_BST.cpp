#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long int ll;

struct node{
			int data;
			node* left;
			node* right;
};


bool check_binary(node* root);
void inorder(node* root);

// this function allocates memory in heap and returns it's pointer

node* getnode(int x)
{
	node* temp=new node();
	temp->data=x;
	temp->left=temp->right=NULL;
	return temp;
}

// this funtion use to make a binary search tree

node* insert(node* root,int x)
{
	if(root==NULL)
	{
		root=getnode(x);
		return root;
	}

	if(root->data >= x)
		root->left=insert(root->left,x);

	else
		root->right=insert(root->right,x);

	return root;
}




int main()
{
	int n,x;
	node* root=NULL;
	// cout<<"Enter the number of nodes"<<endl;
	// cin>>n;

	// cout<<"Enter the elements "<<endl;           
	// for(int i=0;i<n;i++)
	// {
	// 	cin>>x;
	// 	root=insert(root,x);
	// }

	root=getnode(100);
	root->left=getnode(80);
	root->right=getnode(120);
	root->left->right=getnode(50);
	root->left->left=getnode(60);
	root->right->left=getnode(150);
	root->right->right=getnode(170);

	inorder(root);
	cout<<endl;
	cout<<"result"<<" : ";
	if(check_binary(root))
		cout<<"The tree is a binary tree"<<endl;
	else
		cout<<"The tree is not a binary tree"<<endl;

	return 0;
}


// function to check whether a binary tree is a binary search tree
// Time complexity : O(n)

bool check_binary(node* root)
{
	if(root==NULL)
		return true;

	return (root->left==NULL || root->left->data <= root->data)&&(root->right==NULL || root->right->data > root->data)&&check_binary(root->left)&&check_binary(root->right); 
}


// to traverse the tree

void inorder(node* root)
{
	if(root==NULL)
		return;

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}