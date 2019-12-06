//94/10/06
//Vahid Ramazani
// an Easier way for loop detection

//the last assignment: Greedy Implementation of Tourist Tree
#include<iostream>
#include<fstream>
using namespace std;

#define file_in "matrix.txt"
#define M_Max 1000 //MAX cost of a single road (2 reasons:: 1st: the tourist might not want to take the trip if it costs too much;
                                                //2nd: determining min of the remaining)

int* parted; //storing the already parted vertices. [used at party() ]
int n; //size

void look(int &m, int &Va, int &Vb, int** w, short int **out); //pick up the remaining road with min cost

void party(short int **ajc_mat); //determine the output (graph <=> adjacency matrix)'s partition count
	void parted_replace(int fnd, int rep);

int cvc(short int ** ajc_mat);

void wy(int ** out);
void outy(short int ** out);

int main()
{
cout<<"###Greedy Tourist\nInput file: " << file_in <<endl; //Spot Crossing
	int i,j;

int Cost=0;
	ifstream ifs;
	ifs.open(file_in, ifstream::in);
	ifs>>n;
cout<<"n: "<<n<<endl;

//initialization
	parted=new int[n];
	int ** w=new int*[n]; //map, and costs
	short int ** out=new short int*[n]; //output(adjacency Matrix)
	for(i=0;i<n;i++)
	{
		out[i]=new short int[n];
		w[i]=new int[n];
		for(j=0;j<n;j++){
			out[i][j]=0;  //initializing output (0 means no edge)
			ifs>>w[i][j]; //reading map
		}
	}
//	cout<<"Input has been Read.\n";
	cout<<"Input:\n";
wy(w);	
cout<<endl;

	int m, //min
		Va, //Vertex a
		Vb; //Vertex b
	
	int q=0;
cout<<"The Process:\n";
	while(q!=n-1) //steps(till it becomes a tree)
	{
		m=M_Max;
		look(m, Va, Vb, w, out);  //find the min of remaining edges
		party(out);
		
		if(parted[Va]==parted[Vb])
		{
			cout<<"("<<Va<<","<<Vb<<") could cause a loop"<<endl;
			out[Va][Vb] = -1;
			out[Vb][Va] = -1;
		}
		else
		{
		//Add that Edge!
		++q; 
		out[Va][Vb]=1;
		out[Vb][Va]=1;
		Cost+=m;
		
		///Step by Step View:
		cout<<"p="<<cvc(out)<<" | "<<"q="<<q<<"   +("<<  Va<<","<<Vb<<")   Price: "<<m<< endl;
		}
	}

cout<<"Done."<<endl<<endl;

cout<<"Thru:\n";
outy(out);
cout<<endl;
cout<<"#min Cost: "<<Cost<<endl;

return 0;
}

void look(int &m, int &Va, int &Vb, int** w, short int **out)
{
	Va=-1;
	Vb=-1;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(0!=out[i][j]) continue;
			if(w[i][j] < m && 0!=w[i][j]) 
			{
				m=w[i][j];
				Va=i;
				Vb=j;
			}
		}
	}
}

void wy(int ** out)
{
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			cout<<out[i][j]<<" ";
		cout<<endl;
	}
}

void outy(short int ** out)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(1==out[i][j])
				cout<<"("<<i<<","<<j<<")"<<endl;
}

int cvc(short int ** ajc_mat)
{
	int i,j;
	int c=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			if( 0!=ajc_mat[i][j] )
				break;
		if(j<n) c++;
	}
	return c;
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
	for(v=0;v<n;v++)
		parted[v]=-1;

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

