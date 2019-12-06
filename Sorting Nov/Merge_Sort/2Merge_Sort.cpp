//Vahid Ramazani
//940907
//Merge Sort (best, Ave, worst time is n*(log(n))

#include<iostream>
#include<fstream>
#include<time.h>
using namespace std;

#define file_in "input.txt"
#define file_out "m_sorted.txt"
	int n;
unsigned long T[5];

void sort(int [], int , int);	//inclusive range!
void merge(int [], int ,int);

int main()
{
	int i;
	cout<<"Merge Sort\nReading list from \""<<file_in<<"\" and writing the Sorted list to \""<<file_out<<"\" ."<<endl;
// reading input
T[0]=time(NULL);
	ifstream ifs;
	ifs.open(file_in,ifstream::in);
	ifs>>n;
	int* a=new int [n];
	for(i=0;i<n;i++)
		ifs>>a[i];
	ifs.close();

//Merge Sort, The Art!
T[1]=time(NULL);
sort(a,0,n-1);
T[2]=time(NULL);

//file out
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

void sort(int a[], int left, int right)
{
	if(left==right)
		return;
	else
	{
//		cout<<"sort: "; outy(a);
		sort(a , left, (right-left)/2+left);
		sort(a , (right-left)/2+left+1 , right);
		merge(a,left,right);
	}
}

void merge(int a[], int left, int right) //inclusive range!
{
	int pa=left,
		right_start=(right-left)/2+left+1,
		pb=right_start ,
		po=-1;
		
	int* o=new int [right-left+1]; //Tmp List	
//Writing to Tmp List (o)
	for(po=0 ;  po<=right-left && pa<right_start && pb<=right  ; po++)
	{
		if(a[pa]<a[pb])
		{
			o[po]=a[pa];
			++pa;
		}
		else
		{
			o[po]=a[pb];
			++pb;	
		}
	}
//checking the set that is finished
	if(pa<=right_start-1)
		for(pa;pa<=right_start-1;pa++)
		{
			o[po]=a[pa];
			po++;
		}
	if(pb<=right)
		for(pb;pb<=right;pb++)
		{
			o[po]=a[pb];
			po++;
		}

//writing to Main List
	for(po=left;po<=right;po++)
		a[po]=o[po-left];

//removing the Tmp List	
	delete [] o;
}
