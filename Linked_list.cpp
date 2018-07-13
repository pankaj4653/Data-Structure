#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;
typedef long long int ll;


struct node {
				int data;
				node* next;
};

node *head=NULL;


node* getnode(int x)
{
	node* temp=new node();

	temp->data=x;
	temp->next=NULL;

	return temp;
}


void insertf(int x)
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

void insertb(int x)
{
	node* temp=head;

	if(head==NULL)
		head=getnode(x);
	else
	{
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
		temp->next=getnode(x);
	}
}

int size()
{
	node* temp=head;
	int num=0;
	while(temp!=NULL)
	{
		num++;
		temp=temp->next;
	}
	return num;
}


void del(int n)
{
	node* temp1;
	node* temp=head;
	if(size() < n)
	{
		cout<<"Invalid Position"<<endl;
		return;
	}
	else if(n==1)
	{
		
		temp1=temp;
		temp=temp->next;
		head=temp;
	}
	else
	{
		for(int i=0;i<n-2;i++)
		{
			temp=temp->next;
		}
		temp1=temp->next;
		temp->next=temp1->next;
	}
	delete temp1;
	temp1=NULL;
}

void insert(int x,int n)
{
	node* temp=head;
	node* temp1;
	if(size()+1 < n)
	{
		cout<<"Invalid Position"<<endl;
		return;
	}
	else if(n==1)
	{
		if(head==NULL)
			head=getnode(x);
		else
		{
			temp1=getnode(x);
			temp1->next=head;
			head=temp;
		}
	}
	else
	{
		for(int i=0;i<n-2;i++)
		{
			temp=temp->next;
		}
		temp1=getnode(x);
		temp1->next=temp->next;
		temp->next=temp1;
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

void reverse_loop()
{
	node* temp=head;
	node* temp1;
	node* prev=NULL;

	while(temp!=NULL)
	{
		temp1=temp->next;
		temp->next=prev;
		prev=temp;
		temp=temp1;
	}
	head=prev;
}

void reverse_rec(node* temp,node* prev)
{
	if(temp==NULL)
		{
			head=prev;
			return;
		}
	reverse_rec(temp->next,temp);
	temp->next=prev;
}



void rec_display(node* temp)
{
	if(temp==NULL)
		return;

	cout<<temp->data<<" ";
	rec_display(temp->next);
}





void rec_display2(node* temp)
{
		if(temp==NULL)
			return;

		rec_display2(temp->next);
		cout<<temp->data<<" ";
}

int main()
{
	int x,data,n;

	for(;;)
	{
		
		cout<<endl<<"1. To insert at front"<<endl;
		cout<<"2. To insert at back "<<endl;
		cout<<"3. To insert at any position"<<endl;
		cout<<"4. To Know the Size of the List"<<endl;
		cout<<"5. To Delete element at any position"<<endl;
		cout<<"6. To Display the elements in the list"<<endl;
		cout<<"7. To Reverse the elements using loop"<<endl;
		cout<<"8. To Reverse the elements using recursion"<<endl;
		cout<<"9. To Diplay the elements using recursion, forward"<<endl;
		cout<<"10. To Display the elements using recursion, backward"<<endl;
		cout<<"Enter any other number to terminate"<<endl;

		cin>>n;

		switch(n)
		{
			case 1:
			cout<<"Enter the element"<<endl;
			cin>>x;
			insertf(x);
			break;

			case 2:
			cout<<"Enter the element"<<endl;
			cin>>x;
			insertb(x);
			break;

			case 3:
			cout<<"Enter the element and the position"<<endl;
			cin>>data>>x;
			insert(data,x);
			break;

			case 4:
			cout<<"The size of the List : "<<size()<<endl;
			break;

			case 5:
			cout<<"Enter the position"<<endl;
			cin>>x;
			del(x);
			break;

			case 6:
			cout<<"Elements in the list : ";
			display();
			break;

			case 7:
			reverse_loop();
			break;

			case 8:
			reverse_rec(head,NULL);
			break;

			case 9:
			cout<<"The elements in forward : ";
			rec_display(head);
			break;

			case 10:
			cout<<"The elements in backward : ";
			rec_display2(head);
			break;

			default:
			exit(0);
		}

	}
return 0;

}





