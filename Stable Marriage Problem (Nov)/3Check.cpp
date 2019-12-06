//SMP Checker
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
int n;

	int m[Max_Size+1][Max_Size+1]={0};
	int f[Max_Size+1][Max_Size+1]={0};

int mfind(int inp,int row); //Male
int ffind(int inp,int row); //Female

int main()
{
{
	cout<<"###SMP Answer Checker\nReads List of Preferences from \""<<file_list<<"\" and Writes the answer to \""<<file_ans<<"\"\n";
	int i,j,k;
//reading n (size)
	ifstream ifs;
	ifs.open(file_ans , ifstream::in);
	ifs>>n;
///initializing Vectors
	for(i=0;i<=n;i++) //v[0] is not used
	{
		vm.push_back(0);
		vf.push_back(0);
	}

//reading D Answer
	cout<<"Size: "<<n<<endl;
	
	int r=0;
	for(i=1;i<=n;i++)
	{
		ifs>>r;
		vm[i]=r;
		vf[r]=i;
	}	
	
	ifs.close();

//reading list
	ifs.open(file_list , ifstream::in);
	ifs>>r;
	if(r!=n) { cout<<"Conflict in Size: List != Ans"<<endl; return 10; }
	
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


//printing D Answer
	cout<<"Suggested Answer:\n";
	for(i=1;i<=n;i++)
		cout<<vm[i]<<" ";
	cout<<"\b\n";
	
	cout<<"\nMeans:\n";
	for(i=1;i<=n;i++)
		cout<<"M"<<i<< "[opt "<<mfind(vm[i] , i)<<"]" <<" - F"<<vm[i]<< "[opt "<<ffind(i,vm[i])<<"]"<<endl;
}

//check
	cout<<"\n\nChecking for possible Objections...\n";
short int obj_count=0;
for(int man_i=1;man_i<=n;man_i++) //i -> man
{
	int wp=mfind(vm[man_i],man_i);  //the place of man_i's pair, in his priority
	if(1==wp)
	{
		//then, there won't be any objections(since the man has gotten his first option)
	}
	else
	{
		for(int man_i_opt=1;man_i_opt<wp;man_i_opt++) //j -> m[i]["j"]: choices before the Pair of m[i][]
		{
			int man_i_cpair=m[man_i][man_i_opt];
			if( ffind(man_i , man_i_cpair)  <  ffind(vf[man_i_cpair] , man_i_cpair) )
			{
				cout<<"M"<<man_i<<", Opt["<<man_i_opt<<"]  <-->  F"<<man_i_cpair <<", Opt["<<ffind(man_i , man_i_cpair)<<"]"<<  endl;
				++obj_count;
			}
		}
	}
		
}
	
	cout<<endl;
	if(0==obj_count)
		cout<<"Good, You've the Answer";
	else
		cout<<"Oh oh! There "<<(1==obj_count ? "is only " : "are ")<<obj_count;

	cout<<endl;
//checking is done!
	return 0;
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

