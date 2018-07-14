#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;
typedef long long int ll;

struct node {
				int data;
				node *next;
};


struct node* head=NULL;


node* getnode(int x)
{
	node* temp=new node();
	temp->data=x;
	temp->next=NULL;
	return temp;
}


void insert(int x)
{
	node* temp=getnode(x);
	if(head==NULL)
		head=temp;
	else
	{
		temp->next=head;
		head=temp;
	}
}


void display()
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}


void reverse_stack()
{
	stack<node*> s;
	node* temp=head;

	while(temp!=NULL)
	{
		s.push(temp);
		temp=temp->next;
	}

	head=s.top();
	temp=s.top();
	s.pop();
	while(!s.empty())
	{
		temp->next=s.top();
		temp=s.top();
		s.pop();
	}
	temp->next=NULL;
}

int main()
{
	int n,x;

	cout<<"Enter the number of elements in the list"<<endl;
	cin>>n;
	cout<<"Enter the elements"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		insert(x);
	}
	cout<<endl<<"The elements in list : "<<endl;
	display();

	// calling reverse using stack

	reverse_stack();

	cout<<endl<<"The elements after reverse call : "<<endl;
	display();
	cout<<endl;

return 0;
}

