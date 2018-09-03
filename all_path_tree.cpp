#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long int ll;




struct node {
				int data;
				node* left;
				node* right;
};

void allpath(node* root,vector<int> &vec);

void inorder(node* root);

node* getnode(int x)
{
	node* temp=new node;
	temp->data=x;
	temp->left=temp->right=NULL;
	return temp;
}

node* insert(node* root,int x)
{
	if(root==NULL)
	{
		root=getnode(x);
	}
	else if(root->data >= x)
	{
		root->left=insert(root->left,x);
	}
	else 
		root->right=insert(root->right,x);


	return root;
}


int main()
{
	node* root=NULL;

	int n,x;
	cout<<"Enter n"<<endl;
	cin>>n;
	cout<<"Enter the data"<<endl;

	for(int i=0;i<n;i++)
	{
		cin>>x;
		root=insert(root,x);
	}

	inorder(root);

	vector<int> vec;

	allpath(root,vec);

	return 0;
}

void inorder(node* root)
{
	if(root==NULL)
		return;

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}


void allpath(node* root,vector<int> &vec)
{
	if(root==NULL)
		return;

	vec.push_back(root->data);

	if(root->right==NULL && root->left==NULL)
	{
		cout<<endl;
		for(int i=0;i<vec.size();i++)
		{
			cout<<vec[i]<<" ";
		}
		vec.pop_back();
		return;
	}

	allpath(root->left,vec);
	allpath(root->right,vec);

	vec.pop_back();
}








