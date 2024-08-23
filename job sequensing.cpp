#include<bits/stdc++.h>
using namespace std;

struct job
{
    int d;
    int p;
};

bool compare(job a,job b)
{
    return a.p>b.p;
}



int main()
{
    int n;//no of jobs
    cin>>n;
    vector<job>jobs(n);
    for(int i=0;i<n;i++)
    {
        cin>>jobs[i].p>>jobs[i].d;
    }
    sort(jobs.begin(),jobs.end(),compare);
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(jobs[i].d>max)
        max=jobs[i];
    }
    vector<int>duration(max,0);
    

}