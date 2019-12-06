#include<iostream>
#include<fstream>
#include<time.h>
using namespace std;

#define file_in "input.txt"
#define file_out "b_sorted.txt"
	int n;
unsigned long T[5];

void sort(int a[]);

int main()
{
	int i;
	cout<<"Bubble Sort\nReading list from \""<<file_in<<"\" and writing the Sorted list to \""<<file_out<<"\" ."<<endl;
cout<<"Reading input"<<endl;
T[0]=time(NULL);
	ifstream ifs;
	ifs.open(file_in,ifstream::in);
	ifs>>n;
cout<<"Data pieces count: "<<n<<endl;
	int* a=new int [n];
	for(i=0;i<n;i++)
		ifs>>a[i];
	ifs.close();

cout<<"Sorting..."<<endl;
T[1]=time(NULL);
sort(a);
T[2]=time(NULL);

cout<<"Writing Sorted Data to output"<<endl;
	ofstream ofs;
	ofs.open(file_out, ofstream::out);
	ofs<<n<<endl;
	for(i=0;i<n;i++)
		ofs<<a[i]<<(i<n-1?" ":"");
	ofs<<endl;
	ofs<<"\n\n";
	ofs<<"##Processing Time\n";
	ofs<<"reading Input took: "<<T[1]-T[0]<<"s\n";
	ofs<<"#Sorting took: "<<T[2]-T[1]<<"s\n";
T[3]=time(NULL);
	ofs<<"Writing to file took: "<<T[3]-T[2]<<"s\n";

//On SCR output
/*
cout<<"\nsize: "<<n<<endl;	
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\b"<<endl;
T[4]=time(NULL);
*/

	cout<<"\n\n";
	cout<<"##Processing Time\n";
	cout<<"reading Input took: "<<T[1]-T[0]<<"s\n";
	cout<<"#Sorting took: "<<T[2]-T[1]<<"s\n";
	cout<<"writing to file(output) took: "<<T[3]-T[2]<<"s\n";
//	cout<<"Printing output took: "<<T[4]-T[3]<<"s"<<endl;
//	ofs<<"Printing output took: "<<T[4]-T[3]<<"s"<<endl;
	cout<<"\nVR"<<endl;
	ofs<<"\nVR"<<endl;
	ofs.close();
	return 0;
}

void sort(int a [])
{
	int temp;
	int i,j;
	int swapCount =0;
	for(i=0;i<n;i++)
	{
		swapCount =0;
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]<a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				swapCount++;
			}
		}
		
		if (0==swapCount) 	return;
	}
}

