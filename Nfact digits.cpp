#include<iostream>
#include<math.h>
using namespace std;
int flr(double in);

int main()
{
	cout<<"Calc d min K that K! has N digits\nEnter N: ";
	int n;
	cin>>n;
	double l=0;
	int i=1;
	for(i=1;flr(l)<n;i++)
	    l+= log10(i);
	cout<<--i<<endl;
	return 0;
}

int flr(double in)
{
	int k=(int)(in);
	if(in==k)
		return k;
	else
		return k+1;
}