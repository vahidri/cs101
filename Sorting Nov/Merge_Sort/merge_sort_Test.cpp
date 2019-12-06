#include<iostream>
using namespace std;

	int n=7;

void sort(int [], int , int);	//inclusive range!
void merge(int [], int ,int);

void outy(int []);

unsigned long fact(int n);
void perm(int st); //STate


int main()
{
//variables
	
cout<<"Enter n to Test the merge sort for 1-n: ";
cin>>n;
	int* a=new int [n];

unsigned long f=fact(n);
for(int k=0;k<f;k++)
{
	for(int i=0;i<n;i++)
		a[i]=i+1;
	for(int i=0;i<k;i++)
		swap(a[i%n],a[(n==i%n+1 ? 0 : i%n+1)]);
	cout<<k+1<<": ";
	outy(a);
	sort(a,0,n-1);
	cout<<"  =>  ";
	outy(a);
	cout<<endl;
}
	cout<<endl;
	
		
	return 0;
}

void outy(int a[])
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\b";
}

void sort(int a[], int left, int right)
{
//	cout<<endl<<"#Sort left: "<<left<<"  right: "<<right<<endl;
	if(left==right)
		return;
	else
	{
//		cout<<"sort: "; outy(a);
		sort(a , left, (right-left)/2+left);
		sort(a , (right-left)/2+left+1 , right);
		merge(a,left,right);
	}
}

void merge(int a[], int left, int right) //inclusive range!
{
	int pa=left,
		right_start=(right-left)/2+left+1,
		pb=right_start ,
		po=-1;
		
	int* o=new int [right-left+1];
	
//	cout<<endl<<"#Merge left: "<<left<<"  right: "<<right<<endl;
	
	
	for(po=0 ;  po<=right-left && pa<right_start && pb<=right  ; po++)
	{
//		cout<<pa<<','<<pb<<endl;
		if(a[pa]<a[pb])
		{
			o[po]=a[pa];
			++pa;
		}
		else
		{
			o[po]=a[pb];
			++pb;	
		}
		
//		cout<<"a in M for:("<<pa<<" | "<<pb<<") "; outy(a);
//		cout<<"o in M for: "; outy(o);
	}

	if(pa<=right_start-1)
		for(pa;pa<=right_start-1;pa++)
		{
			o[po]=a[pa];
			po++;
		}
	
	if(pb<=right)
		for(pb;pb<=right;pb++)
		{
			o[po]=a[pb];
			po++;
		}

	for(po=left;po<=right;po++)
		a[po]=o[po-left];
	
//	cout<<"M_FIN: "; outy(a);
	delete [] o;
}


unsigned long fact(int n)
{
	unsigned long f=1;
	for(long i=2;i<=n;i++)
		f*=i;
	return f;
}

