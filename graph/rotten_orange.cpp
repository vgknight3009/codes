#include<bits/stdc++.h>
#define mx 5
#define dmax 10000			// for memset range upto this		
#define mp make_pair
using namespace std;

typedef pair<int,int> pii;
											// O(m*n)
bool issafe(int g[][mx],int r,int c){
	
	return (r>=0 && c>=0 && r<4 && c<4 && g[r][c]==1) ;		// Checking those values for which u have to propagate further
	
}

bool check_arr(int g[][mx]){
	
	for(int i=0;i<4;i++){
		for(int j=0;j<mx;j++)
			if(g[i][j]==1)
				return true; 
	}
	return false;
}

int rotoranges(int g[][mx]){
	
	int row[4]={-1,0,0,1} ;
	int col[4]={0,-1,1,0} ;
	
	queue<pii> q;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++)
		{
			if(g[i][j]==2)
				q.push(mp(i,j)) ;
		}
	}
	
	int tim=0;
	q.push(mp(-1,-1)) ;					// delimiting char
	pii f;
	while(!q.empty()){
		
		bool flag=0;
		f=q.front();
		
		while(f.first!=-1){
			
			for(int i=0;i<4;i++){
			
				if(issafe(g,f.first+row[i],f.second+col[i]))
				{
					flag=1;
					q.push(mp(f.first+row[i],f.second+col[i]))  ;
					g[f.first+row[i]][f.second+col[i]] = 2;				// Assign a value such that u will not process it again
				}	
			
			}
			q.pop() ;
			f=q.front();
		
		}
	
		if(flag)
			tim++;
		q.pop();
		
		if(!q.empty()){
			q.push(mp(-1,-1)) ;
		}
		
	}
	
	return check_arr(g)?-1:tim;
	
}

int main(){

	int g[][mx]={{2,1,0,2,0},
				 {0,1,0,2,0},
				 {1,0,0,2,0},
				 {1,1,1,1,0}};
				 
	int ans=rotoranges(g);
	
	if(ans==-1)
		cout<<"Not Possible\n";
	else
		cout<<ans<<"\n";
	
	return 0;
	
}
			

