//List Generator(SMP)
//940823
// Vahid Ramazani
// 94222035

#include<iostream>
#include<fstream>
#include<vector>
#include<time.h>
#include<stdlib.h>
using namespace std;

void v0(int);
int vfind(int);

#define file_out "list.txt"
int n;
vector<int> v;

int main()
{
cout<<"List generator\nWrites a Random list of Preference to \""<<file_out<<"\"\nEnter n(the count of Men=Women): ";
cin>>n;
	
	int i,j;
	for(i=0;i<n;i++)	v.push_back(0); 
	int r=-2;
	
	srand(time(NULL));
	
	ofstream ofs;
	ofs.open(file_out, ofstream::out);
	ofs<<n<<endl;
	for(int k=1;k<=2;k++)
	{
		for (i=0;i<n;i++)
		{
			v0(n);
			for(j=0;j<n;j++)
			{
				r=(rand()%n)+1;
				while(-1!=vfind(r))
					r=(rand()%n)+1;
				v[j]=r;
				cout<<r<<" ";
				ofs<<r<<(j<n-1?" ":"");
			}
			cout<<"\b"<<endl;
			ofs<<endl;
		}
		cout<<endl;
		ofs<<(1==k?"\n":"");
	}
	
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

void v0(int n)
{
	for(int i=0;i<n;i++)
		v[i]=0;
}

