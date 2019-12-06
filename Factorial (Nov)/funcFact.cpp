#include<iostream>

using namespace std;

unsigned int a[524288]; //512*1024 * 4Bytes= 2MB  => k=2 (MB)
const short int X=6;
int c; //place holder

void mp(int i)
{
        for(int j=0;j<=c;j++)
            a[j]*=i;
}

void c10()
{
        for(int j=0;j<=c+X;j++)
            if(10<=a[j])
            {
                a[j+1]+=a[j]/10;
                a[j]%=10;
            }
}

void cph()
{
        for(int j=c+X;j>=c;j--)
            if(a[j]>0)
            {
                c=j;
                j=c-1;
            }
}

int main()
{
cout<<"FUNCTIONAL Big Factorial Calculator\n";
cout<<"Enter n: ";
int n;
cin>>n;

//    n=12345;

    int i=0;
    int j;
a[0]=1;
    for(i=1;i<=n;i++)
    {
        mp(i);

        c10();
    //checking place holder
        cph();
    }

    for(int i=c;i>=0;i--){
        cout<<a[i];
        if(0==(i%3)) cout<<",";
}
    cout<<"\b \n\n";

cout<<n<<"! has "<<c+1<<" digits.\n";
return 0;
}
