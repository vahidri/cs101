#include<iostream>
#include<conio.h>

using namespace std;

//not need to give them ZERO as a value
int ac=0; //array counter
int a[100]={0}; //output (prime divisors)


//left the repd function empty, and it'll become a normal divisor finder program
void repd() //delete repeated divisors
{
    int c=0;
    for(c=0;c<ac-1;c++)
    {
        if(0==(a[ac-1]%a[c]))
        {
            a[ac]=0;
            ac--;
        }
    }
}

void outA(int e)
{
    for(int i=0;i<e;i++)
        cout<<a[i]<<"\t";
    cout<<endl;
}

int main()
{
cout<<"(Edited) Sieve of Eratosthenes (1 to n)\nEnter n: ";
    int n=0;
    cin>>n;

    int i;
    for(i=2;i<=n;++i)
    {
/// omitted the condition(checking if its a divisor)

            a[ac]=i;
            ac++;
            if(ac>1) repd(); //more than one primes
   }

        outA(ac);
    cout<<"count: "<<ac<<endl;

getch();
    return 0;
}
