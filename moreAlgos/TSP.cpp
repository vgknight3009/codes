 #include<bits/stdc++.h>
using namespace std;

int g[21][21] ;
int n,e;

void init()
{
	for(int i=0;i<21;i++){
		for(int j=0;j<21;j++)
		{
			if(i==j)
				g[i][j]=0;
			else
				g[i][j]=INT_MAX;
		}
	}
	
}

int TSP(int pos,int bitmask){
	
	if(bitmask==(1<<n)-1)
		return g[pos][0] ;
	int ans=INT_MAX;
	
	for(int nxt=0;nxt<n;nxt++){
		if(bitmask & (1<<nxt))	continue;
		ans = min(ans , g[pos][nxt]+TSP(nxt,bitmask|(1<<nxt))) ;
		
	}
	return ans;
	
}

int main()
{
	init();
	
	cin>>n>>e;
	
	for(int i=0;i<e;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u][v]=w ;
		g[v][u]=w;
	}
	
	cout<<TSP(0,1);
	
	
	return 0;
}
