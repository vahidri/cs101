#include<iostream>

// 940804, VR
// Hamming to normal Error Corrected

using namespace std;


int main()
{
    
    cout<<"Hamming Codeword to Normal[Error Corrected!](7bits to 4bits)\nEnter Normal binary code(enter -1 to Quit)\n";
int in=0;
int x[8]={0}; //x[0] EC check!
int c=0; //counter
    do{
         cin>>in;
         
         if(-1==in) break;
         x[0]=0;
         c=1;
         while(c<=7)
         {
            x[c]=in%10;
            in/=10;
            c++;
         }
         

         //cus of array, it gets shifted by -1 (x[0] <=> x1)
         
         if(x[1]!=(x[3]+x[5]+x[7])%2) x[0]+=1;
         if(x[2]!=(x[3]+x[6]+x[7])%2) x[0]+=2;
         if(x[4]!=(x[5]+x[6]+x[7])%2) x[0]+=4;
         
         if(0==x[0])
                    cout<<"Normal: ";
         else{
              x[x[0]]+=1;
              x[x[0]]%=2;
             cout<<"ErrorCorrected("<<x[0]<<"): ";
             }
         cout<<x[7]<<x[6]<<x[5]<<x[3];

         cout<<endl<<endl;
       
     }while(1);
return 0;   
}

