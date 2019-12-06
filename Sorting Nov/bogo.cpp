#include<iostream>
#include<vector>
#include<time.h>
#include<stdlib.h>
using namespace std;

int isInOrder(int [],int);
void shuffle(int [],int);
unsigned long fact(int);

vector<int> v;

int main()
{
	int deck[]={2,5,6,10,9};
	int n=sizeof(deck)/sizeof(int);
srand(time(NULL));
	for(int i=0;i<n;i++)
		v.push_back(i);

	unsigned long c=0;
 	
	while(0==isInOrder(deck,n))
	{
    	shuffle(deck,n);
		c++;
	}
	cout<<"Count: "<<c<<"\n\n";
	
	for(int i=0;i<n;i++)
		cout<<deck[i]<<" ";
	cout<<"\b\n"<<endl;
	return 0;
}

int isInOrder(int a[],int n)
{
	for(int i=0;i<n-1;i++)
		if(a[i]>a[i+1])
			return 0;
	return 1;
}

unsigned long fact(int n)
{
	unsigned long f=1;
	for(long i=2;i<=n;i++)
		f*=i;
	return f;
}


void shuffle(int a[],int n)
{
	int k=rand()%fact(n);
//initial:
	for(int i=0;i<n;i++)
		v[i]=i;
//make	
	for(int i=0;i<k;i++)
		swap(v[i%n],v[(n==i%n+1 ? 0 : i%n+1)]);
	
	vector<int> tmp;
	
	for(int i=0;i<n;i++)
		tmp.push_back(a[v[i]]);
	for(int i=0;i<n;i++)
		a[i]=tmp[i];
}
