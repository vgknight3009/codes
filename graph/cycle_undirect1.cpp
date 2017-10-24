#include<bits/stdc++.h>
#define pii pair<int,int>							// O(c*m)  m--> no of edges
#define mp make_pair
#define pb push_back								// ds using rank with path compression
using namespace std;
													// considering self loop as cycle
vector<pii> g;
int par[100];
int rank[100];
int n,m;

void init(){
	for(int i=0;i<=n;i++){
		par[i]=i;
		rank[i]=0;
	}
}

int find_set(int x){
	
	if(x==par[x])
		return x;
	else{
		int k=find_set(par[x]);
		par[x]=k;
		return k;
	}
}

void union_set(int x,int y){
	
	if(rank[x]>rank[y])
		par[y]=x;
	else{
		par[x]=y;
		if(rank[x]==rank[y])
			++rank[y];
	}
	
}

bool iscycle()
{
	init();
	int x,y,p,q;
	for(int i=0;i<m;i++){
		x=g[i].first;
		y=g[i].second;
		
		p = find_set(x);
		q = find_set(y) ;
		
		if(p==q)
			return true;
		else
			union_set(p,q) ;
		
	}
	return false;
}

int main(){
	
	cin>>n>>m ;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g.pb(mp(a,b)) ;					// undirected
		
	}
	iscycle()?cout<<"Cycle...\n":cout<<"Not Pre...\n" ;
	
	return 0;
}
