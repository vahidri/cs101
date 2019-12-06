#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

#define file "sheet.txt"

struct lesson
{
	string name;
	float mark;
	float weight;
};

int main()
{
 cout<<"###Report Sheet"<<endl;
	vector<lesson> sheet;
	lesson tmp;
	cout<<"Enter Lesson Count: ";
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cout<<"Enter Data for Lesson No. "<<sheet.size()+1<<endl;
		cout<<"Name: ";
		cin>>tmp.name;
		cout<<"Mark: ";
		cin>>tmp.mark;
		cout<<"Weight: ";
		cin>>tmp.weight;
		
		cout<<endl;
		sheet.push_back(tmp);
	}

double ave=0;
double total_weight=0; //syllabus_count
ofstream ofs;
ofs.open(file,ofstream::out);
cout<<"No.\tLesson\tMark\tWeight\M*W"<<endl;
ofs<<"No.\tLesson\tMark\tWeight\M*W"<<endl;
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
