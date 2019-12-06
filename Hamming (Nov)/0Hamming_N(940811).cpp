// Hamming CodeWord Generator
// Vahid Ramazani
// 94/08/11

// Took a precious hour! ;-D

#include "iostream"
#include "math.h"

using namespace std;

short int a[100]={0};

long long bin(int);
int checklen(int);
int nth(long,int);
int len(long);
void vshow(int);
void normalplace(long,int,int,int);
void checkcalc(long,int,int,int);

int main()
{
	int in_len;
	long inp;
	
	int cbc=0; //Check Bits Count
	int out_len=0; //output length
	
	cout<<"Normal to Hamming CodeWord\nEnter your input's length: ";
	cin>>in_len;

	cbc=checklen(in_len);
	out_len=cbc+in_len;
	
	cout<<"Enter the msg(output would have "<<out_len<<" digits["<<cbc<<" check bits])\n\n";
	cin>>inp;

	normalplace(inp,in_len,cbc,out_len);
	checkcalc(inp,in_len,cbc,out_len);
	
	cout<<"\nYour Hamming Code Word:\n";	
	vshow(out_len);

	return 0;
}


long long bin(int n)
{
	long out=0;
	long p=1;
	while(n>0)
	{
		out+=(n%2)*p;
		p*=10;
		n/=2;
	}
	return out;
}

int checklen(int m)
{
	int r=0;
	while((m+r+1)>pow(2,r))
		r++;
	return r;
}

int nth(long n,int k)
{
	return (n/ int(pow(10,k-1) )%10);
}

int len(long n)   //assuming n>0
{
	int i=0;
	while(n>0)
	{
		n/=10;
		i++;
	}
	return i;
}

void vshow(int n)
{
	for(int i=n;i>=1;i--)
		cout<<a[i];
	cout<<endl;
}

void normalplace(long in,int inl, int cbc,int outl)
{
	int i=0;
	int pind=inl; //Pointing INput Digit
	for(i=outl;i>=1;i--)
	{
		if(i==pow(2,cbc-1))
		{
			cbc--;
		}
		else
		{
			a[i]=nth(in,pind);
			--pind;
		}
	}
}
void checkcalc(long in,int inl, int cbc,int outl)
{
	int i=0,j=0,place=0;
	
	for(i=cbc;i>=1;i--)
	{
		place=pow(2,i-1);
		
		
		for(j=outl;j>=1;j--)
		{
			if(j!=place)
			{
				if(1==nth( bin(j) ,i))
					a[place]+=a[j];
			}
			
		}
	
		a[place]%=2;
		
	}
}

