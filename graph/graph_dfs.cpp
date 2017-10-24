#include<bits/stdc++.h>
#define mod  1000000007					// solution of FIRESC codechef
using namespace std;

vector<bool> visited;
vector<vector<int> > graph ;
int sizecc=0;

void dfs(int u)
{
	sizecc++;       				// to find size of connected components
	visited[u]=true ;
	
	for(vector<int>::iterator itr=graph[u].begin();itr!=graph[u].end();++itr)
	{
		if(!visited[*itr])
		dfs(*itr) ;
	}
	
}

int main()
{
	ios::sync_with_stdio(false) ;
	int t,n,m,v,e,i;
	cin>>t;
	while(t--)
	{
		cin>>n>>m ;
		graph = vector<vector<int> > (n) ;
		for(i=0;i<m;++i)
		{
			cin>>v>>e;
		//	v--; e-- ;
			graph[v].push_back(e) ;
			graph[e].push_back(v) ;
			
		}
		
		int ans=0;
		long long ways=1;
		visited = vector<bool> (n,0) ; 
		for(i=0;i<n;++i)
		{
			if(visited[i])
			continue;
			
			ans++;				// to find no of connected components 
			sizecc=0;
			
			dfs(i);
			
			ways = (long long)(ways*sizecc)%mod ;
			ways %= mod;
		}
		
		cout<<ans<<" "<<ways<<"\n" ;
	}
	
	
	
	
	return 0;
}
