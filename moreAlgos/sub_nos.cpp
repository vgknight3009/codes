#include <bits/stdc++.h>
#define mx 26

using namespace std;

int add(int x,int y){
		int c=0;
		while(y){
			
			c=x&y;
			x=x^y;
			y=c<<1;
		}	
	return x;
}


int main(){
	
	int x,y;
	
	while(cin>>x>>y){
		y=(~y);
		y=add(y,1);
	
		cout<<add(x,y)<<"\n";
	}
	
	
	return 0;
}
