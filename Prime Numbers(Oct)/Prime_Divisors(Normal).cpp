#include<iostream>
#include<conio.h>
using namespace std;

bool IsPrime(int n)
{
 bool flag=0;
 int i=2;
     while(0==flag && i<n)
     {
      if(0==n%i)
                flag=1;
      i++;
     }
     return flag;
}

int main()
{
int n;
    cin>>n;

    if(0==IsPrime(n)){
                      cout<<n<<" is Prime!"<<endl;
                      return 0;
                      }

int i=2;
    while(i<=n){
              if(0==n%i)
                 if(0==IsPrime(i)) cout<<i<<"\t";
              i++;
    }
cout<<endl;

getch();
    return 0;
}
