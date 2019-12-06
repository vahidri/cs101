#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
#define file_in "mm.txt"

void mult(int **orig, int **inp,int n);
void outy(int **inp, int n);

int main()
{
	int n;
	ifstream ifs;
	ifs.open(file_in, ifstream::in);
	ifs>>n;
	cout<<n<<endl;
	int i,j;
	int ** inp=new int*[n];
	int ** orig=new int*[n];
	for(i=0;i<n;i++)
	{
		inp[i]=new int[n];
		orig[i]=new int[n];
		for(j=0;j<n;j++){
			ifs>>inp[i][j];
			orig[i][j]=inp[i][j];
		}
	}
	ifs.close();
	
	cout<<"#1:\n";
	outy(inp,n);
	cout<<endl;

	for(int k=2;k<=n;k++)
	{
		mult(orig , inp , n);
		cout<<"#"<<k<<":\n";
		outy(inp,n);
		cout<<endl;
		getch();
	}
	
	return 0;
}

void outy(int **inp, int n)
{
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			cout<<inp[i][j]<<" ";
		cout<<endl;
	}
}

void mult(int **orig, int **inp,int n)
{
	int i,j,k;
	int ** tmp=new int*[n];
	for(i=0;i<n;i++)
	{
		tmp[i]=new int[n];
		for(j=0;j<n;j++){
			tmp[i][j]=0;
			for(k=0;k<n;k++)
				tmp[i][j]+= orig[i][k] * inp[k][j];
		}
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			inp[i][j]=tmp[i][j];
		delete [] tmp[i];
	}
	delete [] tmp;
}

