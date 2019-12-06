#include<iostream>
#include<conio.h>

using namespace std;

//not need to give them ZERO as a value
int ac=0; //array counter
int a[100]={0}; //output (prime divisors)

void outA(int e)
{
    for(int i=0;i<e;i++)
        cout<<a[i]<<"\t";
}

int main()
{
cout<<"Printing Divisors\nEnter n: ";
    int n=0;
    cin>>n;

    int i;
    for(i=1;i<=n;++i)
    {
        if(0==(n%i))
        {
            a[ac]=i;
            ac++;
        }
    }
    if(2==ac && n>1)
        cout<<"Here it is! Your Prime number!"<<endl;
    outA(ac);

cout<<"\ncount: "<<ac<<endl;
getch();
    return 0;
}
