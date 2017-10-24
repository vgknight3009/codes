#include<bits/stdc++.h>
#define pb push_back
using namespace std;			// topo sort only works for DAG

vector<vector<int> > g;
bool visited[100]={0} ;

stack<int> s;

void DFS(int u){
	
		visited[u]=1;
		vector<int>::iterator itr;
		for( itr=g[u].begin();itr!=g[u].end();++itr){
		
			if(!visited[*itr])
				DFS(*itr) ;
			
		}
		s.push(u) ;
	
}


int main(){
	
	int v,e;
	cin>>v>>e;

	g=vector<vector<int> > (v+1);
	for(int i=0;i<e;i++){
		int a,b;
		cin>>a>>b;
		g[a].pb(b);
	//	g[b].pb(a);
	}
	
	for(int i=1;i<=v;i++){
		if(!visited[i])
			DFS(i);
		
	}
	while(!s.empty()){
		cout<<s.top()<<"  ";
		s.pop();
	}
	
	return 0;
}
