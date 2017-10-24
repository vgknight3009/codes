#include<bits/stdc++.h>
using namespace std;			// if more testcases then try to CLEAR the vector  ==> important

vector<int> g[100];
bool visited[100] ;
int dist[1000];

int main()
{
	int n,m,a,b;
	cin>>n>>m;
//	g = vector<int> (n) ;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;							// if a is indexed from 0
		g[a].push_back(b) ;
		g[b].push_back(a) ;
	}
	
	memset(visited,0,sizeof visited) ;
	memset(dist,-1,sizeof dist) ;

	dist[0] = 0 ;		// considering 0 as source
	visited[0] = 1;
	
	queue<int> bfsq;
	bfsq.push(0);
	
	while(!bfsq.empty())
	{
		int u=bfsq.front() ;
		bfsq.pop();
		for(int i=0;i<g[u].size();++i)
		{
			int v=g[u][i];
			if(!visited[v])
			{
				visited[v]=true;
				dist[v]=dist[u]+1 ;
				bfsq.push(v);
				
			}
			
		}
		
	}
	
	for(int i=0;i<n;i++)
	cout<<dist[i]<<"  ";
	
	
	return 0;	
}
