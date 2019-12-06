#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	cout<<"Calc Log(n!)\nEnter n: ";
	unsigned int n;
	cin>>n;
	double l=0;
	for (unsigned int i=1;i<=n;i++)
	    l+= log10(i);
	cout<<l<<endl;
	return 0;
}