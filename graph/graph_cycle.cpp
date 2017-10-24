#include<bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> g[100];
bool visit[100]={0};
bool rstack[100]={0} ;

bool dfs(int v)										// indexing frm 1
{
	if(visit[v]==false)
	{
		visit[v]=true;
		rstack[v]=true;
		for(int i=0;i<g[v].size();i++)
		{
			int u=g[v][i];
				if(rstack[u])
					return true;
				else if(!visit[u])
					return dfs(u);
		}
		
	}
	rstack[v] = false;
	return false;
}

bool is_cycle(int v)
{
	for(int i=1;i<=v;i++)
	{
		if(dfs(i))
			return true;
	}
	return false;
	
}

int main()
{
	int v,e;
	cin>>v>>e;
	for(int i=0;i<e;++i)
		{
			int a,b ;
			cin>>a>>b;
	
			g[a].push_back(b) ;
		//	graph[e].push_back(v) ;
			
		}
    
	
	if(is_cycle(v))
	cout<<"Cycle Present\n";
	else
	cout<<"Not Present";
	
	
	return 0;
}
