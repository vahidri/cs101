#include<iostream>
#include<math.h>

using namespace std;

//940804
//VR

bool IsPrime(unsigned int n);

int main()
{
    unsigned int i,j;
    short int a[10]={0};
//a[0] reserved for SUM of them ALL

cout<<" _______________________________________________________________________\n";
cout<<"|\t\t\tPercent\t\tCount\t    % in All\tALL\t|\n";
cout<<"|_______________________________________________________________________|\n";

    for(i=1;i<=6;i++){
                       for(j=pow(10,i-1);j<pow(10,i);j++){
                                                          if(0==IsPrime(j)){
                                                                            a[i]++;
                                                                            ///cout<<j<<" ";
                                                          }
                       }
                       //cout<<endl;
                       a[0]+=a[i];
                       cout<<"|Primes with "<<i<<" digits:\t"<<a[i]/(9*pow(10,i-1))*100<<"%\t"<<a[i]<<"\t|   "<<a[0]/(pow(10,i)-1)*100<<"\t"<<a[0]<<"\t|"<<endl;
                       ///system("pause");
    }
cout<<"|_______________________________________________________________________|\n";
cout<<endl;
system("pause");
return 0;   
}

bool IsPrime(unsigned int n)
{
 bool flag=0;
 unsigned int i=2;
 if(n<2) return -1;
     while(0==flag && i<=pow(n,0.5))
     {
      if(0==n%i)
                flag=1;
      i++;
     }
     return flag;
}
