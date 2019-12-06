#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

#define file_in "sheet_in.txt"
#define file_out "sheet_out.txt"

struct lesson
{
	string name;
	float mark;
	float weight;
};

int main()
{
 cout<<"###Report Sheet\nReading From \""<<file_in<<"\" and Writing To \""<<file_out<<"\""<<endl;
	vector<lesson> sheet;
	lesson tmp;
int n;
ifstream ifs;
ifs.open(file_in,ofstream::in);
	ifs>>n;
	
	for(int i=0;i<n;i++)
	{
		//cout<<"Enter Data for Lesson No. "<<sheet.size()+1<<endl;
        //cout<<"Name: ";
		ifs>>tmp.name;
		//cout<<"Mark: ";
		ifs>>tmp.mark;
		//cout<<"Weight: ";
		ifs>>tmp.weight;
		
		//cout<<endl;
		sheet.push_back(tmp);
	}

double ave=0;
double total_weight=0; //syllabus_count
ofstream ofs;
ofs.open(file_out,ofstream::out);
cout<<"No.\tLesson\tMark\tWeight\tM*W"<<endl;
ofs<<"No.\tLesson\tMark\tWeight\tM*W"<<endl;
	for(int i=0;i<n;i++)
	{
		ave+=sheet[i].mark * sheet[i].weight;
		total_weight+=sheet[i].weight;
		
		cout<<i+1<<"\t"<<sheet[i].name<<"\t"<<sheet[i].mark<<"\t"<<sheet[i].weight<<"\t"<<sheet[i].mark * sheet[i].weight<<endl;
		ofs<<i+1<<"\t"<<sheet[i].name<<"\t"<<sheet[i].mark<<"\t"<<sheet[i].weight<<"\t"<<sheet[i].mark * sheet[i].weight<<endl;
    }
	ave/=total_weight;
    ofs<<endl<<"Average: "<<ave<<endl;
	cout<<endl<<"Average: "<<ave<<endl;
	
	ofs.close();
	return 0;
}
