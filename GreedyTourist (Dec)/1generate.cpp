#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;

#define file_out "matrix.txt"
int main()
{
	cout<<"###Symmetric Positive Integer Matrix Generator\nOutput file: " << file_out <<"\nEnter n to Get the rnd n x n Matrix: ";
	int n;
	cin>>n;
	cout<<"Enter min(non-negative): ";
	unsigned int min,max;
	cin>>min;
	cout<<"Enter Max(Positive): ";
	cin>>max;
	if(min==max){ //a default state
		min=0;
		max=9;
	}
	int i,j;
	srand(time(0));
	int ** ar=new int*[n];
	for(i=0;i<n;i++)
	{
		ar[i]=new int[n];
		for(j=0;j<n;j++)
			ar[i][j]=0;
	}
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			ar[i][j]=rand()%(max-min+1)+min;
			ar[j][i]=ar[i][j];
		}
	}
	
	ofstream ofs;
	ofs.open(file_out, ofstream::out);
	ofs<<n<<endl;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			ofs<<ar[i][j]<<(j<n-1 ? " " : "");
		ofs<<endl;
	}
	ofs.close();
	cout<<"Done"<<endl;
	return 0;
}

