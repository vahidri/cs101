#include<iostream>
#include<math.h>

using namespace std;

int main()
{
//cout<<"Calculating Log(n!)\nEnter n: ";
int n;
//cin>>n;

    n=pow(10,7);

    double L=0;
    int i;

    for(i=1;i<=n;i++)
        L+=log10(i);
    cout<<"log("<<n<<"!)= "<<L<<"\n\nThat means "<<n<<"! has "<<ceil(L)<<" digits."<<endl;

return 0;
}
