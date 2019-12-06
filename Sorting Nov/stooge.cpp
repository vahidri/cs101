//Vahid Ramazani

#include<iostream>
using namespace std;


void stooge_sort(int [],int,int);

int main()
{
int a[]={3,49,-2,1,6};
int size=sizeof(a)/sizeof(int);

for(int i=0;i<size;i++)
	cout<<a[i]<<" ";
cout<<"\b\n";
	
	stooge_sort(a,0,size-1);

cout<<endl;
for(int i=0;i<size;i++)
	cout<<a[i]<<" ";
cout<<"\b\n";
	return 0;
}

void stooge_sort(int a[], int i, int j)
{
	if (a[j]<a[i])
		swap(a[j],a[i]);
	if ((j-i+1) > 2)
	{
		int t=(j-i+1)/3;
		stooge_sort(a,i,j-t);
        stooge_sort(a, i+t, j);
        stooge_sort(a, i, j-t);
	}
}
