#include<bits/stdc++.h>
#define mod 1000000007
#define max 100010
#define ll unsigned long long 
#define pb push_back
#define mp make_pair
#define pii pair<int ,int>
using namespace std;

void F(string s,string r,int k,int n){
	
	if(k==n)
		cout<<r<<"\n";
	else{
		
		for(int i=0;i<n;i++)
			F(s,r+s[i],k+1,n) ;
		
	}
	
}


int main(){
	
	string str;
	cin>>str;
	
	int l=str.length();
	
	F(str,"",0,l);

	return 0;
}
