#include<iostream>

// 940803, VR
// Normal to Hamming Codeword.

using namespace std;


int main()
{
    
    cout<<"Normal code to Hamming Codeword (4bits to 7bits)\nEnter Normal binary code(enter -1 to Quit)\n";
int in=0;
int x[8]={0}; //x[0] as counter!
    do{
         cin>>in;
         
         if(-1==in) break;
         
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
         cout<<"HammingCodeWord: ";
         
         for(x[0]=7;x[0]>=1;x[0]--)
            cout<<x[x[0]];
         cout<<endl<<endl;
         
    }while(1);
return 0;   
}

