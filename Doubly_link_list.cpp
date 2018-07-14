#include<iostream>
#include<vector>
#include<array>

using namespace std;
typedef long long int ll;


struct node {

		node* prev;
		int data;
		node* next;
};

struct node* getnode(int x)
{
	struct node* temp=new node();
	temp->data=x;
	temp->prev=NULL;
	temp->next=NULL;

	return temp;
}
void insert(int x);
void display();
void bdisplay();

struct node* head=NULL;
int main()
{

int n,x;
cout<<"Enter the number of nodes"<<endl;
cin>>n;

for(int i=0;i<n;i++)
{
	cin>>x;
	insert(x);
}
cout<<"forward display"<<endl;
display();

cout<<"Backward display"<<endl;

bdisplay();

return 0;
}


void insert(int x)
{
	struct node* temp=getnode(x);

	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		temp->next=head;
		head->prev=temp;
		head=temp;
	}
}

void display()
{
	struct node* temp=head;

	while(temp!=NULL)
	{
		cout<<temp->data<<"  ";
		temp=temp->next;
	}
}

void bdisplay()
{
	struct node*  temp=head;

	while(temp->next!=NULL)
	{
		temp=temp->next;
	}

	while(temp!=NULL)
	{
		cout<<temp->data<<"  ";
		temp=temp->prev;
	}
}


