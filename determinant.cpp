//941013 04:00 AM
#include<iostream>
#include<fstream>
using namespace std;

#define file_in "deting_matrix.txt"

int** mat_read(unsigned int&Size);
void outy(int** mat, unsigned int Size);

int ** mat_prim(int ** in, unsigned int Size, unsigned int om_i, unsigned int om_j);
int summa(int ** mat, unsigned int Size);
int det(int** mat, unsigned int Size);

int main()
{
cout<<"###Matrix Determinant\nReading input from \""<<file_in<<"\". The result will be printed on this screen\n"<<endl;
	unsigned int Size=0;
	int** mat=mat_read(Size);
cout<<"Size: "<<Size<<endl;
outy(mat,Size);
cout<<endl<<endl;
	cout<<"#det= "<<det(mat,Size)<<endl;
	return 0;
}

int** mat_read(unsigned int&Size)
{
	ifstream ifs;
	ifs.open(file_in, ifstream::in);
	ifs>>Size;
	int **o=new int*[Size];
	for(int i=0;i<Size;i++) o[i]=new int[Size];
	
	for(int i=0;i<Size;i++)
		for(int j=0;j<Size;j++)
			ifs>>o[i][j];
	
	return o;
}

void outy(int** mat, unsigned int Size)
{
	for(int i=0;i<Size;i++){
		for(int j=0;j<Size;j++)
			cout<<mat[i][j]<<"\t";
		cout<<endl;
	}
}

int ** mat_prim(int ** in, unsigned int Size, unsigned int om_i, unsigned int om_j)
{
	int** o=new int*[Size-1];
	for(int i=0;i<Size-1;i++)	o[i]=new int[Size-1];
	
	unsigned int r=0,c=0;
	for(int i=0;i<Size;i++)
		for(int j=0;j<Size;j++)
		{
			if(i==om_i || j==om_j) continue;
			o[r][c]=in[i][j];
			c++;
			if(c==Size-1)
			{
				c=0;
				++r;
			}
		}
	
	return o;
}

int summa(int ** mat, unsigned int Size)
{
	int o=0;
	int s=1;
	for(int i=0;i<Size;i++)
	{
		o+= s * mat[0][i]  * det(mat_prim(mat,Size, 0, i) , Size-1);
		s=-s;
	}
	return o;
}

int det(int **mat, unsigned int Size)
{
	if(2==Size)
		return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0] ;
	else
		return summa(mat,Size);
}

