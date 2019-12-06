#include<iostream>
#include<vector>
using namespace std;

#define file_out "out.txt"

void outy(int);
unsigned long fact(int);

vector<int> v;

int main()
{
	int n;
	cout<<"Showing Permutations of 1 to n\nEnter n: ";
	cin>>n;
	int i;
	unsigned long f=fact(n);
	
	
	for(i=0;i<n;i++)
		v.push_back(i+1);
	outy(n);
	for(i=0;i<f;i++)
	{
		cout<<i+1<<": ";
		outy(n);
		swap(v[i%n],v[(n==i%n+1 ? 0 : i%n+1)]);
	}
	return 0;
}

unsigned long fact(int n)
{
	unsigned long f=1;
	for(long i=2;i<=n;i++)
		f*=i;
	return f;
}

void outy(int n)
{
	for(int i=0;i<n;i++)
		cout<<v[i]<<" ";
	cout<<"\b"<<endl;
}
