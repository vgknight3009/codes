#include<bits/stdc++.h>
#define mod 1000000007
#define max 10010
#define pb push_back
#define mp make_pair
#define pii pair<int,int>								// using rank with path compression
#define ll long long 									// O(km) ==O(mf(n))		m--> No f relations		,its better
using namespace std;

vector<pair<int,pii>  > g;
int n,e;
int rank[max];
int par[max];
int tree[max];


void make_set()
{
	for(int i=1;i<=n;i++)
	{
		par[i]=i;
		rank[i]=0;
	}
}

int find_set(int x)
{
	if(x==par[x])
	return x;
	else{
		int k= find_set(par[x]) ;
		par[x]=k;
		return k;
	}
}

void union_set(int x,int y)
{
	if(rank[x]>rank[y])
	par[y]=x;
	else
	{
		par[x]=y;
		if(rank[y]==rank[x])
		++rank[y] ;
		
	}
	
}

ll kruskal()
{
	make_set();
	ll mst=0;
	int u,v,x,y;
	for(int i=0;i<e;i++)
	{
		u=g[i].second.first;
		v=g[i].second.second;
		
		x=find_set(u);
		y=find_set(v);
		
		if(x!=y)
		{
			mst+=g[i].first;
			cout<<g[0].second.first<<" ==> "<<g[0].second.second<<" = "<<g[0].first<<endl;
			union_set(x,y) ;
			
		}
		
	}
	
	return mst;
}

int main()
{
	ios::sync_with_stdio(false);
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g.pb(mp(w,mp(u,v))) ;
        
    }
	sort(g.begin(),g.end());
	
	ll mst=kruskal();
	cout<<mst<<endl;
	
	
	return 0;
}
