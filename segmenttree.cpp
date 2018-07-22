#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

typedef long long int ll;
using namespace std;



int query(int ql,int qh,int low,int high,int seg[],int pos);
void segment(int arr[],int seg[],int low,int high,int pos);

int main()
{
	


	int n;
	cout<<"Enter the number of elements in the array"<<endl;
	cin>>n;

	int arr[n];
	int seg[10001]={0};

	cout<<"Enter the elements in the array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	segment(arr,seg,0,n-1,0);

	cout<<"The segment array "<<endl;

	for(int i=0;i<50;i++)
		cout<<seg[i]<<" ";

	int l,r;
	
	int t;
	cout<<"Enter t"<<endl;
	cin>>t;

	while(t--)
	{
	cout<<"Enter the range"<<endl;
	cin>>l>>r;
	cout<<"Min : "<<query(l-1,r-1,0,n-1,seg,0);
	}
	
	return 0;

}


void segment(int arr[],int seg[],int low,int high,int pos)
{
	if(low==high)
		{
			seg[pos]=arr[low];
			return;
		}

	int mid=(low+high)/2;

	segment(arr,seg,low,mid,(2*pos+1));
	segment(arr,seg,mid+1,high,(2*pos+2));

	seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
	return;

}


int query(int ql,int qh,int low,int high,int seg[],int pos)
{
	
	if(ql<=low && qh>=high)
	{
		return seg[pos];
	}

	if(ql>high || qh<low)
		return INT_MAX;

	int mid=(low+high)/2;

		return min(query(ql,qh,low,mid,seg,(2*pos+1)),query(ql,qh,mid+1,high,seg,(2*pos+2)));
}