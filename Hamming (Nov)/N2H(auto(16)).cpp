#include<iostream>

using namespace std;

int bin(int dec)
{
    int out=0;
    for(int i=1;i<=1000;i*=10){
            out+=i*(dec%2);
            dec/=2;

            }
return out;
}

int main()
{

int in=0;
int x[8]={0}; //x[0] as counter!

for(int i=0; i<16;i++){
         in=bin(i);
         cout<<in;
         x[7]=in/1000;
         in%=1000;
         x[6]=in/100;
         in%=100;
         x[5]=in/10;
         in%=10;
         x[3]=in; //in/1

         //cus of array, it gets shifted by -1 (x[0] <=> x1)
         x[1]=(x[3]+x[5]+x[7])%2;
         x[2]=(x[3]+x[6]+x[7])%2;
         x[4]=(x[5]+x[6]+x[7])%2;
         cout<<"\t Code:\t";

         for(x[0]=7;x[0]>=1;x[0]--)
            cout<<x[x[0]];
         cout<<endl<<endl;

    }

//system("pause");
return 0;
}

