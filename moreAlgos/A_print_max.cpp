#include <bits/stdc++.h>
using namespace std;

int memo[1000];

void init(){
    memset(memo,-1,1000);
}

int F(int n){
    
    if(n<=6)
        return n;
    int mx=INT_MIN/2;
    if(memo[n]!=-1)
        return memo[n];
    for(int i=n;i>=3;i--){
        
        mx = max( mx, F(i-3)*(n-i+2)) ;
        
    }
    memo[n]=mx;
    return mx;
}

int main() {
	
	int t;
	cin>>t;
	while(t--){
	    init();
	    int n;
	    cin>>n;
	    
	    cout<<F(n)<<"\n";
	    
	}
	
	return 0;
}
