// Calculating (almsot any) n Factiorial using Vector.
// 940821
// Vahid Ramazani

#include<iostream>
#include<fstream>
#include<vector>
#include<time.h>

using namespace std;

#define out_name "Fact.txt"

vector <unsigned int> a;
unsigned int dc[10];
unsigned long T[3];

void mp(unsigned int x); //MultiPly
void r10(); //Remainder 10
unsigned short int len(unsigned int in);

int main()
{
cout<<"Factorial Calculator\n";
cout<<"Enter n: (0 < n < 2^32)\n";
unsigned int n;
cin>>n;

cout<<"\nProcessing...";
T[0]=time(NULL);
///Start Processing
    unsigned int i=0;

	a.push_back(1);  //the first (1!)
    
	for(i=2;i<=n;i++)
    {
        mp(i);
        r10();
	}
	
///Finished Processing!
cout<<" .\nProcessing Finished!\nWriting to "<<out_name<<" ...";
T[1]=time(NULL);
///Start Writing to Fact.txt
ofstream ofs;
ofs.open(out_name , ofstream::out);

	for(unsigned int i=a.size()-1;i>0;i--)
    {
        ofs<<a[i];
        if(0==(i%3)) ofs<<",";
		++dc[a[i]];
	}
	//i is equal to 0 by now, and cuz it's UNSIGNED int, I can't do i--
	++dc[a[0]];
    ofs<<a[0]<<"\n\n";


	for(i=0;0==a[i];i++);  //counting the 0s in front(right side) of n!

ofs<<n<<"! has "<<a.size()<<" digits.\n";
ofs<<"There are "<<i<<" zeros in front(right side) of it!\n";
	
	ofs<<"\nCount of:\n";
	ofs<<"0: "<<dc[0]<<"  (total zeros)\n";
	for(i=1;i<10;i++)
		ofs<<i<<": "<<dc[i]<<endl;
	ofs<<endl;
ofs.close();

///Finished File Writing
T[2]=time(NULL);
cout<<" .\nDone.\n\n#Summary:\n";

for(unsigned int i=a.size()-1;i>0;i--)
		++dc[a[i]];
	//i is equal to 0 by now, and cuz it's UNSIGNED int, I can't do i--
	++dc[a[0]];

	for(i=0;0==a[i];i++);  //counting the 0s in front(right side) of n!

cout<<n<<"! has "<<a.size()<<" digits.\n";
cout<<"There are "<<i<<" zeros in front(right side) of it!\n";
	
	cout<<"\nCount of:\n";
	cout<<"0: "<<dc[0]<<"  (total zeros)\n";
	for(i=1;i<10;i++)
		cout<<i<<": "<<dc[i]<<endl;
	cout<<endl;

	
	cout<<"\n#Operation:\n";
	cout<<"Processing Took:\t"<<T[1]-T[0]<<" s\n";
	cout<<"Writing to file Took:\t"<<T[2]-T[1]<<" s\n";
	cout<<"Sum(Running Time):\t"<<T[2]-T[0]<<" s\n";
	
	cout<<"\nResult available at "<<out_name<<"\n";

	cout<<"\nGood, huh?\nVR";
	cout<<endl;

 
ofs.open(out_name, ofstream::app);

	ofs<<"Processing Took:\t"<<T[1]-T[0]<<" s\n";
	ofs<<"Writing to file Took:\t"<<T[2]-T[1]<<" s\n";
	ofs<<"Sum(Running Time):\t"<<T[2]-T[0]<<" s\n";
	ofs<<"\nGood, huh?\nVR";
	ofs<<endl;
ofs.close();
return 0;
}

void r10()
{
	//from 0 to p-1
	int i;
	for(i=0;i<a.size()-1;i++)
	{
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	
	//the last number(it's not a digit yet!)

	unsigned int p=a.size()-1;
	unsigned short int to_be_added_to_p=len(a[p])-1;
	
	
	for(i=0;i<to_be_added_to_p;i++)
	{
		a.push_back(a[p+i]/10);
		a[p+i]%=10;
	}
	
	p+=to_be_added_to_p;
}

unsigned short int len(unsigned int in)
{
	int out;
	for(out=0;in>0;out++)
		in/=10;
	return out;
}

void mp(unsigned int x)
{
        for(int j=0;j<a.size();j++)
            a[j]*=x;
}

