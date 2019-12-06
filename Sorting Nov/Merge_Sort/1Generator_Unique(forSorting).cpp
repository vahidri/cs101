#include<iostream>
#include<fstream>
#include<vector>
#include<time.h>
#include<stdlib.h>
using namespace std;

int vfind(int);

#define file_out "input.txt"

unsigned int n;
vector<int> v;

int main()
{
cout<<"Random List Generator(Unique)\nOutput will be stored in \""<<file_out<<"\" (before Printing here!)\nEnter count: ";
cin>>n;
	cout<<"Enter range: a b ";
int a,b;
cin>>a>>b;
	int j; 
	int r=-2;
	srand(time(0));
	
	for(j=0;j<n;j++)
		v.push_back(0); 

	ofstream ofs;
	ofs.open(file_out, ofstream::out);
	ofs<<n<<endl;

	for(j=0;j<n;j++)
	{
		r=rand()%(b-a+1)+a;
		while(-1!=vfind(r))
			r=rand()%(b-a+1)+a;
		v[j]=r;
		ofs<<r<<(j<n-1?" ":"");
	}
	ofs<<endl;
	
	ofs.close();	
	return 0;
}

int vfind(int inp)
{
	for(int i=0;i<n;i++)
		if(inp==v[i])
			return i;
	return -1;
}

