#include<bits/stdc++.h>
#define mx 101								// O( 8*8*r*c )
#define mp make_pair
#define pii pair<int,int> 
using namespace std;

int R,C;

bool issafe(string g[],int r,int c){
	
	return (r>=0 && c>=0 && r<R && c<C && (g[r][c]=='.' || g[r][c]=='F')) ;
	
}

int find_dist(string str[],int r,int c){

	int dist[r][c];
	
	queue<pair<int,pii> > q;
	
	int x,y;
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			dist[i][j]=INT_MAX ;
			if(str[i][j]=='S')
			{
				dist[i][j]=0;
				q.push(mp(-1,mp(i,j))) ;
			}
			else if(str[i][j]=='F'){
				x=i;y=j;
			}
		}
	}

	int row[8]={-1,-1,-1,0,0,1,1,1} ;
	int col[8]={-1,0,1,-1,1,-1,0,1} ;
	
	pair<int,pii> p;
	while(!q.empty()){
		
		p=q.front();
		q.pop();
		
		for(int i=0;i<8;i++){
			
			int k=p.second.first+row[i];
			int l=p.second.second+col[i];
			
			if(issafe(str,k,l) && 
			dist[k][l]>=dist[p.second.first][p.second.second]+1)
			{
				int y = dist[p.second.first][p.second.second] + 1  ;
				if(p.first==i)
					dist[k][l]--;
				dist[k][l] = min(dist[k][l],y) ;
				q.push(mp(i,mp(k,l))) ;
 			}	
		}
		
		
	}
	
	return dist[x][y]==INT_MAX?-1:dist[x][y] ;
	
}


int main(){

	ios::sync_with_stdio(false);
	int m;
	cin>>m;
	while(m--){
		
		cin>>R>>C ;
		string str[R];
		
		for(int i=0;i<R;i++)
			cin>>str[i];
			
		cout<<find_dist(str,R,C)<<"\n";
	}
	
	return 0;
}
