#include<bits/stdc++.h>
using namespace std;

string F(string str,int l,int r,int n){
	
	while(l>=0 && r<n && str[l]==str[r]){
		l--;
		r++;
	}
	return str.substr(l+1,r-l-1);
	
}

int main(){
	
	string str;
	cin>>str;
	int l=str.length();
	
	string ans="",a,b;
	int k=0;
	for(int i=0;i<l;i++){
		
		a =F(str,i,i,l);
		if(a.length()>ans.length())
			ans=a;
		b = F(str,i,i+1,l);
		if(b.length()>ans.length())
			ans=b;
		//k = max(max(x,y),k);
		
	}
	cout<<ans;
	
	return 0;
}
