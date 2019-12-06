//940923
// Dec -> Bin
// Just Output, no Memory usage!
//VR

#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	cout<<"Decimal to Binary\nEnter Your decimal no.: ";
	unsigned long long dec;
	cin>>dec;
	int l=log(dec)/log(2) ,
		i;
	cout<<l+1<<" digits in binary\n\n";
	for(i=l;i>-1;--i) cout<<i%10;
	cout<<endl;
	while(dec>0)
	{
		for(i=0;i<l;i++) cout<<" ";
		cout<<dec%2<<"\r";
		dec/=2;
		l--;
	}
	cout<<endl;
	return 0;
}

