#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;
typedef long long int ll;



struct node{
		node* left;
		int data;
		node* right;
};


node* getnode(int x)
{
	node* temp=new node();
	temp->data=x;
	temp->left=temp->right=NULL;
	return temp;
}


void inorder(node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

// inorder traversal of binary search tree gives sorted arrray

void preorder(node* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(node* root)
{
	if(root==NULL)
		return;

	preorder(root->left);
	preorder(root->right);
	cout<<root->data<<" ";
}

bool search(node *root,int x)
{
	if(root==NULL)
		return false;
	
	else if(x==root->data)
		return true;

	else if(x>root->data)
		return search(root->right,x);
	
	else if(x<root->data)
		return search(root->left,x);
}


int height(node* root)
{
	if(root==NULL)
		return -1;

	return (1+max(height(root->left),height(root->right)));
}

node* fmin(node* root)
{
	if(root->left==NULL)
		return root;

	return fmin(root->left);

}

node* del(node* root,int x);

node* fmax(node* root)
{
	if(root->right==NULL)
		return root;

	return fmax(root->right);
}

node* insert(node* root,int x)
{
	if(root==NULL)
	{
		root=getnode(x);
		
	}

	 else if(x<=root->data)
	 	root->left=insert(root->left,x);

	 else if(x>root->data)
	 	root->right=insert(root->right,x);


return root;
}
bool search2(node* root,int x);
void insert2(node** root,int x);
void levelorder(node* root);
void postorderi(node *root);
int size(node* temp);

int main()
{
	int n,x,k;
	struct node* root=NULL;


	for(;;)
	{
		cout<<endl;
		cout<<"Enter 1 to insert                    "<<endl;
		cout<<"Enter 2 to traverse in preorder      "<<endl;
		cout<<"Enter 3 to trsverse in inorder 		"<<endl;
		cout<<"Enter 4 to traverse in postorder 	"<<endl;
		cout<<"Enter 5 to search any element 		"<<endl;
		cout<<"Enter 6 to get the height of the tree"<<endl;
		cout<<"Enter 7 to get the max element  		"<<endl;
		cout<<"Enter 8 to get the min element  		"<<endl;
		cout<<"Enter 9 to delete any element  		"<<endl;
		cout<<"Enter 10 to use search               "<<endl;
		cout<<"Enter 11 to insert2 as a iterative approach"<<endl;
		cout<<"Enter 12 for level order traversal "<<endl;
		cout<<"Enter 13 for iterartive approach of postorder"<<endl;
		cout<<"Enter 14 to get the size of the tree"<<endl;
		cout<<"Enter any other element to terminate	"<<endl;

		cin>>k;

		switch(k)
		{
			case 1:
			cout<<"Enter the data"<<endl;
			cin>>x;
			root=insert(root,x);
			break;

			case 2:
			preorder(root);
			break;

			case 3:
			inorder(root);
			break;

			case 4:
			postorder(root);
			break;

			case 5:
			cout<<"Enter the data to be searched"<<endl;
			cin>>x;
			if(search(root,x))
				cout<<"Found"<<endl;
			else 
				cout<<"Not Found"<<endl;

			break;

			case 6:
			cout<<"Height of the tree : "<<height(root)<<endl;
			break;

			case 7:
			cout<<"Max element : "<<fmax(root)->data<<endl;
			break;

			case 8:
			cout<<"Min element : "<<fmin(root)->data<<endl;
			break;

			case 9:
			cout<<"Enter the element to delete "<<endl;
			cin>>x;
			root=del(root,x);
			break;

			case 10:
			cout<<"Enter the data to be searched"<<endl;
			cin>>x;
			if(search2(root,x))
				cout<<"Found"<<endl;
			else 
				cout<<"Not Found"<<endl;

			break;

			case 11:
			cout<<"Enter the data"<<endl;
			cin>>x;
			insert2(&root,x);
			break;

			case 12:
			cout<<"Level order Traversal"<<endl;
			levelorder(root);
			break;

			case 13:
			cout<<"Iterative approach of postorder"<<endl;
			postorderi(root);
			break;

			case 14:
			cout<<"Size of the tree : "<<size(root);
			break;
			default:
			exit(0);
		}

	}

return 0;

}



node* del(node* root,int x)
{
	if(root==NULL)
		return root;
	
	else if(x<root->data)
	root->left=del(root->left,x);
	
	else if(x>root->data)
	root->right=del(root->right,x);

	else 
	{
		if(root->left==NULL && root->right==NULL)
			{
				delete root;
				root=NULL;
			}
		else if(root->left==NULL && root->right!=NULL)
		{
			node* temp=root;
			root=root->right;
			delete temp;
			temp=NULL;
			
		}
		else if(root->left!=NULL && root->right==NULL)
		{
			node* temp=root;
			root=root->left;
			delete temp;
			temp=NULL;
			
		}
		else
		{
			node* temp=fmin(root->right);
			root->data=temp->data;
			root->right=del(root->right,temp->data);
		}
	}
	return root;
	
}


//search as a iterative approach

bool search2(node* root,int x)
{
	node* temp=root;

	

	while(1)
	{
		
		if(temp->data==x)
			return true;

		else if(temp->data>x)
			{
				temp=temp->left;
				if(temp==NULL)
				{
					return false;
				}
			}

		else
			{
				temp=temp->right;
				if(temp==NULL)
				{
					return false;
				}
			}

		

	}
}

//insert as iterative approach

void insert2(node** root,int x)
{
	
	node* temp=(*root);

	if((*root)==NULL)
		{
			(*root)=getnode(x);
		}


	else{

			while(1)
	{	
		

		 if(x>((temp)->data))
		{
			if((temp)->right==NULL)
				{
					(temp)->right=getnode(x);
					break;
				}

			else
				(temp)=(temp)->right;
		}

		else 
		{
			if((temp)->left==NULL)
				{
					(temp)->left=getnode(x);
					break;
				}
			else
				(temp)=(temp)->left;
		}
	}
	}
}


void levelorder(node* root)
{
	queue<node*> vec;

	node* temp;
	if(root!=NULL)
		vec.push(root);

	while(!vec.empty())
	{
		temp=vec.front();
		
		cout<<temp->data<<" ";
		vec.pop();


		if(temp->left!=NULL)
		{
			vec.push(temp->left);
		}

		if(temp->right!=NULL)
		{
			vec.push(temp->right);
		}
	}
}


// iterative approach of postorder ;
void postorderi(node *root)
{
	stack<node*> s1,s2;

	node* temp;

	if(root==NULL)
		return;

	s1.push(root);

	while(!s1.empty())
	{
		s2.push(s1.top());
		temp=s1.top();
		s1.pop();
		if(temp->left!=NULL)
			s1.push(temp->left);

		if(temp->right!=NULL)
			s1.push(temp->right);
	}

	while(!s2.empty())
	{
		temp=s2.top();
		cout<<temp->data<<" ";
		s2.pop();
	}

}


int size(node* temp)
{
	if (temp==NULL)
		return 0;
	else
		return 1+size(temp->left)+size(temp->right);
}

