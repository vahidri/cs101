//SMP Matcher (Male Optimal)
//940827
// Vahid Ramazani
// 94222035
#define Max_Size 20

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

#define file_ans "ans.txt"
#define file_list "list.txt"

vector<int> vm;
vector<int> vf;
vector<int> vopt;
int n;
	int m[Max_Size+1][Max_Size+1]={0};
	int f[Max_Size+1][Max_Size+1]={0};

int vfind(int,vector<int>);  //v for vector
int mfind(int inp,int row); //Male
int ffind(int inp,int row); //Female

int main()
{
	cout<<"###SMP Matcher\nReads from \""<<file_list<<"\" and Writes the (minimalistic) Answer to \""<<file_ans<<"\"\n\n";
	int i,j,k;
//reading n (size)
	ifstream ifs;

//reading list
	ifs.open(file_list , ifstream::in);
	ifs>>n;
	//males
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			ifs>>m[i][j];
		}
	}
	
	//females
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			ifs>>f[i][j];
		}
	}
	ifs.close();

///initializing Vectors
	for(i=0;i<=n;i++) //v[0] is not used
	{
		vm.push_back(0);
		vf.push_back(0);
		vopt.push_back(1);
	}
	
while(-1!=vfind(0,vm))
{
	int thisman=vfind(0,vm);
	int nhl=vopt[thisman]; //nTh of His List
	int hco=m[thisman][nhl]; //His Current Option
	if(  0==vf[hco]  ) //if the prefered woman No. opt (haven't tried her yet!) of thisman is single, then mingle!
	{
		vm[thisman]=hco;
		vf[hco]=thisman;
	}
	else
	{
		if(ffind(thisman,hco) < ffind(vf[hco] , hco) )
		{
			++vopt[vf[hco]];
			vm[vf[hco]]=0;
			vm[thisman]=hco;
			vf[hco]=thisman;		
		}
		else
		{
			++vopt[thisman];
		}
	}
	
}

//NOTE: m[i][vopt[i]]==vm[i]

cout<<"The Male Optimal Answer is:"<<endl;
	ofstream ofs;
	ofs.open(file_ans , ofstream::out);
ofs<<n<<endl;	
	for(int i=1;i<=n;i++)
	{
		cout<<"M"<<i<<"[opt "<<vopt[i]<<"] - F"<<vm[i]<<"[opt "<<ffind(i,vm[i])<<"]"<<endl;	
		ofs<<vm[i]<<(i<n?" ":"");
	}
	ofs<<endl;
	ofs.close();
	return 0;
}


int vfind(int inp, vector<int> k)
{	
//k.size()==n+1
	for(int i=1;i<=n;i++)
		if(inp==k[i])
			return i;
	return -1;
}

int ffind(int inp,int row)
{	
	for(int i=1;i<=n;i++)
		if(inp==f[row][i])
			return i;
	return -1;
}

int mfind(int inp,int row)
{	
	for(int i=1;i<=n;i++)
		if(inp==m[row][i])
			return i;
	return -1;
}

