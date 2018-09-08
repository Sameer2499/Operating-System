#include<bits/stdc++.h>
using namespace std;
struct sjf{
 int brust,prt,tat,wt;
 string pid;
};
vector <sjf> v;
void swap(int i,int j)
{
	int tb,tprt;string tpid;
	tb=v[i].brust;
	tpid=v[i].pid;
	tprt=v[i].prt;
	v[i].brust=v[j].brust;
	v[i].pid=v[j].pid;
	v[i].prt=v[j].prt;
	v[j].brust=tb;
	v[j].pid=tpid;
	v[j].prt=tprt;
}
void sort(int np)
{
	for(int i=0;i<np;i++)
	{
		for(int j=0;j<np;j++)
		{
			if(v[j].prt < v[j+1].prt)
			{
				swap(j,j+1);
			}
		}
	}
}
int main()
{
	cout<<" \t\t Program For Priority Scheduling.";
	cout<<"\n Number Of process:";
	int np;
	cin>>np;
	for(int i=0;i<np;i++)
	{
		int bt,prt;string pid;
		cin>>pid>>bt>>prt;
		v.push_back({bt,prt,0,0,pid});
	}
	sort(np);
	v[0].tat=v[0].brust;
	v[0].wt=0;
	for(int i=1;i<np;i++)
	{
		v[i].tat=v[i].brust+v[i-1].tat;
		v[i].wt=v[i].tat-v[i].brust;
	}
	cout<<"\nPid\tBT\tPrt\tTAT\tWT\n";
	int sumtat=0,sumwt=0;
	for(int i=0;i<np;i++)
	{   sumtat+=v[i].tat;
	    sumwt+=v[i].wt;
		cout<<v[i].pid<<"\t"<<v[i].brust<<"\t"<<v[i].prt<<"\t"<<v[i].tat<<"\t"<<v[i].wt<<endl;
	}
	cout<<"Average Tat:"<<sumtat/np;
	cout<<"\nAverage Wt:"<<sumwt/np;
	return 0;	
}
