#include<iostream>

// 940804, VR
// Hamming to normal

using namespace std;


int main()
{
    
    cout<<"Hamming Codeword to Normal[Error Detection](7bits to 4bits)\nEnter Normal binary code(enter -1 to Quit)\n";
int in=0;
int x[8]={0}; //x[0] as source!
int c=0; //counter
    do{
         cin>>in;
         
         if(-1==in) break;
         x[0]=in;
         c=1;
         while(c<=7)
         {
            x[c]=in%10;
            in/=10;
            c++;
         }
         

         //cus of array, it gets shifted by -1 (x[0] <=> x1)
         
         //err detection(assuming there may be only one err, no more) [if not, omitting "else"s before "if"s will do]
         if(x[1]!=(x[3]+x[5]+x[7])%2) cout<<"err in 1st!";
         else if(x[2]!=(x[3]+x[6]+x[7])%2) cout<<"err in 2nd!";
         else if(x[4]!=(x[5]+x[6]+x[7])%2) cout<<"err in 4th! (3rd check bit)";
         else cout<<"Normal: "<<x[7]<<x[6]<<x[5]<<x[3];

         cout<<endl<<endl;
         
    }while(1);
return 0;   
}

