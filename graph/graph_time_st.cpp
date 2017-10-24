#include<bits/stdc++.h>
#define mod 1000000007
#define max 100010			// to get topo-sort ==> just sort them acc to finish time(decresingly)  or
#define ll unsigned long long 				// store them in stack scc to finsih time
#define pb push_back
#define mp make_pair
#define pii pair<int ,int>
using namespace std;

vector<vector<int> >g;
vector<int> visit;
int time_d[100]={0};
int time_f[100]={0};

int time_ct=0;
int n,m;

void dfs(int s)
{
    visit[s]=1;
    time_ct++;
    time_d[s]=time_ct;       // discovery time
    for(vector<int>::iterator itr=g[s].begin();itr!=g[s].end();++itr)
    {
        if(!visit[*itr])
        dfs(*itr) ;
    }
    time_ct++;
    time_f[s]=time_ct ;
    
}

int main()
{
    	cin>>n>>m ;
		g = vector<vector<int> > (n+1) ;
		for(int i=0;i<m;++i)
		{
			int v,e;
			cin>>v>>e;
			g[v].push_back(e) ;
			
		}
		visit=vector<int> (n+1,0);
		for(int i=1;i<=n;i++)
		{
		    if(!visit[i])
		    dfs(i) ;
		    
		}
		for(int i=1;i<=n;i++)
		cout<<time_d[i]<<"  "<<time_f[i]<<endl;
		
    
    return 0;
}
