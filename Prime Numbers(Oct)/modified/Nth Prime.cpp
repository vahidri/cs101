#include<iostream>
#include<math.h>
using namespace std;

bool IsPrime(int n)
{
 int i=2;
     while(i<=powl(n,0.5))
     {
      if(0==n%i)
                return 1;
      i++;
     }
     return 0;
}

int main()
{
	int pc=0;
	int n=0;
	cout<<"Calc Nth Prime No.\nEnter N: ";
	cin>>n;
	unsigned long long i;
for(i=2;pc<n;i++)
	if(0==IsPrime(i))
		pc++;
cout<<pc<<". "<<--i<<endl;
    return 0;
}
