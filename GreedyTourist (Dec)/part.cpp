#include<iostream>
#include<fstream>
using namespace std;
#define file_in "mm.txt"

int* parted; //storing the already parted vertices. [ party() ]
int n;

void outy(short int **inp);
void p_out();

void parted_replace(int fnd, int rep);
void party(short int **ajc_mat);
int parted_uniq_count(); //connotes the partition count of given graph

int mat_vertex_deg(short int** ajc_mat , int row);
bool detect_loop(short int** ajc_mat);

int main()
{
cout<<"###Graph Partition Counter\nReading the Adjacency Matrix from \""<<file_in<<"\"\n";
	ifstream ifs;
	ifs.open(file_in, ifstream::in);
	ifs>>n;
	cout<<"n: "<<n<<endl;
	int i,j;
	parted=new int[n];
	short int ** inp=new short int*[n];
	short int ** orig=new short int*[n];
	for(i=0;i<n;i++)
	{
		parted[i]=-1;
		inp[i]=new short int[n];
		orig[i]=new short int[n];
		for(j=0;j<n;j++){
			ifs>>inp[i][j];
			orig[i][j]=inp[i][j];
		}
	}
	ifs.close();

outy(inp);
cout<<endl;

	party(inp);
	cout<<"Partition Tops:\n";
	for(int i=0;i<n;i++)
		cout<<parted[i]<<" ";
	cout<<"\b\n\n";
	
	cout<<"Partition Count: "<<parted_uniq_count()<<endl;
	
	cout<<detect_loop(inp)<<endl;
	return 0;
}

void outy(short int **inp)
{
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			cout<<inp[i][j]<<" ";
		cout<<endl;
	}
}


int parted_uniq_count()
{
	int out=0;
	for(int fnd=0;fnd<n;fnd++)
		for(int i=0;i<n;i++)
			if(fnd==parted[i]){
				++out;
				break;
			}
	return out;
}

void parted_replace(int fnd, int rep)
{
	for(int i=0;i<n;i++)
		if(parted[i]==fnd)
			parted[i]=rep;
}

void party(short int **ajc_mat)
{
	int v, //the Vertexes
		to_v, //the other one, to see if there is an edge between them.
		vtop; //top Vertex 
	for(int i=0;i<n;i++)
		parted[i]=-1;
//checking Vertex by Vertex!
		//Level 1 connection for each one will do

	for(v=0;v<n;v++)
	{
		if(-1 == parted[v]) //this is a new vertex ( a new top )
		{
			parted[v]=v; //top of its group(temporarily)
			vtop=v;
		}
		else
			vtop=parted[v];
		
		for(to_v=v+1;to_v<n;to_v++)
			if(1==ajc_mat[v][to_v])
				if( -1 == parted[to_v] )
					parted[to_v]=vtop;
				else
					parted_replace(parted[to_v], vtop);
	}
}

int mat_vertex_deg(short int** ajc_mat , int row)
{
	int out=0;
	for(int i=0;i<n;i++)
		if( 1==ajc_mat[row][i])
			out++;
	return out;
}

void p_out()
{
	cout<<"Parted: ";
	for(int i=0;i<n;i++)
		cout<<parted[i]<<" ";
	cout<<endl;
}

bool detect_loop(short int** ajc_mat)
{
	int i,j;
	party(ajc_mat);
	
	///
	//p_out();
	
	for(i=0;i<n;i++)
	{
		if(-1==parted[i]) //been there!
			continue;
		else
		{
			int looking_for=parted[i];
			int q_of_this_part=0;
			int p_of_this_part=0;
			for(j=i;j<n;j++)
			{
				if( looking_for==parted[j] )
				{
					p_of_this_part++;
					q_of_this_part+=mat_vertex_deg(ajc_mat , j);
					parted[j] = -1;
				}
			}
			q_of_this_part/=2;
			if (q_of_this_part>=p_of_this_part)
				return 1; //loop in this partition
		}
	}
	return 0;
}

