#include<bits/stdc++.h>
#define mod 1000000007
#define max 100010
#define ll unsigned long long 
#define pb push_back
#define mp make_pair
#define pii pair<int ,int>
using namespace std;


void F(string s,int l,int r){
	
	if(l==r)
		cout<<s<<"\n";
		
	else{
		for(int i=l;i<=r;i++){
		
		swap(s[l],s[i]);
		F(s,l+1,r);
		swap(s[l],s[i]);
		
	}
	}
	
	
}

int main(){
	
	string str;
	cin>>str;
	
	int l=str.length();
	
	F(str,0,l-1);

	return 0;
}
