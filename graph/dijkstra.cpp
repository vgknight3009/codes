#include<bits/stdc++.h>
#define max 10000
#define dmax 10000			// for memset range upto this		

using namespace std;

typedef pair<int,int> pii ;
vector<pii> g[max] ;
int d[max] ;

void dijkstra(int start)
{
	int i,c ;
	
	priority_queue< pii,vector< pii >,greater<pii> > q ; 		// min priority queue
	
	for(int i=0;i<max;i++)
	d[i]=dmax ;
	
	
	q.push(make_pair(0,start)) ;			// weight,vertex , so sorting will be done according to weight 
	d[start] = 0;
	
	while(!q.empty())
	{
		int u = q.top().second ;
		c = q.top().first ;
		q.pop() ;
		
		if(d[u]<c)	continue ;								// Imp , it optimises the soln
		
		for(i=0;i<g[u].size();i++)
		{
			int v=g[u][i].first ;
			int w=g[u][i].second ;
			
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				q.push(pii(d[v],v)) ;     // sort by weight
			}
		}	
	}
}


int main()
{
	int t,u,v,w,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		
		for(int i=1;i<=n;i++)	g[i].clear() ;
		
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v>>w;
			
			g[u].push_back(pii(v,w)) ;			// for directed graph
		}
		int start;
		
		cin>>start;
		dijkstra(start) ;
		
		cout<<d[3]<<endl;
		
		
		
	}
	
	return 0;
}
