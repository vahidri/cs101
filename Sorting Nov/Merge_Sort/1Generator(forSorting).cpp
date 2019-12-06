#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>

using namespace std;

#define file_gen "input.txt"

int main()
{
	cout<<"Random List Generator\nOutput will be stored in \""<<file_gen<<"\" (before Printing here!)\nEnter count: ";
	unsigned int n;
	int a,b;
	cin>>n;
	cout<<"Enter range: a b ";
	cin>>a>>b;	
	srand(time(0));
	ofstream ofs;
	ofs.open(file_gen,ofstream::out);
	ofs<<n<<endl;
	
	int i;
	if(a==b)
		for(i=0;i<n;i++)
			ofs<<rand()<<(i<n-1?" ":"\n");
	else
		for(i=0;i<n;i++)
			ofs<<rand()%(b-a+1)+a<<(i<n-1?" ":"\n");
	ofs.close();

/*	
	ifstream ifs;
	ifs.open(file_gen,ifstream::in);
	ifs>>n;
	int x;
	for(i=0;i<n;i++)
	{
		ifs>>x;
		cout<<x<<(i<n-1?" ":"\n");
	}
	ifs.close();
*/	
	return 0;
}
