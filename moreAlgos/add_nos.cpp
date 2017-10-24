#include <bits/stdc++.h>
#define mx 26

using namespace std;
					// works for both neg n pos
int main(){
	
	int x,y;
	
	while(cin>>x>>y){
	
		int c=0;
		while(y){
			
			c=x&y;
			x=x^y;
			y=c<<1;
		}	
		cout<<x<<"\n";
	}
	
	
	return 0;
}
