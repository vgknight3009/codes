#include<bits/stdc++.h>
#define mod  1000000007						// Kahn algo  		--->  O( V+E )
using namespace std;

vector<vector<int> > g ;
int n,m;

void topo_sort(){
	
	int indeg[n+1]={0} ;
	for(int i=1;i<=n;i++){
		for(vector<int>::iterator itr=g[i].begin();itr!=g[i].end();++itr)
			indeg[*itr]++;
	}
	
	queue<int> q;
	
	for(int i=1;i<=n;i++){
		if(!indeg[i])
			q.push(i) ;
	}
	int ctr=0;
	vector<int> topo ;
	
	while(!q.empty() ){
		
		int u=q.front() ;
		q.pop();
		topo.push_back(u) ;
		
		for(vector<int>::iterator itr=g[u].begin();itr!=g[u].end();++itr)
		{
			if(--indeg[*itr]==0)
				q.push(*itr) ;
			
		}
		
		ctr++ ;
	}
	
	if(ctr!=n)
		cout<<"Cycle Present\n";
	else{
		
		for(int i=0;i<n;i++)
			cout<<topo[i]<<"  ";
	}
	
}

int main()
{
	ios::sync_with_stdio(false) ;
	int t,v,e,i;
	cin>>t;
	while(t--)
	{
		cin>>n>>m ;
		g = vector<vector<int> > (n+1) ;
		for(i=0;i<m;++i)
		{
			cin>>v>>e;
			g[v].push_back(e) ;	
		}
		
		topo_sort() ;

	}
		
	return 0;
}
