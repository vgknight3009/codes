#include<bits/stdc++.h>
#define mx 260
using namespace std;

int a[mx][mx];
int n,m,c;

bool issafe(int i,int j){
	return (i>=0 && j>=0 && i<n && j<m && a[i][j]==1 ) ;
	
}

void DFS(int k,int l){
	
	c++;
	a[k][l]=0;
	int row[4]={-1,0,0,1};
	int col[4]={0,-1,1,0} ;
	
	for(int i=0;i<4;i++){
		
		if(issafe(k+row[i],l+col[i]))
			DFS(k+row[i],l+col[i]) ;
		
	}
	
}

int main(){
	
	cin>>n>>m;
	while(n && m){
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				cin>>a[i][j] ;
		}
		map<int,int> mp;
		int ctr=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				
				c=0;
				if(a[i][j])
				{
					ctr++;
					DFS(i,j);
					mp[c]++;	
				}
				
			}
			
		}
		cout<<ctr<<"\n";
		for(map<int,int>::iterator itr=mp.begin();itr!=mp.end();++itr)
			cout<<itr->first<<" "<<itr->second<<"\n";
		
		cin>>n>>m;
	}
	
	
	return 0;
}
