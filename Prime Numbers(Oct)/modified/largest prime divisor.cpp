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
	unsigned long long n,i;
	cout<<"Calc the Largest Prime Factor of N\nEnter N: ";
	//cin>>n;
	n=600851475143;
	//775,146.09922452683397274485982169
	i=powl(n,0.5);
	cout<<"Starting from "<<i<<endl;
for(;i>1;i--)
	if(0==IsPrime(i) && 0==n%i)
		break;
cout<<(1==i ? n : i)<<endl;
    return 0;
}
