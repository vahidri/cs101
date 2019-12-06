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
    int a[100]={0}; //prime numbers
    int pc=0; //counter
    int i=0;
for(i=2;i<=541;i++){
            if(0==IsPrime(i)){
                 a[pc]=i;
                 pc++;
                 }
            }


int n;
    cin>>n;

    if(0==IsPrime(n)){
                      cout<<n<<" is Prime!"<<endl;
                      return 0;
                      }

i=0;
int c=0;
    while(a[i]<n){
              if(0==n%a[i]){
                            cout<<a[i]<<"\t";
                            c++;
                            }
              i++;
    }
cout<<endl;

getch();
    return 0;
}
