//940906 FRI
//Running a test!

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	cout<<"Decimal to Binary\nEnter Your decimal no.: ";
	long long dec;
	cin>>dec;
	
	vector<short int> bin;
	cout<<dec<<" in bin:\n";
	while(dec>0)
	{
		bin.push_back(dec%2);
		dec/=2;
	}
	
	for(int x=bin.size()-1;x>=0;x--)
		cout<<bin[x];
	cout<<endl;
	
	return 0;
}